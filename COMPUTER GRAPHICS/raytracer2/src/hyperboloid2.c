/*
** hyperboloid2.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon May 22 16:21:20 2017 Charles Aubert
** Last update Wed May 24 14:47:56 2017 Charles Aubert
*/

#include "../inc/src.h"

double   intersect_hyperboloid2(sfVector3f e, sfVector3f v,
				double r, sfVector3f t)
{
  double a;
  double b;
  double c;
  double delta;
  double k;

  a = t.x * pow(v.x, 2) + t.y * pow(v.y, 2) - t.z * pow(v.z, 2);
  b = 2 * (t.x * e.x * v.x + t.y * e.y * v.y - t.z * e.z * v.z);
  c = t.x * pow(e.x, 2) + t.y * pow(e.y, 2) - t.z * pow(e.z, 2) + pow(r, 2);
  delta = pow(b, 2) - 4 * a * c;
  k = check_k_value(delta, a, b);
  return (k);
}

double   hyperboloid2_prep(sfVector3f e, sfVector3f v,
			  double r, t_object *obj)
{
  double k;

  e = translate_in(e, obj->pos);
  e = rotate_xyz_in(e, obj->rot);
  v = rotate_xyz_in(v, obj->rot);
  k = intersect_hyperboloid2(e, v, r, obj->coef);
  v = rotate_zyx(v, obj->rot);
  e = rotate_zyx(e, obj->rot);
  e = translate(e, obj->pos);
  return (k);
}

sfVector3f	get_normal_hyperboloid2(sfVector3f i_p, sfVector3f coef)
{
  sfVector3f	result;

  result.x = i_p.x * coef.x;
  result.y = i_p.y * coef.y;
  result.z = -i_p.z * coef.z;
  return (result);
}
