/*
** short.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Apr  7 14:51:55 2017 Charles Aubert
** Last update Wed Apr 26 09:17:19 2017 Charles Descoust
*/

#include "../include/lemin.h"

t_search	update_struct(t_search search, t_summit *start, char *name)
{
  search.start = start;
  search.i += 1;
  if (search.i >= search.max)
    search.start = NULL;
  if (start != NULL)
    {
      search.path = create_link(search.path, start);
      search.send = name;
    }
  return (search);
}

int		search_name(t_link *save, t_search search)
{
  t_link	*links;

  links = save;
  while (links != NULL)
    {
      if (my_strcmp(links->summit->name, search.start->name) != 0 &&
	  my_strcmp(search.send, links->summit->name) != 0 &&
	  my_strcmp(search.origin, links->summit->name) != 0 &&
	  my_strcmp(links->summit->name, search.name) == 0)
	return (0);
      links = links->next;
    }
  return (1);
}

t_search	find_smallest(t_link *save, t_search search, int flag)
{
  static int	i = 0;
  t_search	res;

  if (flag)
    i = 0;
  if (i == 0)
    res = find_smallest2(save, search);
  else
    res = update_struct(search, NULL, NULL);
  i = 1;
  return (res);
}

t_search	scan_links(t_search search, int flag)
{
  t_link	*save;

  if (search.i >= search.max || search.start == NULL)
    return (update_struct(search, NULL, NULL));
  save = search.start->links;
  if (search_name(save, search) == 0)
    return (search);
  return (find_smallest(save, search, flag));
}

t_search	init_search(t_summit *start, t_summit *end, int max)
{
  t_search	search;

  search.start = start;
  if ((search.path = create_link(NULL, start)) == NULL)
    {
      search.start = NULL;
      return (search);
    }
  search.i = 1;
  search.max = max;
  search.origin = start->name;
  search.name = end->name;
  search.send = start->name;
  if ((search = scan_links(search, 1)).start != NULL)
    {
      search.path = create_link(search.path, end);
      search.path = double_chain(search.path);
    }
  return (search);
}
