/*
** window.c for window in /home/descou_c/Graphic/bswolf3d
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec 13 09:34:47 2016 Charles Descoust
** Last update Mon Jan 23 13:41:43 2017 Charles Descoust
*/

#include "inc/my.h"

sfVector2f	move_pos(float dir, sfVector2f pos, t_my_win win)
{
  sfVector2f	tmp;
  float		dist;

  tmp = pos;
  dist = 0.05;
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    pos = move_forward(pos, dir, dist);
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    pos = move_forward(pos, dir, -dist);
  if (win.map[(int)pos.y][(int)pos.x] == 0)
    return (pos);
  else
    return (tmp);
}

float		move_dir(float dir)
{
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    dir = dir + 1.5;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    dir = dir - 1.5;
  return (dir);
}

int		my_win(t_my_win win, sfSprite *sprite, sfVector2f pos, sfTexture *texture)
{
  sfEvent	event;
  float		dir;

  dir = 270.0;
  while (sfRenderWindow_isOpen(win.window))
    {
      while (sfRenderWindow_pollEvent(win.window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(win.window);
	  if (event.key.code == sfKeyEscape)
	    sfRenderWindow_close(win.window);
	}
      dir = move_dir(dir);
      pos = move_pos(dir, pos, win);
      aff_no_wall(win.buffer);
      aff_wall(win.buffer, pos, win, (dir - 22.5));
      sfTexture_updateFromPixels(texture, win.buffer->pixels, win.buffer->width,
      				 win.buffer->height, 0, 0);
      sfRenderWindow_clear(win.window, sfBlack);
      sfRenderWindow_drawSprite(win.window, sprite, NULL);
      sfRenderWindow_display(win.window);
    }
  return (0);
}

int			open_window(sfVideoMode mode, t_my_framebuffer *buffer, char *path)
{
  t_my_win              win;
  sfTexture             *texture;
  sfSprite              *sprite;
  sfVector2f		pos;
  t_map			info;

  pos.x = 2.5;
  pos.y = 4.5;
  win = my_create_window(mode, buffer);
  if ((texture = my_create_texture(mode)) == NULL)
    return (-1);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  info = create_map(path);
  win.mapSize.x = info.chars;
  win.mapSize.y = info.lines;
  win.map = info.map;
  my_win(win, sprite, pos, texture);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(win.window);
  return (0);
}
