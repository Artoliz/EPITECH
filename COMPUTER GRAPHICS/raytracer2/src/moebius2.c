/*
** moebius2.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu May 25 09:57:24 2017 Charles Aubert
** Last update Sun May 28 14:27:32 2017 Charles Aubert
*/

#include "../inc/rt2.h"

void	init_strip0(t_strip s, double *coef)
{
  coef[0] = (s.b * s.b * s.d + s.d * s.d * s.d - 2 * s.b * s.b * s.f - 2 *
	     s.d * s.d * s.f + s.d * s.f * s.f - 2 * s.b * s.f * s.a - s.d
	     * s.a * s.a) / coef[3];
}

void	init_strip2(t_strip s, double *coef)
{
  coef[2] = (2 * s.c * s.e * s.b - 4 * s.c * s.g * s.b + s.c * s.c * s.d + 3
              * s.e * s.e * s.d - 4 * s.e * s.g * s.d + s.g * s.g * s.d - 2 *
              s.c * s.c * s.f - 2 * s.e * s.e * s.f + 2 * s.e * s.g * s.f - 2
              * s.c * s.g * s.a) / coef[3];
}

void	init_strip1(t_strip s, double *coef)
{
  coef[1] = (s.e * s.b * s.b - 2 * s.g * s.b * s.b + 2 * s.c * s.b * s.d + 3
	     * s.e * s.d * s.d - 2 * s.g * s.d * s.d - 4 * s.c * s.b * s.f -
	     4 * s.e * s.d * s.f + 2 * s.g * s.d * s.f + s.e * s.f * s.f - 2
	     * s.g * s.b * s.a - 2 * s.c * s.f * s.a - s.e * s.a * s.a)
    / coef[3];
}

void    init_strip(t_strip s, double *coef)
{
  coef[3] = s.c * s.c * s.e + s.e * s.e * s.e - 2 * s.c * s.c * s.g - 2 * s.e
    * s.e * s.g + s.e * s.g * s.g;
  init_strip1(s, coef);
  init_strip2(s, coef);
  init_strip0(s, coef);
}
