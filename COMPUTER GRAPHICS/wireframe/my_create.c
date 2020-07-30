/*
** my_create.c for my_create in /home/descou_c/Graphic/wireframe
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Dec  5 16:47:19 2016 Charles Descoust
** Last update Sun Dec 11 15:25:59 2016 Charles Descoust
*/

#include "include/wire.h"

sfVideoMode	my_create_mode()
{
  sfVideoMode   mode;

  mode.width = WIDTH;
  mode.height = HEIGHT;
  mode.bitsPerPixel = 32;
  return (mode);
}

t_my_win		my_create_window(sfVideoMode mode, t_my_framebuffer *buffer)
{
  sfRenderWindow	*window;
  t_my_win		win;

  window = sfRenderWindow_create(mode, "wireframe", sfResize | sfClose, NULL);
  if (window == NULL)
    exit(84);
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
