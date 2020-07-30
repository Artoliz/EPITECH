/*
** display.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Apr  6 16:14:36 2017 Charles Aubert
** Last update Thu Apr 13 11:44:17 2017 Charles Aubert
*/

#include "../include/lemin.h"

int		display_double_link(t_link *list)
{
  t_link	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_printf(1, 0, "link name = %s, ", tmp->summit->name);
      my_printf(1, 0, "type = %d\n", tmp->summit->type);
      tmp = tmp->prev;
    }
  return (0);
}

int		display_links(t_link *links)
{
  t_link	*tmp;

  tmp = links;
  while (tmp != NULL)
    {
      my_printf(1, 0, "link name = %s, ", tmp->summit->name);
      my_printf(1, 0, "type = %d\n", tmp->summit->type);
      tmp = tmp->next;
    }
  return (0);
}

int	display_summit(t_summit *sum)
{
  my_printf(1, 0, "name = %s, type = %d, ", sum->name, sum->type);
  my_printf(1, 0, "x = %d, y = %d\n", sum->y, sum->y);
  display_links(sum->links);
  return (0);
}

int	display_summits(t_summit **file)
{
  int	i;

  i = 0;
  my_printf(1, 0, "Summits: \n");
  while (file[i] != NULL)
    {
      display_summit(file[i]);
      i += 1;
    }
  return (0);
}

int	display_graph(t_graph *graph)
{
  my_printf(1, 0, "\t\tGraph\nAnts: %d\nSize: %d\n", graph->ants, graph->size);
  display_summits(graph->summits);
  my_printf(1, 0, "Start:\n");
  display_summit(graph->start);
  my_printf(1, 0, "End:\n");
  display_summit(graph->end);
  return (0);
}
