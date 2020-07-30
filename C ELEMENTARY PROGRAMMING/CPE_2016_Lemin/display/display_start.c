/*
** display_start.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Sun Apr  9 10:26:33 2017 Charles Aubert
** Last update Fri Apr 21 10:15:43 2017 Charles Aubert
*/

#include "../include/lemin.h"

int	display_summit_start(t_summit *summit)
{
  if (summit->type == 2)
    my_printf(1, 0, "##end\n");
  else if (summit->type == 1)
    my_printf(1, 0, "##start\n");
  my_printf(1, 0, "%s %d %d\n", summit->name, summit->x, summit->y);
  return (0);
}

int	display_start(t_graph *graph)
{
  int	i;

  i = 0;
  if (graph->start == NULL || graph->end == NULL ||
      graph->summits == NULL)
    return (0);
  my_printf(1, 0, "#number_of_ants\n%d\n", graph->ants);
  my_printf(1, 0, "#rooms\n");
  while (graph->summits[i] != NULL)
    i += 1;
  i -= 1;
  while (i >= 0)
    {
      display_summit_start(graph->summits[i]);
      i -= 1;
    }
  return (0);
}
