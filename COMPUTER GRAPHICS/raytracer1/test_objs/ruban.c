/*
** ruban.c for ruban in /home/descou_c/Graphic/raytracer1/test_objs
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar  9 10:39:10 2017 Charles Descoust
** Last update Sat Mar 11 15:17:22 2017 Charles Descoust
*/

#include "../raytracer1/inc/my.h"

sfVector3f	ruban_expr(sfVector3f eye, sfVector3f dir, float s)
{
  sfVector3f	rub;
  float	a;
  float	u;

  a = 1.0;
  u = 0.5;
  rub.x = (a + u * sin(s / 2)) * cos(s) - eye.x;
  rub.y = (a + u * sin(s / 2)) * cos(s) - eye.y;
  rub.z = u * cos(s / 2) - eye.z;
  /* printf("%f / %f / %f\n", rub.x, rub.y, rub.z); */
  return (rub);
}

float		intersect_ruban(sfVector3f eye, sfVector3f dir, float radius)
{
  sfVector3f	rub;
  float		k;
  float		delta;
  float		s;

  s = radius * M_PI / 180;
  if (s < 0 || s > M_PI_2)
    return (-1.0f);
  rub = ruban_expr(eye, dir, s);
  return (k);
}
