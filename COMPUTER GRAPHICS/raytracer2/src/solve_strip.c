/*
** solve_strip.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue May 23 12:01:19 2017 Charles Aubert
** Last update Thu May 25 09:46:12 2017 Charles Aubert
*/

#include "../inc/rt2.h"

t_cubic	        get_cubic(double *a)
{
  t_cubic	res;

  res.q = a[2] * a[2] - 3 * a[1];
  res.r = 2 * a[2] * a[2] * a[2] - 9 * a[2] * a[1] + 27 * a[0];
  res.bq = res.q / 9;
  res.br = res.r / 54;
  res.bq3 = res.bq * res.bq * res.bq;
  res.br2 = res.br * res.br;
  res.cr2 = 729 * res.r * res.r;
  res.cq3 = 2916 * res.q * res.q * res.q;
  res.sgnbr = res.br >= 0 ? 1 : -1;
  res.i = 0;
  return (res);
}

int	solve_second_case(t_cubic c, double *a, double *r)
{
  c.sqrtbq = sqrt(c.bq);
  if (c.br > 0)
    {
      r[0] = -2 * c.sqrtbq - a[2] / 3;
      r[1] = c.sqrtbq - a[2] / 3;
      r[2] = c.sqrtbq - a[2] / 3;
    }
  else
    {
      r[0] = -c.sqrtbq - a[2] / 3;
      r[1] = -c.sqrtbq - a[2] / 3;
      r[2] = 2 * c.sqrtbq - a[2] / 3;
    }
  return (3);
}

int	solve_third_case(t_cubic c, double *a, double *r)
{
  c.ratio = c.sgnbr * sqrt(c.br2 / c.bq3);
  c.theta = acos(c.ratio);
  c.norm = -2 * sqrt(c.bq);
  c.r0 = c.norm * cos(c.theta / 3) - a[2] / 3;
  c.r1 = c.norm * cos((c.theta + 2.0 * M_PI) / 3) - a[2] / 3;
  c.r2 = c.norm * cos((c.theta - 2.0 * M_PI) / 3) - a[2] / 3;
  if (c.r0 > c.r1)
    double_swap(&c.r0, &c.r1);
  if (c.r1 > c.r2)
    {
      double_swap(&c.r1, &c.r2);
      if (c.r0 > c.r1)
	double_swap(&c.r0, &c.r1);
    }
  r[0] = c.r0;
  r[1] = c.r1;
  r[2] = c.r2;
  return (3);
}

int	solve_fourth_case(t_cubic c, double *a, double *r)
{
  c.ba = -c.sgnbr * pow(fabs(c.br) + sqrt(c.br2 - c.bq3), 1.0 / 3.0);
  c.bb = c.bq / c.ba;
  r[0] = c.ba + c.bb - a[2] / 3.0;
  return (1);
}

int		solve_cubic(double *a, double *r)
{
  t_cubic         c;

  c = get_cubic(a);
  if (c.br == 0.0 && c.bq == 0.0)
    {
      while (c.i++ < 3.0)
	r[c.i] = -a[2] / 3.0;
      return (3);
    }
  else if (c.cr2 == c.cq3)
    return (solve_second_case(c, a, r));
  else if (c.br2 < c.bq3)
    return (solve_third_case(c, a, r));
  else
    return (solve_fourth_case(c, a, r));
}
