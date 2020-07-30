/*
** ia2.c for ia in /home/descou_c/CPE/CPE_2016_matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Feb 22 11:00:37 2017 Charles Descoust
** Last update Sun Feb 26 11:35:43 2017 Charles Descoust
*/

#include "inc/my.h"

int*	count_matches(char** map, int* tab, int nb_lines)
{
  int   i;
  int   j;
  int   c;

  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      c = 0;
      while (map[i][j] != '\0')
        {
          if (map[i][j] == '|')
            c = c  + 1;
          j = j + 1;
        }
      tab[i] = c;
      i = i + 1;
    }
  return (tab);
}

int	total_matches(int* tab_match, int nb_lines)
{
  int   i;
  int   res;

  i = 0;
  res = 0;
  while (i < nb_lines)
    {
      res = res + tab_match[i];
      i = i + 1;
    }
  return (res);
}

int	find_line(char** map, int match)
{
  int   i;
  int   j;
  int   c;

  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      c = 0;
      while (map[i][j] != '\0')
        {
          if (map[i][j] == '|')
            c = c + 1;
          j = j + 1;
        }
      if (c >= match)
        return (i + 1);
      i = i + 1;
    }
  return (-1);
}

int	check(char** map, int i)
{
  int   j;
  int   c;
  int   d;

  c = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != '\0')
        {
          if (map[i][j] == '|')
            {
              d = i;
              c = c + 1;
              break;
            }
          j = j + 1;
        }
      i = i + 1;
    }
  if (c == 1)
    return (d + 1);
  else
    return (-1);
}

int	find_match(char** map, int max_match, int line)
{
  int   i;
  int   c;

  i = 0;
  c = 0;
  while (map[line - 1][i] != '\0')
    {
      if (map[line -1][i] == '|')
        c = c + 1;
      i = i + 1;
    }
  return (c - 1);
}
