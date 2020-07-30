/*
** cylinder.c for cylinder in /home/descou_c/Graphic/raytracer1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 09:05:23 2017 Charles Descoust
** Last update Tue Mar  7 15:28:29 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f	N;

  N.x = intersection_point.x;
  N.y = intersection_point.y;
  N.z = 0;
  return (N);
}

sfVector3f	cylinder_expr(sfVector3f dir, sfVector3f eye, float radius)
{
  sfVector3f    expr;

  expr.x = pow(dir.x, 2) + pow(dir.y, 2);
  expr.y = 2.f * (dir.x * eye.x + dir.y * eye.y);
  expr.z = pow(eye.x, 2) + pow(eye.y, 2) - pow(radius, 2);
  return (expr);
}

float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
				   float radius)
{
  float         k;
  float         delta;
  sfVector3f    expr;

  expr = cylinder_expr(dir_vector, eye_pos, radius);
  delta = pow(expr.y, 2) - 4.f * expr.x * expr.z;
  if (delta < 0)
    return (-1.0f);
  k = calc_delta(delta, expr);
  if (k < 0)
    return (-1.0f);
  return (k);
}
