/*
** cone.c for cone in /home/descou_c/Graphic/raytracer1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 09:02:10 2017 Charles Descoust
** Last update Thu Mar 16 14:10:29 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  sfVector3f	N;

  N.x = intersection_point.x;
  N.y = intersection_point.y;
  N.z = -tan(semiangle * (M_PI / 180)) * intersection_point.z;
  return (N);
}

sfVector3f	cone_expr(sfVector3f dir, sfVector3f eye, float semiangle)
{
  sfVector3f    expr;
  float		s;

  s = pow(tan(M_PI * (fmod(semiangle, 180.0)) / 180.0), 2);
  expr.x = pow(dir.x, 2) + pow(dir.y, 2) - pow(dir.z, 2) * s;
  expr.y = 2 * (eye.x * dir.x + eye.y * dir.y - eye.z * dir.z * s);
  expr.z = pow(eye.x, 2) + pow(eye.y, 2) - pow(eye.z, 2) * s;
  return (expr);
}

float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
			       float semiangle)
{
  float         k;
  float         delta;
  sfVector3f    expr;

  if (semiangle <= -90 || semiangle >= 90)
    return (-1.0f);
  expr = cone_expr(dir_vector, eye_pos, semiangle);
  delta = pow(expr.y, 2) - 4.f * expr.x * expr.z;
  if (delta < 0)
    return (-1.0f);
  k = calc_delta(delta, expr);
  if (k < 0)
    return (-1.0f);
  return (k);
}
