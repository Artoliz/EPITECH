/*
** cone.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/Raytracer1/raytracer1/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed Feb 22 18:24:50 2017 Charles Aubert
** Last update Wed May 24 14:43:40 2017 Charles Aubert
*/

#include "../inc/src.h"

double		intersect_cone_k(double a, double b, double delta)
{
  double	k1;
  double	k2;

  if (delta == 0.0 && a != 0.0)
    {
      k1 = -b / (2 * a);
      return ((k1 > 0.0) ? k1 : -1.0);
    }
  else if (delta > 0.0 && a != 0.0)
    {
      k1 = (-b + sqrt(delta)) / (2 * a);
      k2 = (-b - sqrt(delta)) / (2 * a);
      if (k1 < 0.0 && k2 < 0.0)
	return (-1.0);
      else if (k1 < 0.0)
	return (k2);
      else if (k2 < 0.0)
	return (k1);
      return ((k1 < k2) ? k1 : k2);
    }
  else
    return (-1.0);
}

double		intersect_cone(sfVector3f e, sfVector3f v, double s)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  if (s >= 90 || s <= -90)
    return (-1.0);
  s = pow(tan(PI * s / 180.0), 2);
  a = pow(v.x, 2) + pow(v.y, 2) - pow(v.z, 2) * s;
  b = 2 * (e.x * v.x + e.y * v.y - e.z * v.z * s);
  c = pow(e.x, 2) + pow(e.y, 2) - pow(e.z, 2) * s;
  delta = pow(b, 2) - (4 * a * c);
  return (intersect_cone_k(a, b, delta));
}

double   cone_prep(sfVector3f e, sfVector3f v,
		   double r, t_object *obj)
{
  double k;

  e = translate_in(e, obj->pos);
  e = rotate_xyz_in(e, obj->rot);
  v = rotate_xyz_in(v, obj->rot);
  k = intersect_cone(e, v, r);
  v = rotate_zyx(v, obj->rot);
  e = rotate_zyx(e, obj->rot);
  e = translate(e, obj->pos);
  return (k);
}

sfVector3f      get_normal_cone(sfVector3f i_p, double semi_angle)
{
  sfVector3f    result;

  result.x = i_p.x;
  result.y = i_p.y;
  result.z = -(tan(semi_angle * (PI / 180.0)) * i_p.z);
  return (result);
}
