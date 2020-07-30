/*
** update_screen.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/display
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed May  3 21:19:10 2017 Charles Aubert
** Last update Tue May 23 09:34:45 2017 Charles Aubert
*/

#include "../inc/rt2.h"

int     draw(t_win win)
{
  sfTexture_updateFromPixels(win.texture, win.buffer->pixels,
			     WIDTH, HEIGHT, 0, 0);
  sfRenderWindow_clear(win.win, sfBlack);
  sfRenderWindow_drawSprite(win.win, win.sprite, NULL);
  sfRenderWindow_display(win.win);
  return (0);
}
