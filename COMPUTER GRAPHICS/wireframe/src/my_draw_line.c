/*
** my_draw_line.c for my_draw_line in /home/descou_c/Graphic/bswireframe_no
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Nov 15 08:52:22 2016 Charles Descoust
** Last update Sun Dec 11 20:02:39 2016 Charles Descoust
*/

#include "../include/wire.h"

int	max_to_min(t_my_framebuffer *buffer, sfVector2f from,
		   sfVector2f to, sfColor color)
{
  float	i;
  float	a;

  a = (to.y - from.y) / (to.x - from.x);
  while (from.x < to.x)
    {
      (a < 0) ? (i = -a) : (i = a);
      my_put_pixel(buffer, from.x, from.y, color);
      from.y = from.y - i;
      from.x = from.x + 1;
    }
  return (0);
}

int	min_to_max(t_my_framebuffer *buffer, sfVector2f from,
		   sfVector2f to, sfColor color)
{
  float i;
  float a;

  a = (to.y - from.y) / (to.x - from.x);
  while (from.x < to.x)
    {
      (a < 0) ? (i = -a) : (i = a);
      my_put_pixel(buffer, from.x, from.y, color);
      from.y = from.y + i;
      from.x = from.x + 1;
    }
  return (0);
}

int	same_y(t_my_framebuffer *buffer, sfVector2i from,
	       sfVector2i to, sfColor color)
{
  while (from.x < to.x)
    {
      my_put_pixel(buffer, from.x, from.y, color);
      from.x = from.x + 1;
    }
  return (0);
}

int	same_x(t_my_framebuffer *buffer, sfVector2i from,
	       sfVector2i to, sfColor color)
{
  while (from.y < to.y)
    {
      my_put_pixel(buffer, from.x, from.y, color);
      from.y = from.y + 1;
    }
  return (0);
}

void		my_draw_line(t_my_framebuffer* framebuffer, sfVector2i from,
			     sfVector2i to, sfColor color)
{
  if (from.x == to.x)
    {
      if (from.y < to.y)
	same_x(framebuffer, from, to, color);
      else
	same_x(framebuffer, to, from, color);
    }
  else if (from.x < to.x)
    {
      if (from.y > to.y)
  	max_to_min(framebuffer, transform(from), transform(to), color);
      else if (from.y < to.y)
  	min_to_max(framebuffer, transform(from), transform(to), color);
      else
  	same_y(framebuffer, from, to, color);
    }
  else
    {
      if (from.y < to.y)
  	max_to_min(framebuffer, transform(to), transform(from), color);
      else if (from.y > to.y)
  	min_to_max(framebuffer, transform(to), transform(from), color);
      else
  	same_y(framebuffer, to, from, color);
    }
}
