/*
** hyperbolic_paraboloid.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon May 22 16:21:59 2017 Charles Aubert
** Last update Mon May 22 16:22:41 2017 Charles Aubert
*/

#include "../inc/src.h"

float   intersect_hyperbolic_paraboloid(sfVector3f e, sfVector3f v, float s)
{
  return (-1);
}

float   hyperbolic_paraboloid_prep(sfVector3f e, sfVector3f v,
				   float r, t_object *obj)
{
  float k;

  e = translate_in(e, obj->pos);
  e = rotate_xyz_in(e, obj->rot);
  v = rotate_xyz_in(v, obj->rot);
  k = intersect_hyperbolic_paraboloid(e, v, r);
  v = rotate_zyx(v, obj->rot);
  e = rotate_zyx(e, obj->rot);
  e = translate(e, obj->pos);
  return (k);
}

sfVector3f      get_normal_hyperbolic_paraboloid()
{
  return (-1);
}
