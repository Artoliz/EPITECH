/*
** link.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Apr  7 11:12:47 2017 Charles Aubert
** Last update Sat Apr 29 17:51:19 2017 Charles Aubert
*/

#include "../include/lemin.h"

int		existing_summit(t_summit **res, char *name)
{
  int		i;

  i = 0;
  while (res[i] != NULL)
    {
      if (my_strcmp(res[i]->name, name) == 0)
	return (0);
      i += 1;
    }
  return (1);
}

int             valid_link(char *line, t_summit **res)
{
  char          **tab;

  if ((tab = my_split(line, " -\t")) == NULL ||
      size_array((void *)tab) < 2 || existing_summit(res, tab[0]) != 0 ||
      existing_summit(res, tab[1]) != 0)
    return (free_array_char(tab, 1));
  return (free_array_char(tab, 0));
}

t_link		*create_link(t_link *links, t_summit *add)
{
  t_link	*res;

  if (add == NULL)
    return (NULL);
  if ((res = malloc(sizeof(t_link))) == NULL)
    return (NULL);
  res->next = links;
  res->summit = add;
  return (res);
}

t_summit	**link_summit(char *line, t_summit **res)
{
  char		**tab;
  t_summit	*from;
  t_summit	*to;

  if ((tab = my_split(line, " -\t")) == NULL)
    res = NULL;
  if (res != NULL)
    my_printf(1, 0, "%s-%s\n", tab[0], tab[1]);
  if (res != NULL && (from = get_link(res, tab[0])) == NULL)
    res = NULL;
  if (res != NULL && (to = get_link(res, tab[1])) == NULL)
    res = NULL;
  if (res != NULL && ((from->links = create_link(from->links, to)) == NULL ||
		      (to->links = create_link(to->links, from)) == NULL))
    res = NULL;
  free_array_char(tab, 0);
  return (res);
}
