/*
** paraboloide.c for paraboloide in /home/descou_c/Graphic/raytracer1/test_ojbs
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar  9 09:53:31 2017 Charles Descoust
** Last update Thu Mar  9 09:57:19 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	paraboloide_expr(sfVector3f eye, sfVector3f dir, float cte)
{
  sfVector3f	expr;

  expr.x = pow(dir.x, 2) + pow(dir.y, 2) - pow(dir.z, 2) * cte;
  expr.y = 2 * (eye.x * dir.x + eye.y * dir.y - eye.z * dir.z * cte);
  expr.z = pow(eye.x, 2) + pow(eye.y, 2) - pow(eye.z, 2) * cte;
  return (expr);
}

float		intersect_paraboloide(sfVector3f eye_pos, sfVector3f dir, float cte)
{
  float		k;
  float		delta;
  sfVector3f	expr;

  expr = paraboloide_expr(eye_pos, dir, cte);
  delta = pow(expr.y, 2) - 4.f * expr.x * expr.z;
  if (delta < 0)
    return (-1.0f);
  k = calc_delta(delta, expr);
  if (k < 0)
    return (-1.0f);
  return (k);
}
