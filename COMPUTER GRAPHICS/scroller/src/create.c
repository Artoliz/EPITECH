/*
** create.c for create in /home/descou_c/Graphic/RTV1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Feb  3 14:37:31 2017 Charles Descoust
** Last update Fri Mar 31 23:41:33 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVideoMode	create_my_mode()
{
  sfVideoMode   mode;

  mode.width = WIDTH;
  mode.height = HEIGHT;
  mode.bitsPerPixel = 32;
  return (mode);
}

t_my_framebuffer*	my_framebuffer_create(int width, int height)
{
  int                   i;
  sfUint8               *pixels;
  t_my_framebuffer      *buffer;

  pixels = malloc(sizeof(*pixels) * width * height * 4);
  if (pixels == NULL)
    return (NULL);
  i = 0;
  while (i < (width * height * 4))
    {
      pixels[i] = 0;
      i = i + 1;
    }
  buffer = malloc(sizeof(t_my_framebuffer));
  if (buffer == NULL)
    return (NULL);
  buffer->pixels = pixels;
  buffer->width = width;
  buffer->height = height;
  return (buffer);
}

sfTexture*	create_my_texture(sfVideoMode mode)
{
  sfTexture*    texture;

  texture = sfTexture_create(mode.width, mode.height);
  return (texture);
}

sfSprite*	create_my_sprite(sfTexture* texture)
{
  sfSprite*     sprite;

  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}

t_my_win	create_my_win(sfVideoMode mode, t_my_framebuffer* buffer,
			      sfTexture* texture, sfSprite* sprite)
{
  sfRenderWindow*       window;
  t_my_win              win;

  window = sfRenderWindow_create(mode, "Raytracer1", sfResize | sfClose, NULL);
  win.mode = mode;
  win.buffer = buffer;
  win.texture = texture;
  win.sprite = sprite;
  win.window = window;
  return (win);
}
