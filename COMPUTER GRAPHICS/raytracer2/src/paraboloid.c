/*
** paraboloid.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon May 22 16:19:19 2017 Charles Aubert
** Last update Wed May 24 14:48:39 2017 Charles Aubert
*/

#include "../inc/src.h"

double		intersect_paraboloid(sfVector3f e, sfVector3f v)
{
  sfVector3f	abc;
  double	k;
  double	delta;

  abc.x = pow(v.x, 2) + pow(v.y, 2);
  abc.y = 2.f * (e.x * v.x + v.z * e.y) - v.z;
  abc.z = pow(e.x, 2) + pow(e.y, 2) - e.z;
  delta = pow(abc.y, 2) - (4.f * abc.x * abc.z);
  k = check_k_value(delta, abc.x, abc.y);
  return (k);
}

double   paraboloid_prep(sfVector3f e, sfVector3f v,
			 double r, t_object *obj)
{
  double k;

  r -= 1;
  e = translate_in(e, obj->pos);
  e = rotate_xyz_in(e, obj->rot);
  v = rotate_xyz_in(v, obj->rot);
  k = intersect_paraboloid(e, v);
  v = rotate_zyx(v, obj->rot);
  e = rotate_zyx(e, obj->rot);
  e = translate(e, obj->pos);
  return (k);
}

sfVector3f	get_normal_paraboloid(sfVector3f i_p)
{
  sfVector3f	result;

  result.x = i_p.x;
  result.y = i_p.y;
  result.z = -sqrt(i_p.z);
  return (result);
}
