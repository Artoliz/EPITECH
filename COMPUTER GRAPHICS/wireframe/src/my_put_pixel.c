/*
** my_put_pixel.c for my_put_pixel in /home/descou_c/Graphic/bswireframe_no
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Nov 15 08:53:58 2016 Charles Descoust
** Last update Sun Dec 11 17:14:43 2016 Charles Descoust
*/

#include "../include/wire.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;
  if (x > framebuffer->width)
    x = x - framebuffer->width;
  if (y > framebuffer->height)
    y = y - framebuffer->height;
  framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
}
