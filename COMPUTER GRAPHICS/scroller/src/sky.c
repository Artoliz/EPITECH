/*
** sky.c for  in /home/Gxan/delivery/scroller
** 
** Made by Amardeilh Guilhem
** Login   <Gxan@epitech.net>
** 
** Started on  Sun Apr  2 17:24:23 2017 Amardeilh Guilhem
** Last update Sun Apr  2 21:07:52 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"

t_sprite	*create_skystuff(t_sprite *sprites)
{
  if ((sprites->cloud1 = create_sprite("./ref/us/nuage.png")) == NULL)
    return (NULL);
  if ((sprites->cloud2 = create_sprite("./ref/us/nuage_bi.png")) == NULL)
    return (NULL);
  if ((sprites->fading = create_sprite("./ref/us/fading.png")) == NULL)
    return (NULL);
  return (sprites);
}

void			aff_sun(t_my_win win, sfSprite *sun)
{
  sfVector2f		pos;

  pos.x = (WIDTH / 2) - 147;
  pos.y = (HEIGHT / 2) - 144;
  sfSprite_setPosition(sun, pos);
  sfRenderWindow_drawSprite(win.window, sun, NULL);
}

void			aff_sky(t_my_win win, t_sprite *sprites, time_t count)
{
  static sfVector2f	pos1 = {WIDTH / 2, 100};
  static sfVector2f	pos2 = {200, 350};
  static sfVector2f    	pos3 = {WIDTH / 2 + 2544, 100};
  static sfVector2f    	pos4 = {2744, 350};
  float			inc;

  if (count < 8  || count >= 12)
    inc = -0.8;
  else
    inc = -0.4;
  sfSprite_setPosition(sprites->cloud1, pos1);
  sfSprite_setPosition(sprites->cloud2, pos2);
  sfRenderWindow_drawSprite(win.window, sprites->cloud1, NULL);
  sfRenderWindow_drawSprite(win.window, sprites->cloud2, NULL);
  sfSprite_setPosition(sprites->cloud1, pos3);
  sfSprite_setPosition(sprites->cloud2, pos4);
  sfRenderWindow_drawSprite(win.window, sprites->cloud1, NULL);
  sfRenderWindow_drawSprite(win.window, sprites->cloud2, NULL);
  pos1.x = (pos1.x < -2544) ? WIDTH : pos1.x + (inc / 2);
  pos2.x = (pos2.x < -2544) ? WIDTH : pos2.x + inc;
  pos3.x = (pos3.x < -2544) ? WIDTH : pos3.x + (inc / 2);
  pos4.x = (pos4.x < -2544) ? WIDTH : pos4.x + inc;
}
