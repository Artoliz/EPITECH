/*
** summit.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Apr  6 12:01:24 2017 Charles Aubert
** Last update Sat Apr 29 12:21:35 2017 Charles Aubert
*/

#include "../include/lemin.h"

int             valid_summit(t_link *sums, char *name, int x, int y)
{
  t_link	*tmp;

  tmp = sums;
  while (tmp != NULL)
    {
      if (my_strcmp(sums->summit->name, name) == 0 ||
	  (sums->summit->x == x && sums->summit->y == y))
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

t_summit        *get_summit_type(t_summit **res, int type)
{
  int           i;

  i = 0;
  while (res[i] != NULL)
    {
      if (res[i]->type == type)
        return (res[i]);
      i += 1;
    }
  return (NULL);
}

int		count_summits(t_link *sums)
{
  int		count;
  t_link	*tmp;

  count = 0;
  tmp = sums;
  while (tmp != NULL)
    {
      count += 1;
      tmp = tmp->next;
     }
  return (count);
}

t_summit	**get_summits(t_link *sums)
{
  t_summit	**res;
  int		count;
  int		i;

  if ((count = count_summits(sums)) <= 0 ||
      (res = malloc(sizeof(t_summit *) * (count + 1))) == NULL)
    return (NULL);
  i = 0;
  while (sums != NULL)
    {
      res[i] = sums->summit;
      i += 1;
      sums = sums->next;
    }
  res[i] = NULL;
  return (res);
}

t_summit	*create_summit(char *line, int *type, t_link *sums)
{
  char		**tab;
  t_summit	*res;

  if ((tab = my_split(line, " \t")) == NULL ||
      size_array((void *)tab) < 3 ||
      (res = malloc(sizeof(t_summit))) == NULL)
    return (NULL);
  if ((res->name = my_strdup(tab[0])) == NULL)
    return (NULL);
  res->data = 0;
  res->y = my_getnbr(tab[2]);
  res->x = my_getnbr(tab[1]);
  res->type = *type;
  res->links = NULL;
  if (*type == MY_START)
    my_printf(1, 0, "##start\n");
  else if (*type == MY_END)
    my_printf(1, 0, "##end\n");
  my_printf(1, 0, "%s %d %d\n", res->name, res->x, res->y);
  if (valid_summit(sums, res->name, res->x, res->y) != 0)
    return (NULL);
  free_array_char(tab, 0);
  *type = MY_NORMAL;
  return (res);
}
