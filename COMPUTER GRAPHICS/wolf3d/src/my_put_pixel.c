/*
** my_put_pixel.c for my_put_pixel in /home/descou_c/Graphic/wolf3d/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Dec 21 14:39:18 2016 Charles Descoust
** Last update Wed Dec 21 14:39:20 2016 Charles Descoust
*/

#include "../inc/my.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  if ((x >= 0 && x < framebuffer->width) && (y >= 0 && y < framebuffer->height))
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
