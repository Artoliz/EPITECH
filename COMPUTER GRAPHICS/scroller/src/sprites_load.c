/*
** sprites_load.c for  in /home/Gxan/delivery/scroller/src
** 
** Made by Amardeilh Guilhem
** Login   <Gxan@epitech.net>
** 
** Started on  Sat Apr  1 20:41:06 2017 Amardeilh Guilhem
** Last update Sun Apr  2 17:50:33 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"

sfIntRect	rectfill(int left, int top, int width, int height)
{
  sfIntRect	rectangle;

  rectangle.left = left;
  rectangle.top = top;
  rectangle.width = width;
  rectangle.height = height;
  return (rectangle);
}

sfSprite	*create_sprite(char* filename)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  if ((texture = sfTexture_createFromFile(filename, NULL)) == NULL)
    return (NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}

t_sprite	*load_sprites()
{
  t_sprite	*sprites;

  if ((sprites = malloc(sizeof(struct s_sprite))) == NULL)
    return (NULL);
  if ((sprites->title = create_title()) == NULL)
    return (NULL);
  if ((sprites->bg1_sky = create_sprite("./ref/us/bg1_mer.png")) == NULL)
    return (NULL);
  if ((sprites->bg1_land = create_sprite("./ref/us/bg1_plaine.png")) == NULL)
    return (NULL);
  if ((sprites->bg2_sky = create_sprite("./ref/us/bg2_mer.png")) == NULL)
    return (NULL);
  if ((sprites->bg2_land = create_sprite("./ref/us/bg2_plaine.png")) == NULL)
    return (NULL);
  if ((sprites->fireball = create_sprite("./ref/us/fire_sprite.png")) == NULL)
    return (NULL);
  if ((sprites->luna = create_sprite("./ref/us/lune.png")) == NULL)
    return (NULL);
  if ((sprites->sun = create_sprite("./ref/us/sun.png")) == NULL)
    return (NULL);
  if ((sprites->squall = create_sprite("./ref/us/squall_sprite.png")) == NULL)
    return (NULL);
  if ((sprites = create_skystuff(sprites)) == NULL)
    return (NULL);
  return (sprites);
}
