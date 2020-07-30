/*
** new_framebuffer.c for new_framebuffer in /home/descou_c/Graphic/test/raytracer2/threads
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sun May 28 14:16:23 2017 Charles Descoust
** Last update Sun May 28 19:04:28 2017 Bastien LECUSSAN
*/

#include "../inc/rt2.h"

sfColor		new_color(t_my_framebuffer *buffer, sfVector2i *pos)
{
  sfColor	color;

  color.r = buffer->pixels[(WIDTH * pos->y + pos->x) * 4];
  color.g = buffer->pixels[(WIDTH * pos->y + pos->x) * 4 + 1];
  color.b = buffer->pixels[(WIDTH * pos->y + pos->x) * 4 + 2];
  color.a = buffer->pixels[(WIDTH * pos->y + pos->x) * 4 + 3];
  return (color);
}

t_my_framebuffer	*calc_new_buffer(t_my_framebuffer *buffer)
{
  t_my_framebuffer	*new;
  sfVector2i		pos;
  sfColor		color;

  if ((new = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  if ((new->pixels = malloc(WIDTH * HEIGHT *
			    sizeof(sfUint8) * 4)) == NULL)
    return (NULL);
  new->height = HEIGHT;
  new->width = WIDTH;
  pos.y = 0;
  while (pos.y < HEIGHT)
    {
      pos.x = 0;
      while (pos.x < WIDTH)
	{
	  color = new_color(buffer, &pos);
	  my_put_pixel(new, pos.x, pos.y, color);
	  pos.x += 1;
	}
      pos.y += 1;
    }
  return (new);
}
