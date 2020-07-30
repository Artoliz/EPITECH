/*
** my_aff.c for my_aff in /home/descou_c/CPE/CPE_2016_matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Feb 15 09:04:40 2017 Charles Descoust
** Last update Thu Feb 16 10:52:50 2017 Charles Descoust
*/

#include "inc/my.h"

void	aff_stars(int nb_lines)
{
  int   i;

  i = nb_lines * 2 + 1;
  while (i != 0)
    {
      my_putstr("*");
      i = i - 1;
    }
  my_putstr("\n");
}

void	aff_map(char** map, int nb_lines)
{
  int   i;
  int   j;

  i = 0;
  aff_stars(nb_lines);
  while (map[i] != NULL)
    {
      j = nb_lines - i - 1;
      my_putstr("*");
      while (j != 0)
        {
          my_putstr(" ");
          j = j - 1;
        }
      my_putstr(map[i]);
      j = nb_lines - i - 1;
      while (j != 0)
        {
          my_putstr(" ");
          j = j - 1;
        }
      my_putstr("*\n");
      i = i + 1;
    }
  aff_stars(nb_lines);
}

int	aff_play(char* str, int match, int line)
{
  my_putstr(str);
  my_putstr(" removed ");
  my_put_nbr(match);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putstr("\n");
  return (0);
}
