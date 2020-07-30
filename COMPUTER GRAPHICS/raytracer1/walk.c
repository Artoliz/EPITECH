/*
** walk.c for walk in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 13:20:02 2017 Charles Descoust
** Last update Wed Apr  5 09:18:35 2017 Charles Descoust
*/

#include "inc/my.h"

float	what_k(t_my_object* obj, t_my_pos* basic, t_ptr_ft* tab)
{
  int	i;
  float	k_tmp;

  i = 0;
  while (i < 3)
    {
      if (my_strcmp(tab[i].name, obj->name) == 0)
	{
          basic->eye_pos = translate_inv(basic->eye_pos, obj->coord);
	  basic->eye_pos = rotate_xyz_inv(basic->eye_pos, obj->rotate);
	  basic->dir_vector = rotate_xyz_inv(basic->dir_vector, obj->rotate);
	  k_tmp = tab[i].ft(basic->eye_pos, basic->dir_vector, obj->radius);
	  basic->dir_vector = rotate_zyx(basic->dir_vector, obj->rotate);
	  basic->eye_pos = rotate_zyx(basic->eye_pos, obj->rotate);
          basic->eye_pos = translate(basic->eye_pos, obj->coord);
	  if (k_tmp > 0)
	    return (k_tmp);
	}
      i = i + 1;
    }
  return (-1.0f);
}

float	transit_plane(t_my_object* obj, t_my_pos basic, t_my_object** final)
{
  float	k_plane;
  float	k_final;

  basic.eye_pos.z = basic.eye_pos.z - obj->coord.z;
  k_plane = intersect_plane(basic.eye_pos, basic.dir_vector);
  (k_plane > 0) ? (k_plane) : (k_plane = 100.f);
  if (k_plane > 0)
    {
      k_final = k_plane;
      *final = obj;
    }
  else
    k_final = 100.f;
  return (k_final);
}

sfColor		what_color(t_my_object* obj, t_my_pos basic, t_ptr_ft* tab)
{
  float		k_tmp;
  t_my_object	*final;
  t_my_object	*save;

  save = obj;
  while (obj != NULL)
    {
      if (my_strcmp(obj->name, "PLANE") == 0)
	basic.k = transit_plane(obj, basic, &final);
      else
	{
	  k_tmp = what_k(obj, &basic, tab);
	  if (k_tmp > 0 && k_tmp < basic.k)
	    {
	      basic.k = k_tmp;
	      final = obj;
	    }
	}
      obj = obj->next;
    }
  if (basic.k == 100.f)
    return (sfBlack);
  basic.new_pos = calc(basic.eye_pos, basic.dir_vector, basic.k);
  return (calc_new_color(final, basic, save, tab));
}

void		run_time(t_my_win win)
{
  sfTexture_updateFromPixels(win.texture, win.buffer->pixels,
			     WIDTH, HEIGHT, 0, 0);
  sfRenderWindow_clear(win.window, sfBlack);
  sfRenderWindow_drawSprite(win.window, win.sprite, NULL);
  sfRenderWindow_display(win.window);
}

void		*pixels_walk(void *arg)
{
  t_my_win	*tmp;
  sfVector3f	dir_vector;
  t_ptr_ft	tab[] =
    {
      {"SPHERE", intersect_sphere},
      {"CONE", intersect_cone},
      {"CYLINDER", intersect_cylinder},
    };

  tmp = (t_my_win*)arg;
  while (tmp->var[tmp->idx].pos.x < tmp->var[tmp->idx].max.x)
    {
      tmp->var[tmp->idx].pos.y = tmp->var[tmp->idx].save;
      while (tmp->var[tmp->idx].pos.y < tmp->var[tmp->idx].max.y)
        {
	  dir_vector = calc_dir_vector(500.f, tmp->basic.screen_size,
                                       tmp->var[tmp->idx].pos);
          dir_vector = rotate_xyz_inv(dir_vector, tmp->basic.eye_rotate);
          tmp->basic.dir_vector = dir_vector;
          tmp->basic.k = 100.f;
          my_put_pixel(tmp->buffer, tmp->var[tmp->idx].pos.x, tmp->var[tmp->idx].pos.y,
                       what_color(tmp->obj, tmp->basic, tab));
          tmp->var[tmp->idx].pos.y += 1;
        }
      run_time(*tmp);
      tmp->var[tmp->idx].pos.x += 1;
    }
  pthread_exit(NULL);
}
