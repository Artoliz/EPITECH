/*
** fireball.c for  in /home/Gxan/delivery/scroller
** 
** Made by Amardeilh Guilhem
** Login   <Gxan@epitech.net>
** 
** Started on  Sat Apr  1 16:28:22 2017 Amardeilh Guilhem
** Last update Sun Apr  2 22:38:04 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"
#include <errno.h>

void			fireball_event(t_my_win win, sfSprite *fireball,
				       time_t count)
{
  static sfVector2f	pos = {350, 760};
  static float		inc = 0;
  sfIntRect		rectangle;

  if (count >= 8 && count < 13)
    {
      inc += 0.04;
      rectangle = rectfill(220 * (int) inc, 0, 220, 188);
      sfSprite_setTextureRect(fireball, rectangle);
      sfSprite_setPosition(fireball, pos);
      sfRenderWindow_drawSprite(win.window, fireball, NULL);
      pos.x += 2.5;
    }
}

sfSprite	*create_fireball(char *fn)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  if ((texture = sfTexture_createFromFile(fn, NULL)) == NULL)
    return (NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}
