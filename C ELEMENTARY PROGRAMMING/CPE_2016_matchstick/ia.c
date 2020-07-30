/*
** ia.c for ia in /home/descou_c/CPE/matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Feb 11 16:23:28 2017 Charles Descoust
** Last update Sun Feb 26 16:34:17 2017 Charles Descoust
*/

#include "inc/my.h"

int	rand_line(char** map, int match)
{
  int	i;
  int	j;

  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == '|')
	    return (i + 1);
	  j = j + 1;
	}
      i = i + 1;
    }
}

int	ia_turn4(char** map, int max_match, int* line, int res)
{
  int	match;

  if ((*line = check(map, 0)) == -1)
    {
      match = (res % 3) * (-1/2) + 2;
      if (match <= max_match)
	*line = find_line(map, match);
      else
	*line = find_line(map, max_match);
    }
  else
    match = find_match(map, max_match, *line);
  if (*line == -1)
    *line = rand_line(map, match);
  if (*line == 1 && match == 2)
    match = 1;
  if (match > max_match)
    match = 1;
  return (match);
}

int	ia_turn3(char** map, int max_match, int* line, int res)
{
  int	match;

  if ((*line = check(map, 0)) == -1)
    {
      match = rand() % max_match + 1;
      if (match <= max_match)
	*line = find_line(map, match);
      else
	*line = find_line(map, max_match);
    }
  else
    match = find_match(map, max_match, *line);
  if (*line == -1)
    *line = rand_line(map, match);
  if (*line == 1 && match == 2)
    match = 1;
  if (match > max_match)
    match = 1;
  return (match);
}

int	ia_turn2(char** map, int max_match, int* line, int res)
{
  int	match;

  if (res % 3 == 1)
    match = ia_turn3(map, max_match, line, res);
  else
    match = ia_turn4(map, max_match, line, res);
  return (match);
}

char**	ia_turn(char** map, int max_match, int nb_lines)
{
  int	line;
  int	match;
  int	res;
  int	*tab_match;

  my_putstr("AI's turn...\n");
  if ((tab_match = malloc(sizeof(int) * nb_lines)) == NULL)
    return (NULL);
  tab_match = count_matches(map, tab_match, nb_lines);
  res = total_matches(tab_match, nb_lines);
  match = ia_turn2(map, max_match, &line, res);
  if (match == 0)
    match = 1;
  map = update_map(map, line, match);
  aff_play("AI", match, line);
  return (map);
}
