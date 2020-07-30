/*
** my_aff.c for my_aff in /home/descou_c/Graphic/wolf3d
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Dec 23 12:59:02 2016 Charles Descoust
** Last update Tue Jan 10 13:28:30 2017 Charles Descoust
*/

#include "inc/my.h"

sfColor		sky_color()
{
  sfColor	sky;

  sky.r = 51;
  sky.g = 153;
  sky.b = 255;
  sky.a = 255;
  return (sky);
}

sfColor		ground_color()
{
  sfColor	ground;

  ground.r = 96;
  ground.g = 96;
  ground.b = 96;
  ground.a = 255;
  return (ground);
}

sfColor		wall_color()
{
  sfColor	wall;

  wall.r = 200;
  wall.g = 200;
  wall.b = 200;
  wall.a = 255;
  return (wall);
}

void		aff_no_wall(t_my_framebuffer *buffer)
{
  int		i;
  int		j;

  i = 0;
  while (i < buffer->width)
    {
      j = 0;
      while (j < buffer->height)
  	{
  	  if (j < (buffer->height / 2))
  	    my_put_pixel(buffer, i, j, sky_color());
  	  else
  	    my_put_pixel(buffer, i, j, ground_color());
  	  j = j + 1;
  	}
      i = i + 1;
    }
}

void		aff_wall(t_my_framebuffer *buffer, sfVector2f pos, t_my_win win,
			 float dir)
{
  int		x;
  int		j;
  float		cast;
  float		demi;

  x = 0;
  while (x < WIDTH)
    {
      cast = raycast(pos, dir, win.map, win.mapSize);
      demi = (float)HEIGHT / (2.0 * cast);
      j = (int)demi;
      wall_sup(buffer, x, j);
      wall_inf(buffer, x, j);
      dir = dir + (45.0 / (float)HEIGHT);
      x = x + 1;
    }
}
