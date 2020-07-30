/*
** map.c for map in /home/descou_c/CPE/matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Feb 11 12:19:25 2017 Charles Descoust
** Last update Sat Feb 11 15:06:35 2017 Charles Descoust
*/

#include "inc/my.h"

char	*add_line(char* cur_line, int j)
{
  int	i;

  i = 0;
  while (j > 0)
    {
      cur_line[i] = '|';
      i = i + 1;
      j = j - 1;
    }
  cur_line[i] = '\0';
  return (cur_line);
}

char	**create_map(int nb_lines)
{
  int	i;
  int	j;
  char	**map;

  i = 0;
  j = 1;
  if ((map = malloc(sizeof(char*) * (nb_lines + 1))) == NULL)
    return (NULL);
  while (i < nb_lines)
    {
      if ((map[i] = malloc(sizeof(char) * (j + 1))) == NULL)
	return (NULL);
      map[i] = add_line(map[i], j);
      j = j + 2;
      i = i + 1;
    }
  map[i] = NULL;
  return (map);
}
