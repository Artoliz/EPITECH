/*
** torus.c for torus in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar  9 09:43:20 2017 Charles Descoust
** Last update Thu Mar  9 11:02:50 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	torus_expr(sfVector3f eye, sfVector3f dir, sfVector3f tore, float R, float r)
{

  return (tore);
}

float		intersect_torus(sfVector3f eye, sfVector3f dir, float R, float r)
{
  float		k;
  sfVector3f	expr;
  float		delta;

  expr.x = (R + r * cos(u)) * cos(v);
  expr.y = (R + r * cos(u)) * sin(v);
  expr.z = r * sin(v);
  expr = torus_expr(eye, dir, expr, R, r);
  delta = pow(expr.y, 2) - 4.f * expr.x * expr.z;
  if (delta < 0)
    return (-1.0f);
  k = calc_delta(delta, expr);
  if (k < 0)
    return (-1.0f);
  return (k);
}
