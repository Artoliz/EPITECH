/*
** window.c for window in /home/descou_c/Graphic/wireframe
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Dec  5 09:27:16 2016 Charles Descoust
** Last update Sun Dec 11 17:02:21 2016 Charles Descoust
*/

#include "include/wire.h"

int			my_window(t_my_win win, sfSprite *sprite)
{
  sfEvent		event;

  while (sfRenderWindow_isOpen(win.window))
    {
      while (sfRenderWindow_pollEvent(win.window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(win.window);
	  if (event.key.code == sfKeyEscape)
	    sfRenderWindow_close(win.window);
	}
      sfRenderWindow_clear(win.window, sfBlack);
      sfRenderWindow_drawSprite(win.window, sprite, NULL);
      sfRenderWindow_display(win.window);
    }
  return (0);
}

int			open_window(t_tab tab, t_my_framebuffer *buffer, sfVideoMode mode)
{
  t_my_win		win;
  sfTexture		*texture;
  sfSprite		*sprite;

  win = my_create_window(mode, buffer);
  if ((texture = my_create_texture(mode)) == NULL)
    return (-1);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  aff_my_z(win, tab);
  aff_my_y(win, tab);
  sfTexture_updateFromPixels(texture, buffer->pixels, buffer->width,
			     buffer->height, 0, 0);
  my_window(win, sprite);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(win.window);
  return (0);
}
