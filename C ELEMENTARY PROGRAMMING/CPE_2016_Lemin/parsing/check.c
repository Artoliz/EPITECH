/*
** check.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Apr  4 16:57:51 2017 Charles Aubert
** Last update Sat Apr 15 16:59:23 2017 Charles Aubert
*/

#include "../include/lemin.h"

int	check_def(char *line)
{
  char	**tab;

  if ((tab = my_split(line, " \t")) == NULL ||
      my_contain(line, "-") == 0 ||
      size_array((void *)tab) < 3)
    return (free_array_char(tab, 1));
  if (size_array((void *)tab) > 3 && tab[3][0] != '#')
    return (free_array_char(tab, 1));
  if (my_str_isnum(tab[1]) == 1 || my_str_isnum(tab[2]) == 1)
    return (free_array_char(tab, 1));
  return (free_array_char(tab, 0));
}

int	check_link(char *line)
{
  char	**tab;

  if ((tab = my_split(line, " \t-")) == NULL)
    return (free_array_char(tab, 1));
  if (size_array((void *)tab) < 2)
    return (free_array_char(tab, 1));
  if (size_array((void *)tab) > 2 && tab[2][0] != '#')
    return (free_array_char(tab, 1));
  return (free_array_char(tab, 0));
}

int	check_comment(char *line)
{
  char	**tab;

  if ((tab = my_split(line, " \t")) == NULL)
    return (free_array_char(tab, 1));
  if (tab[0][0] == '#')
    return (free_array_char(tab, 0));
  return (free_array_char(tab, 1));
}

int		check_summit(t_summit **res)
{
  int		i;
  int		i2;
  t_summit	**tmp;

  i = 0;
  tmp = res;
  while (res[i] != NULL)
    {
      i2 = 0;
      while (tmp[i2] != NULL)
	{
	  if (i != i2 && (my_strcmp(res[i]->name, tmp[i2]->name) == 0 ||
			  (res[i]->x == tmp[i2]->x && res[i]->y == tmp[i2]->y)))
	    return (1);
	  else if (i != i2 && res[i]->type == MY_START &&
		   tmp[i2]->type == MY_START)
	    return (1);
	  else if (i != i2 && res[i]->type == MY_END && tmp[i2]->type == MY_END)
	    return (1);
	  i2 += 1;
	}
      i += 1;
    }
  return (0);
}

int	check_file(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i][0] != '\0')
	return (1);
      i += 1;
    }
  return (0);
}
