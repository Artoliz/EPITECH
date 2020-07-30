/*
** my_put_pixel.c for my_put_pixel in /home/descou_c/Graphic/RTV1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Feb  3 14:11:47 2017 Charles Descoust
** Last update Tue Feb 14 12:51:46 2017 Charles Descoust
*/

#include "inc/my.h"

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
