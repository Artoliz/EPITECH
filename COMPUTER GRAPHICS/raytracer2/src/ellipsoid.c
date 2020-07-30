/*
** ellipsoid.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon May 22 16:15:53 2017 Charles Aubert
** Last update Fri May 26 11:58:46 2017 Charles Aubert
*/

#include "../inc/src.h"

double		check_k_value(double delta, double a, double b)
{
  double	k1;
  double	k2;

  if (delta < 0.00)
    return (-1.00);
  else if (delta >= 0.00)
    {
      k1 = ((b * -1.00) - sqrt(delta)) / (2 * a);
      k2 = ((b * -1.00) + sqrt(delta)) / (2 * a);
      if (k1 >= 0.00 && k2 >= 0.00)
	{
	  if (k1 < k2)
	    return (k1);
	  else
	    return (k2);
	}
      else if (k1 < 0.00 && k2 >= 0.00)
	return (k2);
      else if (k1 >= 0.00 && k2 < 0.00)
	return (k1);
      else if (k1 < 0.00 && k2 < 0.00)
	return (-1.0);
    }
  return (-1.0);
}

double		intersect_ellipsoid(sfVector3f e, sfVector3f v, sfVector3f t,
				    double r)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k;

  a = t.x * pow(v.x, 2) + t.y * pow(v.y, 2)
    + t.z * pow(v.z, 2);
  b = 2 * (t.x * e.x * v.x + t.y * e.y * v.y
           + t.z * e.z * v.z);
  c = t.x * pow(e.x, 2) + t.y * pow(e.y, 2) + t.z * pow(e.z, 2)
    - pow(r, 2);
  delta = pow(b, 2) - 4 * a * c;
  k = check_k_value(delta, a, b);
  return (k);
}

double   ellipsoid_prep(sfVector3f e, sfVector3f v,
			double r, t_object *obj)
{
  double k;

  e = translate_in(e, obj->pos);
  e = rotate_xyz_in(e, obj->rot);
  v = rotate_xyz_in(v, obj->rot);
  k = intersect_ellipsoid(e, v, obj->coef, r);
  v = rotate_zyx(v, obj->rot);
  e = rotate_zyx(e, obj->rot);
  e = translate(e, obj->pos);
  return (k);
}

sfVector3f      get_normal_ellipsoid(sfVector3f i_p, sfVector3f coef)
{
  sfVector3f    result;

  result.x = i_p.x * coef.x;
  result.y = i_p.y * coef.y;
  result.z = i_p.z * coef.z;
  return (result);
}
