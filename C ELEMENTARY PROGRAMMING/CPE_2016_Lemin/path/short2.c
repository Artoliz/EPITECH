/*
** short2.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/CPE_2016_Lemin/path
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed Apr 19 17:22:06 2017 Charles Aubert
** Last update Fri Apr 21 16:28:56 2017 Charles Aubert
*/

#include "../include/lemin.h"

t_search	find_smallest2(t_link *save, t_search search)
{
  int           min;
  t_search      res;
  t_search      tmp;
  t_link        *l;

  res.start = NULL;
  min = -1;
  l = save;
  while (l != NULL)
    {
      if (my_strcmp(search.send, l->summit->name) != 0 &&
	  my_strcmp(l->summit->name, search.start->name) != 0)
	{
	  tmp = scan_links(update_struct(search, l->summit,
					 search.start->name), 0);
	  if (min < 0 || (min > 0 && tmp.start != NULL && tmp.i < min))
	    {
	      min = tmp.i;
	      res = tmp;
	    }
	}
      l = l->next;
    }
  return (res);
}
