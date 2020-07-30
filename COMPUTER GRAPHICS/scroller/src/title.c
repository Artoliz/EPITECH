/*
** title.c for title in /home/descou_c/Graphic/my_scro/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Mar 31 23:59:13 2017 Charles Descoust
** Last update Sun Apr  2 15:55:08 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"

void		aff_title(t_my_win win, t_title *title)
{
  int		i;

  i = 1;
  while (i < 10)
    {
      sfSprite_setTextureRect(title[0].cur, title[i].size);
      sfSprite_setPosition(title[0].cur, title[i].pos);
      sfRenderWindow_drawSprite(win.window, title[0].cur, NULL);
      i+= 1;
    }
}

void		move_pos(t_title *title)
{
  int		i;

  i = 1;
  while (i < 10)
    {
      if (title[i].pos.x == WIDTH)
	{
	  title[i].pos.x = title[i].save.x;
	  title[i].pos.y = title[i].save.y;
	}
      title[i].pos.x += 0.05;
      title[i].pos.y = title[i].save.y + cos(title[i].pos.x) * 30;
      i += 1;
    }
}

t_title	*add_pos_size(t_title* title)
{
  title[0].size.left = 0;
  title[0].size.top = 0;
  title[1].size.left = 32 * 3;
  title[1].size.top = 25 * 3;
  title[2].size.left = 32 * 4;
  title[2].size.top = 25 * 4;
  title[3].size.left = 32 * 5;
  title[3].size.top = 25 * 3;
  title[4].size.left = 32 * 0;
  title[4].size.top = 25 * 4;
  title[5].size.left = 32 * 7;
  title[5].size.top = 25 * 3;
  title[6].size.left = 32 * 5;
  title[6].size.top = 25 * 4;
  title[7].size.left = 32 * 1;
  title[7].size.top = 25 * 4;
  title[8].size.left = 32 * 1;
  title[8].size.top = 25 * 5;
  title[9].size.left = 32 * 2;
  title[9].size.top = 25 * 5;
  return (title);
}

t_title		*add_tab(t_title *title, sfSprite* sprite)
{
  int		i;
  int		j;
  int		k;

  i = 1;
  k = 10;
  j = 400;
  title[0].cur = sprite;
  title[0].pos.x = 0;
  title[0].pos.y = 0;
  while (i < 10)
    {
      title[i].save.x = k;
      title[i].save.y = j;
      title[i].pos.x = k;
      title[i].pos.y = j;
      title[i].size.width = 32;
      title[i].size.height = 25;
      k += 32;
      i += 1;
    }
  title = add_pos_size(title);
  return (title);
}

t_title		*create_title()
{
  t_title	*title;
  sfTexture	*texture;
  sfSprite	*sprite;

  if ((title = malloc(sizeof(t_title) * 10)) == NULL)
    return (NULL);
  if ((texture = sfTexture_createFromFile("./ref/font/fontf.png",
					  NULL)) == NULL)
    return (NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  title = add_tab(title, sprite);
  return (title);
}
