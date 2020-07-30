/*
** main.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Apr  3 16:51:18 2017 Charles Aubert
** Last update Sat Apr 29 17:43:51 2017 Charles Aubert
*/

#include "./include/lemin.h"

int		main(int argc, char **argv)
{
  t_graph	*graph;

  argv[0] = NULL;
  if (argc != 1)
    return (my_printf(2, 84, "Invalid number of arguments.\n"));
  if ((graph = get_graph()) == NULL)
    return (my_printf(2, 84, "Invalid input.\n"));
  if (my_algo(graph) != 0)
    return (my_printf(2, 84, "\nAn error occured in pathfinding.\n"));
  free_graph(graph);
  return (0);
}
