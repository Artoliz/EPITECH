/*
** squall_move.c for  in /home/Gxan/delivery/scroller
** 
** Made by Amardeilh Guilhem
** Login   <Gxan@epitech.net>
** 
** Started on  Sun Apr  2 14:47:15 2017 Amardeilh Guilhem
** Last update Sun Apr  2 18:28:00 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"

float		squall_attack(t_my_win win, sfSprite *squall, time_t count, float inc)
{
  sfIntRect	rectangle;
  sfVector2f	pos;

  pos.x = 350;
  pos.y = 820;
  if ((int) inc < 8.5 && count < 10)
    inc += 0.04;
  if ((int) inc > 7.5 && count > 10)
    inc -= 0.05;
  rectangle = rectfill(53 * (int) inc, 0, 53, 79);
  sfSprite_setTextureRect(squall, rectangle);
  sfSprite_setPosition(squall, pos);
  sfRenderWindow_drawSprite(win.window, squall, NULL);
  return (inc);
}

void			squall_event(t_my_win win, sfSprite *squall,
				     time_t count)
{
  static float		inc = 7;
  sfVector2f		pos;
  sfIntRect		rectangle;

  pos.x = 350;
  pos.y = 820;
  if (count < 7 || count >= 12)
    {
      if ((int) inc == 1)
	inc = 7;
      inc -= 0.04;
      rectangle = rectfill(53 * (int) inc, 0, 53, 79);
      sfSprite_setTextureRect(squall, rectangle);
      sfSprite_setPosition(squall, pos);
      sfRenderWindow_drawSprite(win.window, squall, NULL);
    }
  else if (count >= 7 && count < 12)
    inc = squall_attack(win, squall, count, inc);
}
