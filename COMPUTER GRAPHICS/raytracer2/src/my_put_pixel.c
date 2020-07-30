/*
** my_put_pixel.c for  in /home/miklox/semestre0/info_graph/Wireframe/wireframe
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Mon Dec  5 15:42:39 2016 Bastien LECUSSAN
** Last update Sat May 27 12:59:59 2017 Bastien LECUSSAN
*/

#include "src.h"

void            my_put_pixel(t_my_framebuffer *framebuffer, int x,
			     int y, sfColor color)
{
  if (x >= 0 && y >= 0 && x < framebuffer->width && y < framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
