/*
** average.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/conf_calc
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu May  4 15:09:39 2017 Charles Aubert
** Last update Mon May  8 13:41:09 2017 Charles Aubert
*/

#include "../inc/rt2.h"

sfColor average_color(sfColor *colors, int size)
{
  int   i;
  float sr;
  float sg;
  float sb;
  float sa;

  sr = 0;
  sg = 0;
  sb = 0;
  sa = 0;
  i = 0;
  while (i < size)
    {
      sr += colors[i].r;
      sg += colors[i].g;
      sb += colors[i].b;
      sa += colors[i].a;
      i += 1;
    }
  free(colors);
  return (sfColor_fromRGBA(sr / size, sg / size, sb / size, sa / size));
}

float   average_coef(float *coef, int size)
{
  int   i;
  float sum;

  i = 0;
  sum = 0;
  while (i < size)
    {
      sum += coef[i];
      i += 1;
    }
  if (sum > 1.0)
    sum = 1.0;
  return (sum);
}

float   average_shadow(int *coef, int size)
{
  int   i;
  float sum;

  sum = 0;
  i = 0;
  while (i < size)
    {
      sum += coef[i];
      i += 1;
    }
  return (sum / size);
}

sfColor         get_color_average(t_objects tools, float x, float y)
{
  sfColor       *colors;
  int           i;
  float         incr;

  if (AL == 1)
    return (no_aliasing(tools));
  if ((colors = init_aliasing(&i, &incr)) == NULL)
    return (sfBlack);
  while (tools.vect->pos.y < y + 0.5)
    {
      tools.vect->pos.x = x;
      if (x > 0 && y > 0 && AL > 1 && AL % 4 == 0)
        tools.vect->pos.x -= 0.5;
      while (tools.vect->pos.x < x + 0.5)
        {
          tools.vect->dir = rotate_xyz(calc_dir_vector(500.0, tools.vect->size,
						       tools.vect->pos),  tools.vect->r_eye);
          colors[i] = calc(tools);
	  tools.vect->pos.x += incr;
          i += 1;
        }
      tools.vect->pos.y += incr;
    }
  return (average_color(colors, (AL * (AL / 4))));
}

sfColor average_color_coef(sfColor *colors, int size, float *coef, float bril)
{
  int   i;
  float sr;
  float sg;
  float sb;
  float sa;

  sr = 0;
  sg = 0;
  sb = 0;
  sa = 0;
  i = 0;
  while (i < size)
    {
      sr += colors[i].r * coef[i] * bril;
      sg += colors[i].g * coef[i] * bril;
      sb += colors[i].b * coef[i] * bril;
      sa += colors[i].a;
      i += 1;
    }
  free(colors);
  return (sfColor_fromRGBA(sr, sg, sb, sa));
}
