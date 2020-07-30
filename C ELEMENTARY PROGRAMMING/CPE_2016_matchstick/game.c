/*
** game.c for game in /home/descou_c/CPE/matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Feb 11 12:34:28 2017 Charles Descoust
** Last update Wed Feb 22 14:52:07 2017 Charles Descoust
*/

#include "inc/my.h"

char	**update_map(char** map, int line, int match)
{
  int	i;
  int	j;

  i = 0;
  while (map[i] != NULL)
    {
      if (i == (line - 1))
	{
	  j = my_strlen(map[i]) - 1;
	  while (map[i][j] != '|')
	    j = j - 1;
	  while (match > 0)
	    {
	      if (map[i][j] == '|')
		map[i][j] = ' ';
	      match = match - 1;
	      j = j - 1;
	    }
	}
      i = i + 1;
    }
  return (map);
}

char	*my_loose(char** map)
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
	    return ("OK");
	  j = j + 1;
	}
      i = i + 1;
    }
  return ("KO");
}

int	game(char** map, int nb_lines, int max_match)
{
  my_putstr("Your turn:\n");
  if ((map = user_turn(map, nb_lines, max_match)) == NULL)
    {
      if (map == 0)
	return (0);
      else
	return (84);
    }
  aff_map(map, nb_lines);
  if (my_strcmp(my_loose(map), "KO") == 0)
    {
      my_putstr("You lost, too bad...\n");
      return (2);
    }
  my_putstr("\n");
  map = ia_turn(map, max_match, nb_lines);
  aff_map(map, nb_lines);
  if (my_strcmp(my_loose(map), "KO") == 0)
    {
      my_putstr("I lost... snif... but I'll get you next time!!\n");
      return (1);
    }
  my_putstr("\n");
  game(map, nb_lines, max_match);
}
