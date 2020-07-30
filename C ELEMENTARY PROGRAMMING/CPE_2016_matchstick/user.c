/*
** user.c for user in /home/descou_c/CPE/matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Feb 11 15:09:45 2017 Charles Descoust
** Last update Mon Feb 27 16:28:18 2017 Charles Descoust
*/

#include "inc/my.h"

int	if_exist(char** map, int line, int match)
{
  int   i;
  int   j;
  int   count;

  i = 0;
  count = 0;
  while (map[i] != NULL)
    {
      if (i == (line - 1))
        {
          j = my_strlen(map[i]) - 1;
          while (j >= 0)
            {
              if (map[i][j] == '|')
                count = count + 1;
              j = j - 1;
            }
        }
      i = i + 1;
    }
  if (count >= match)
    return (0);
  else
    return (1);
}

int	transit_line(char** map, int nb_lines, int max)
{
  char	*buff;
  int	line;

  buff = NULL;
  my_putstr("Line: ");
  if ((buff = get_next_line(0)) == NULL)
    return (0);
  if (my_strisnum(buff) == 84)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      line = transit_line(map, nb_lines, max);
      if (line == 0)
	return (0);
      buff = NULL;
    }
  if (buff != NULL)
    line = my_getnbr(buff);
  if (line < 1 || line > nb_lines)
    {
      my_putstr("Error: this line is out of range\n");
      line = transit_line(map, nb_lines, max);
      if (line == 0)
	return (0);
      buff = NULL;
    }
  free(buff);
  return (line);
}

int	transit_match(char** map, int nb_lines, int max, int *line)
{
  char	*buff;
  int	match;

  buff = NULL;
  my_putstr("Matches: ");
  if ((buff = get_next_line(0)) == NULL)
    return (0);
  if (my_strisnum(buff) == 84)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      *line = transit_line(map, nb_lines, max);
      if (*line == 0)
	return (0);
      match = transit_match(map, nb_lines, max, line);
      if (match == 0)
	return (0);
      buff = NULL;
    }
  if (buff != NULL)
    match = my_getnbr(buff);
  free(buff);
  if (match == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      *line = transit_line(map, nb_lines, max);
      if (*line == 0)
	return (0);
      match = transit_match(map, nb_lines, max, line);
      if (match == 0)
	return (0);
      buff = NULL;
    }
  return (match);
}

void	error_matches(char** map, int nb_lines, int max, int flag)
{
  if (flag == 1)
    {
      my_putstr("Error: you cannot remove more than ");
      my_put_nbr(max);
      my_putstr(" matches per turn\n");
      map = user_turn(map, nb_lines, max);
    }
  else if (flag == 2)
    {
      my_putstr("Error: not enough matches on this line\n");
      map = user_turn(map, nb_lines, max);
    }
}

char	**user_turn(char** map, int nb_lines, int max)
{
  int   line;
  int   match;

  if ((line = transit_line(map, nb_lines, max)) == 84)
    return (NULL);
  if (line == 0)
    return (0);
  if ((match = transit_match(map, nb_lines, max, &line)) == 84)
    return (NULL);
  if (match == 0)
    return (0);
  if (match > max)
    error_matches(map, nb_lines, max, 1);
  else if (if_exist(map, line, match) == 1)
    error_matches(map, nb_lines, max, 2);
  else
    {
      map = update_map(map, line, match);
      aff_play("Player", match, line);
      return (map);
    }
  return (map);
}
