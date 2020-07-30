/*
** free.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Apr  6 16:24:54 2017 Charles Aubert
** Last update Wed Apr 19 15:26:01 2017 Charles Aubert
*/

#include "../include/lemin.h"

t_link		*free_links_last(t_link *links)
{
  t_link        *save;

  save = links->next;
  free(links);
  return (save);
}

int		free_links(t_link *links)
{
  t_link	*save;

  save = links->next;
  while (save != NULL)
    {
      free(links);
      links = save;
      save = links->next;
    }
  free(save);
  free(links);
  return (0);
}

int	free_tab_summits(t_summit **res)
{
  int	i;

  i = 0;
  while (res[i] != NULL)
    {
      free(res[i]->name);
      if (res[i]->links != NULL)
	free_links(res[i]->links);
      free(res[i]);
      i += 1;
    }
  free(res);
  return (0);
}

int	free_graph(t_graph *graph)
{
  free_tab_summits(graph->summits);
  free(graph);
  return (0);
}
