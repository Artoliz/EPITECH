/*
** intersect_plane.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/Raytracer1/bsraytracer1/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Feb  7 09:36:19 2017 Charles Aubert
** Last update Wed May 24 14:48:55 2017 Charles Aubert
*/

#include "../inc/src.h"

double		intersect_plane(sfVector3f e, sfVector3f v)
{
  double	k;

  if (v.z == 0.0)
    return (-1.0);
  k = -(e.z) / v.z;
  if (k < 0.0)
    return (-1.0);
  return (k);
}

double   plane_prep(sfVector3f e, sfVector3f v, t_object *obj)
{
  double k;

  e = translate_in(e, obj->pos);
  e = rotate_xyz_in(e, obj->rot);
  k = intersect_plane(e, v);
  e = rotate_zyx(e, obj->rot);
  e = translate(e, obj->pos);
  return (k);
}

sfVector3f      get_normal_plane(int upward)
{
  sfVector3f    result;

  result.x = 0.0;
  result.y = 0.0;
  result.z = 100.0;
  if (upward == 0)
    result.z = -100.0;
  return (result);
}

sfColor         checkboard(sfVector3f pos, t_object *obj)
{
  int           a;
  int           b;

  a = pos.x;
  b = pos.y;
  if (a < 0)
    a *= -1;
  if (b < 0)
    b *= -1;
  if (a % 100 > 50 && b % 100 > 50)
    return (obj->sc);
  else if (a % 100 <= 50 && b % 100 <= 50)
    return (obj->sc);
  else if (a % 100 <= 50 && b % 100 >= 0)
    return (sfBlack);
  else if (a % 100 >= 0 && b % 100 <= 50)
    return (sfBlack);
  return (obj->sc);
}
