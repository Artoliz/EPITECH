/*
** intersect_sphere.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/Raytracer1/bsraytracer1
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Feb  6 18:32:09 2017 Charles Aubert
** Last update Wed May 24 14:44:40 2017 Charles Aubert
*/

#include "../inc/src.h"

double	check_return_cylinder(double k1, double k2)
{
  if (k1 < 0.0 && k2 < 0.0)
    return (-1.0);
  else if (k1 < 0.0)
    return (k2);
  else if (k2 < 0.0)
    return (k1);
  return ((k1 < k2) ? k1 : k2);
}

double		intersect_cylinder(sfVector3f e, sfVector3f v,
				   double r)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k1;
  double	k2;

  a = pow(v.x, 2) + pow(v.y, 2);
  b = 2 * (e.x * v.x + e.y * v.y);
  c = pow(e.x, 2) + pow(e.y, 2) - pow(r, 2);
  delta = pow(b, 2) - (4 * a * c);
  if (delta == 0.0 && a != 0.0)
    {
      k1 = -b / (2 * a);
      return ((k1 > 0.0) ? k1 : -1.0);
    }
  else if (delta > 0.0 && a != 0.0)
    {
      k1 = (-b + sqrt(delta)) / (2 * a);
      k2 = (-b - sqrt(delta)) / (2 * a);
      return (check_return_cylinder(k1, k2));
    }
  else
    return (-1.0);
}

double		cylinder_prep(sfVector3f e, sfVector3f v,
			      double r, t_object *obj)
{
  double	k;

  e = translate_in(e, obj->pos);
  e = rotate_xyz_in(e, obj->rot);
  v = rotate_xyz_in(v, obj->rot);
  k = intersect_cylinder(e, v, r);
  v = rotate_zyx(v, obj->rot);
  e = rotate_zyx(e, obj->rot);
  e = translate(e, obj->pos);
  return (k);
}

sfVector3f	get_normal_cylinder(sfVector3f i_p)
{
  sfVector3f    result;

  result.x = i_p.x;
  result.y = i_p.y;
  result.z = 0;
  return (result);
}
