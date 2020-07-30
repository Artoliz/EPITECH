/*
** my_wall.c for my_wall in /home/descou_c/Graphic/wolf3d
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Jan 10 13:21:03 2017 Charles Descoust
** Last update Tue Jan 17 08:55:32 2017 Charles Descoust
*/

#include "inc/my.h"

void	wall_sup(t_my_framebuffer *buffer, int x, int j)
{
  while (j >= 0)
    {
      my_put_pixel(buffer, x, (HEIGHT / 2) + j, wall_color());
      j = j - 1;
    }
}

void	wall_inf(t_my_framebuffer *buffer, int x, int j)
{
  while (j >= 0)
    {
      my_put_pixel(buffer, x, (HEIGHT / 2) - j, wall_color());
      j = j - 1;
    }
}
