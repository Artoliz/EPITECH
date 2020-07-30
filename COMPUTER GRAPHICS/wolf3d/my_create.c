/*
** my_create.c for my_create_wolf3d in /home/descou_c/Graphic/bswolf3d
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec 13 08:58:06 2016 Charles Descoust
** Last update Thu Jan 12 09:48:18 2017 Charles Descoust
*/

#include "inc/my.h"

sfVideoMode	my_create_mode()
{
  sfVideoMode   mode;

  mode.width = WIDTH;
  mode.height = HEIGHT;
  mode.bitsPerPixel = 32;
  return (mode);
}

t_my_win		my_create_window(sfVideoMode mode,
					 t_my_framebuffer *buffer)
{
  sfRenderWindow        *window;
  t_my_win              win;

  window = sfRenderWindow_create(mode, "Wolf3d", sfResize | sfClose, NULL);
  win.window = window;
  win.buffer = buffer;
  return (win);
}

sfTexture		*my_create_texture(sfVideoMode mode)
{
  sfTexture             *texture;

  texture = sfTexture_create(mode.width, mode.height);
  return (texture);
}
