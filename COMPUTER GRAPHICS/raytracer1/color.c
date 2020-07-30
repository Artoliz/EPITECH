/*
** color.c for color in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Feb 16 14:24:52 2017 Charles Descoust
** Last update Tue Mar 14 12:58:16 2017 Charles Descoust
*/

#include "inc/my.h"

sfVector3f	choose_normale(t_my_object* obj, sfVector3f new_pos)
{
  sfVector3f	N;

  if (my_strcmp(obj->name, "SPHERE") == 0)
    N = get_normal_sphere(new_pos);
  else if (my_strcmp(obj->name, "CONE") == 0)
    N = get_normal_cone(new_pos, obj->radius);
  else if (my_strcmp(obj->name, "CYLINDER") == 0)
    N = get_normal_cylinder(new_pos);
  else if (my_strcmp(obj->name, "PLANE") == 0)
    N = get_normal_plane(1);
  return (N);
}

float	calc_shadow(t_my_object* save, t_my_pos basic,
		    t_ptr_ft* tab, t_my_object* current)
{
  float	k;
  int	i;

  while (save != NULL)
    {
      i = 0;
      while (i < 3)
	{
	  if (save != current && my_strcmp(tab[i].name, save->name) == 0)
	    {
	      basic.new_pos = translate_inv(basic.new_pos, save->coord);
	      basic.new_pos = rotate_xyz_inv(basic.new_pos, save->rotate);
	      basic.dir_light = rotate_xyz_inv(basic.dir_light, save->rotate);
	      k = tab[i].ft(basic.new_pos, basic.dir_light, save->radius);
	      basic.dir_light = rotate_zyx(basic.dir_light, save->rotate);
	      basic.new_pos = rotate_zyx(basic.new_pos, save->rotate);
	      basic.new_pos = translate(basic.new_pos, save->coord);
	      if (k > 0.0 && k < 1.0)
		return (60.0);
	    }
	  i = i + 1;
	}
      save = save->next;
    }
  return (0.0);
}

sfColor		damier(t_my_object* cur, t_my_pos basic)
{
  int		a;
  int		b;

  a = basic.new_pos.x;
  b = basic.new_pos.y;
  if (a < 0)
    a *= -1;
  if (b < 0)
    b *= -1;
  if (a % 100 > 50 && b % 100 > 50)
    cur->color = sfWhite;
  else if (a % 100 <= 50 && b % 100 <= 50)
    cur->color = sfWhite;
  else if (a % 100 <= 50 && b % 100 > 0)
    cur->color = sfBlack;
  else if (a % 100 > 0 && b % 100 <= 50)
    cur->color = sfBlack;
  return (cur->color);
}

sfColor		calc_new_color(t_my_object* cur, t_my_pos basic,
			       t_my_object* save, t_ptr_ft* tab)
{
  float         coef;
  sfColor       new_color;
  sfVector3f    N;
  float		shadow;

  basic.dir_light = calc_dir_light(basic.new_pos, basic.light_pos);
  shadow = calc_shadow(save, basic, tab, cur);
  basic.dir_light = rotate_xyz_inv(basic.dir_light, cur->rotate);
  basic.new_pos = translate_inv(basic.new_pos, cur->coord);
  basic.new_pos = rotate_xyz_inv(basic.new_pos, cur->rotate);
  N = choose_normale(cur, basic.new_pos);
  if (my_strcmp(cur->name, "PLANE") == 0 && cur->radius == 1)
    cur->color = damier(cur, basic);
  coef = get_light_coef(basic.dir_light, N);
  new_color.r = cur->color.r * coef;
  new_color.g = cur->color.g * coef;
  new_color.b = cur->color.b * coef;
  new_color.a = (cur->color.a - shadow) * coef;
  return (new_color);
}
