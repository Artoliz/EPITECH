/*
** fade.c for  in /home/Gxan/delivery/scroller
** 
** Made by Amardeilh Guilhem
** Login   <Gxan@epitech.net>
** 
** Started on  Sun Apr  2 21:08:02 2017 Amardeilh Guilhem
** Last update Sun Apr  2 22:46:51 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"

void			aff_fade(t_my_win win, sfSprite *sprite, time_t count)
{
  sfVector2f		pos;
  static sfColor       	color = {255, 255, 255, 0};

  pos.x = 0;
  pos.y = 0;
  sfSprite_setPosition(sprite, pos);
  sfSprite_setColor(sprite, color);
  sfRenderWindow_drawSprite(win.window, sprite, NULL);
  if ((count >= 14 && count < 15 && color.a < 255) ||
      (count >= 21 && color.a < 255))
    color.a += 5;
  if (count >= 15 && count < 21 && color.a > 0)
    color.a -= 5;
}
