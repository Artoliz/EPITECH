/*
** aff_back.c for aff_back in /home/descou_c/Graphic/scroller/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Apr  1 16:24:44 2017 Charles Descoust
** Last update Sun Apr  2 18:22:04 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"

void			aff_bg_dark(t_my_win win, t_sprite *sprites)
{
  static sfVector2f     pos[4]= {{0, 0}, {1920, 0}, {0, 819}, {1920, 819}};

  sfSprite_setPosition(sprites->bg2_sky, pos[0]);
  sfSprite_setPosition(sprites->bg2_land, pos[2]);
  sfRenderWindow_drawSprite(win.window, sprites->bg2_sky, NULL);
  sfRenderWindow_drawSprite(win.window, sprites->bg2_land, NULL);
  sfSprite_setPosition(sprites->bg2_sky, pos[1]);
  sfSprite_setPosition(sprites->bg2_land, pos[3]);
  sfRenderWindow_drawSprite(win.window, sprites->bg2_sky, NULL);
  sfRenderWindow_drawSprite(win.window, sprites->bg2_land, NULL);
  pos[0].x -= 0.3;
  pos[1].x -= 0.3;
  pos[2].x -= 0.6;
  pos[3].x -= 0.6;
  if (pos[0].x == -1920)
    pos[0].x = 1920;
  if (pos[1].x == -1920)
    pos[1].x = 1920;
  if (pos[2].x == -1920)
    pos[2].x = 1920;
  if (pos[3].x == -1920)
    pos[3].x = 1920;
}

void			aff_bg_light(t_my_win win, t_sprite *sprites, time_t count)
{
  static sfVector2f     pos[4]= {{0, 0}, {1920, 0}, {0, 839}, {1920, 839}};

  sfSprite_setPosition(sprites->bg1_sky, pos[0]);
  sfSprite_setPosition(sprites->bg1_land, pos[2]);
  sfRenderWindow_drawSprite(win.window, sprites->bg1_sky, NULL);
  sfRenderWindow_drawSprite(win.window, sprites->bg1_land, NULL);
  sfSprite_setPosition(sprites->bg1_sky, pos[1]);
  sfSprite_setPosition(sprites->bg1_land, pos[3]);
  sfRenderWindow_drawSprite(win.window, sprites->bg1_sky, NULL);
  sfRenderWindow_drawSprite(win.window, sprites->bg1_land, NULL);
  if (count < 7 || count >= 12)
    {
      pos[0].x -= 0.3;
      pos[1].x -= 0.3;
      pos[2].x -= 0.6;
      pos[3].x -= 0.6;
    }
  if (pos[0].x == -1920)
    pos[0].x = 1920;
  if (pos[1].x == -1920)
    pos[1].x = 1920;
  if (pos[2].x == -1920)
    pos[2].x = 1920;
  if (pos[3].x == -1920)
    pos[3].x = 1920;
}
