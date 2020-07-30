/*
** moebius.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue May 23 11:07:18 2017 Charles Aubert
** Last update Sun May 28 15:06:48 2017 Charles Aubert
*/

#include "../inc/rt2.h"

int		inside(sfVector3f h, double scale)
{
  double	t;
  double	s;

  t = atan2(h.y, h.x);
  if (double_sign(sinf(t / 2)) != 0.0)
    s = h.z / sinf(t / 2);
  else
    s = double_sign(cosf(t)) ? (h.x / cosf(t) - scale) / cosf(t / 2) :
      (h.y / sinf(t) - scale) / cosf(t / 2);
  h.x -= (scale + s * cosf(t / 2)) * cosf(t);
  h.y -= (scale + s * cosf(t / 2)) * sinf(t);
  h.z -= s * sin(t / 2);
  if (double_sign(h.x * h.x + h.y * h.y + h.z * h.z) == 1)
    return (0);
  return (s >= -(scale / 2) && s <= (scale / 2));
}

double   strip_root(double *roots, int ret, sfVector3f e,
				  sfVector3f v, double scale)
{
  int		i;
  sfVector3f	hit;

  i = 0;
  while (i < ret)
    {
      if (roots[i] > MY_PRES)
        {
          hit = translate(multiply_vec(v, roots[i]), e);
          if (inside(hit, scale))
	    return (roots[i]);
        }
      i += 1;
    }
  return (-1.0);
}

double		intersect_strip(sfVector3f e, sfVector3f v,
				double r, t_object *obj)
{
  double	coef[4];
  double	root[3];
  t_strip	s;
  int		ret;

  s.a = r;
  s.b = e.x;
  s.c = v.x;
  s.d = e.y;
  s.e = v.y;
  s.f = e.z;
  s.g = v.z;
  init_strip(s, coef);
  ret = solve_cubic(coef, root);
  return (strip_root(root, ret, e, v, obj->r));
}

double   strip_prep(sfVector3f e, sfVector3f v,
		    double r, t_object *obj)
{
  double k;

  e = translate_in(e, obj->pos);
  e = rotate_xyz_in(e, obj->rot);
  v = rotate_xyz_in(v, obj->rot);
  k = intersect_strip(e, v, r, obj);
  v = rotate_zyx(v, obj->rot);
  e = rotate_zyx(e, obj->rot);
  e = translate(e, obj->pos);
  return (k);
}

sfVector3f	get_normal_strip(sfVector3f i_p, double scale)
{
  sfVector3f	result;

  result.x = -2 * scale * i_p.z + 2 * i_p.x * i_p.y - 4 * i_p.x * i_p.z;
  result.y = -scale * scale + i_p.x * i_p.x + 3 * i_p.y * i_p.y - 4 * i_p.y *
    i_p.z + i_p.z * i_p.z;
  result.z = -2 * scale * i_p.x - 2 * i_p.x * i_p.x - 2 * i_p.y * i_p.y + 2 *
    i_p.y * i_p.z;
  return (result);
}
