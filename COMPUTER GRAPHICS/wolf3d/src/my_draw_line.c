/*
** my_draw_line.c for my_draw_line in /home/descou_c/Graphic/wolf3d/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Dec 21 14:23:41 2016 Charles Descoust
** Last update Tue Jan 24 17:45:31 2017 Charles Descoust
*/

#include "../inc/my.h"

int	max_to_min(t_my_framebuffer *buffer, sfVector2f from,
		   sfVector2f to, sfColor color)
{
  float	i;
  float	a;

  a = (to.y - from.y) / (to.x - from.x);
  while (from.x < to.x)
    {
      (a < 0) ? (i = -a) : (i = a);
      if ((from.x >= 0 && from.x < buffer->width) &&
	  (from.y >= 0 && from.y < buffer->height))
	my_put_pixel(buffer, from.x, from.y, color);
      from.y = from.y - i;
      from.x = from.x + 1.0;
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
      if ((from.x >= 0 && from.x < buffer->width) &&
	  (from.y >= 0 && from.y < buffer->height))
	my_put_pixel(buffer, from.x, from.y, color);
      from.y = from.y + i;
      from.x = from.x + 1.0;
    }
  return (0);
}

int	same(t_my_framebuffer* buffer, sfVector2i from,
	     sfVector2i to, sfColor color)
{
  if (from.y == to.y)
    {
      while (from.x < to.x)
	{
	  if (from.x >= 0 && from.x < buffer->width)
	    my_put_pixel(buffer, from.x, from.y, color);
	  from.x = from.x + 1;
	}
    }
  else
    {
      while (from.y < to.y)
	{
	  if (from.y >= 0 && from.y < buffer->height)
	    my_put_pixel(buffer, from.x, from.y, color);
	  from.y = from.y + 1;
	}
    }
  return (0);
}

sfVector2f	transform(sfVector2i src)
{
  sfVector2f    dest;

  dest.x = src.x;
  dest.y = src.y;
  return (dest);
}

void	my_draw_line(t_my_framebuffer* framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  if (from.x == to.x || from.y == to.y)
    {
      if (from.x < to.x || from.y < to.y)
	same(framebuffer, from, to, color);
      else
	same(framebuffer, to, from, color);
    }
  else if (from.x < to.x)
    {
      if (from.y > to.y)
  	max_to_min(framebuffer, transform(from), transform(to), color);
      else if (from.y < to.y)
  	min_to_max(framebuffer, transform(from), transform(to), color);
    }
  else
    {
      if (from.y < to.y)
  	max_to_min(framebuffer, transform(to), transform(from), color);
      else if (from.y > to.y)
  	min_to_max(framebuffer, transform(to), transform(from), color);
    }
}
