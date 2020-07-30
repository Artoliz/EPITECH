/*
** sphere.c for sphere in /home/descou_c/Graphic/raytracer1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 08:57:29 2017 Charles Descoust
** Last update Tue Mar  7 16:23:24 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  sfVector3f	N;

  N.x = intersection_point.x;
  N.y = intersection_point.y;
  N.z = intersection_point.z;
  return (N);
}

sfVector3f	sphere_expr(sfVector3f dir, sfVector3f eye, float radius)
{
  sfVector3f    expr;
  float         a;

  expr.x = pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2);
  a = eye.x * dir.x + eye.y * dir.y + eye.z * dir.z;
  expr.y = 2.f * a;
  expr.z = pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2) - pow(radius, 2);
  return (expr);
}

float	calc_delta(float delta, sfVector3f expr)
{
  float k1;
  float k2;

  if (delta == 0 && expr.x != 0)
    {
      k1 = -expr.y / (2.f * expr.x);
      if (k1 > 0)
        return (k1);
      else
        return (-1.0f);
    }
  else if (expr.x != 0)
    {
      k1 = (-expr.y + sqrt(delta)) / (2.f * expr.x);
      k2 = (-expr.y - sqrt(delta)) / (2.f * expr.x);
      if (k1 > 0 && k2 > 0)
        return (k1 > k2 ? k2 : k1);
      if ((k1 > 0 && k2 < 0) || (k1 < 0 && k2 > 0))
        return (k1 > 0 ? k1 : k2);
    }
  return (-1.0f);
}

float		intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
				 float radius)
{
  float         k;
  float         delta;
  sfVector3f    expr;

  expr = sphere_expr(dir_vector, eye_pos, radius);
  delta = pow(expr.y, 2) - 4.f * expr.x * expr.z;
  if (delta < 0)
    return (-1.0f);
  k = calc_delta(delta, expr);
  if (k < 0)
    return (-1.0f);
  return (k);
}
