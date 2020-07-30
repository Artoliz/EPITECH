/*
** my_aff.c for my_aff in /home/descou_c/Graphic/wireframe
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Dec  9 17:48:37 2016 Charles Descoust
** Last update Sun Dec 11 17:04:10 2016 Charles Descoust
*/

#include "include/wire.h"

int		aff_my_y(t_my_win win, t_tab tab)
{
  sfVector2i    one;
  sfVector2i    two;
  int           i;
  int           j;

  i = 0;
  while (i != tab.chars)
    {
      j = 0;
      while (j != tab.lines)
	{
	  one = my_parallel_projection(transfert(i, j, tab.tab[j][i]), 45);
	  if (j + 1 <= (tab.lines - 1))
	    two = my_parallel_projection(transfert(i, j + 1, tab.tab[j + 1][i]), 45);
	  else
	    break;
	  my_draw_line(win.buffer, one, two, sfGreen);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

int		aff_my_z(t_my_win win, t_tab tab)
{
  sfVector2i    one;
  sfVector2i    two;
  int           i;
  int           j;

  j = 0;
  while (j != tab.lines)
    {
      i = 0;
      while (i != tab.chars)
	{
	  one = my_parallel_projection(transfert(i, j, tab.tab[j][i]), 45);
	  if (i + 1 <= (tab.chars - 1))
	    two = my_parallel_projection(transfert(i + 1, j, tab.tab[j][i + 1]), 45);
	  else
	    break;
	  my_draw_line(win.buffer, one, two, sfGreen);
	  i = i + 1;
	}
      j = j + 1;
    }
  return (0);
}
