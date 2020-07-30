/*
** my_raytracer.c for  in /home/miklox/semestre1/infographie/bsraytracer1
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Mon Feb  6 18:34:36 2017 Bastien LECUSSAN
** Last update Sun May 28 18:53:06 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

void	init_var_eye_screen(sfVector2i *screen_size, sfVector3f *rotate,
			    t_my_struct *my_struct, t_frame *window)
{
  screen_size->x = S_WIDTH;
  screen_size->y = S_HEIGHT;
  rotate->x = ROTATION_SCENE_X;
  rotate->y = ROTATION_SCENE_Y;
  rotate->z = ROTATION_SCENE_Z;
  my_eye_pos(&my_struct->eye);
  window->light.x = my_struct->eye.x;
  if (MY_MACRO_LIGHT_X != 0)
    window->light.x = MY_MACRO_LIGHT_X;
  window->light.y = my_struct->eye.y;
  window->light.z = MY_MACRO_LIGHT_Z;
  get_new_size_obj(window->scene, &my_struct->eye);
}

int		my_raytracer(t_frame *window)
{
  sfVector2i	screen_size;
  int		count;
  int		count2;
  sfVector3f	rotate;
  t_my_struct   my_struct;
  t_smallest	dist;

  count = 0;
  init_var_eye_screen(&screen_size, &rotate, &my_struct, window);
  while (count < screen_size.y && (count2 = 0) == 0)
    {
      while (count2 < screen_size.x)
	{
	  my_screen_pos(&my_struct.pos, count, count2);
	  calc_dir_vector_obj(DIST, &screen_size, &my_struct.pos,
			      &my_struct.vector);
	  rotate_xyz_obj(&my_struct.vector, &rotate);
	  if (my_scene(&my_struct, window, &dist, window->save_face) == 84)
	    return (84);
	  count2 = count2 + 1;
	}
      window_refresh(window);
      count = count + 1;
    }
  return (0);
}

void	my_eye_pos(sfVector3f *eye_pos)
{
  eye_pos->x = -500;
  eye_pos->y = 0;
  eye_pos->z = 0;
}

void	my_screen_pos(sfVector2i *my_pos, int count, int count2)
{
  my_pos->x = count2;
  my_pos->y = count;
}

int		my_scene(t_my_struct *my_struct, t_frame *window,
			 t_smallest *dist, t_face_vtx *save)
{
  t_face_vtx	*tmp;
  sfColor	color;

  tmp = window->scene->face;
  dist->dist = -1;
  save = NULL;
  while (tmp != NULL)
    {
      if ((dist->res = intersect_face(tmp,
				      my_struct, window->scene)) != -1)
	if (dist->res < dist->dist || dist->dist == -1)
	  {
	    dist->dist = dist->res;
	    save = tmp;
	  }
      tmp = tmp->prev;
    }
  if (dist->dist > 0)
    {
      color = get_my_color(window, my_struct, dist->dist, save);
      my_put_pixel(window->frameb, my_struct->pos.x, my_struct->pos.y, color);
    }
  else
    my_put_pixel(window->frameb, my_struct->pos.x, my_struct->pos.y, sfWhite);
  return (0);
}
