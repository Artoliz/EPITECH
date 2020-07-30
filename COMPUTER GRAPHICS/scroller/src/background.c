/*
** background.c for background in /home/descou_c/Graphic/my_scro/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Apr  1 10:27:43 2017 Charles Descoust
** Last update Sat Apr  1 21:22:35 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"

t_sprite	*create_bg_day(char *fn1, char *fn2, t_sprite *sprites)
{
  sfTexture     *text_sky;
  sfTexture	*text_land;

  if ((text_sky = sfTexture_createFromFile
       (fn1, NULL)) == NULL)
    return (NULL);
  if ((text_land = sfTexture_createFromFile
       (fn2, NULL)) == NULL)
    return (NULL);
  sprites->bg1_sky = sfSprite_create();
  sprites->bg1_land = sfSprite_create();
  sfSprite_setTexture(sprites->bg1_sky, text_sky, sfTrue);
  sfSprite_setTexture(sprites->bg1_land, text_land, sfTrue);
  return (sprites);
}

t_sprite	*create_bg_night(char *fn1, char *fn2, t_sprite *sprites)
{
  sfTexture     *text_sky;
  sfTexture     *text_land;

  if ((text_sky = sfTexture_createFromFile
       (fn1, NULL)) == NULL)
    return (NULL);
  if ((text_land = sfTexture_createFromFile
       (fn2, NULL)) == NULL)
    return (NULL);
  sprites->bg2_sky = sfSprite_create();
  sprites->bg2_land = sfSprite_create();
  sfSprite_setTexture(sprites->bg2_sky, text_sky, sfTrue);
  sfSprite_setTexture(sprites->bg2_land, text_land, sfTrue);
  return (sprites);
}
