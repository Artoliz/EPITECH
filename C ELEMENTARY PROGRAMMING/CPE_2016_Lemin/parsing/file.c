/*
** file.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Apr  3 16:54:18 2017 Charles Aubert
** Last update Sat Apr 29 17:49:43 2017 Charles Aubert
*/

#include "../include/lemin.h"

char		*init_graph(t_graph *graph)
{
  char		*line;
  int		type;
  t_link	*s;

  type = MY_NORMAL;
  s = NULL;
  my_printf(1, 0, "#rooms\n");
  while (type != -1 && (line = get_next_line(0)) != NULL && line[0] != '\0')
    {
      if (my_strcmp(line, "##start") == 0)
	type = MY_START;
      else if (my_strcmp(line, "##end") == 0)
	type = MY_END;
      else if (check_def(line) == 0 &&
	       (s = create_link(s, create_summit(line, &type, s))) == NULL)
	return (NULL);
      else if (check_comment(line) != 0 && check_def(line) != 0)
	break;
      free(line);
    }
  if ((graph->summits = get_summits(s)) == NULL)
    return (NULL);
  free_links(s);
  return (line);
}

t_summit	*get_link(t_summit **res, char *name)
{
  int		i;

  i = 0;
  while (res[i] != NULL)
    {
      if (my_strcmp(res[i]->name, name) == 0)
	return (res[i]);
      i += 1;
    }
  return (NULL);
}

t_graph	*link_summits(t_summit **res, char *line, t_graph *graph)
{
  while (line != NULL && line[0] != '\0' &&
	 (check_link(line) == 0 || check_comment(line) == 0))
    {
      if (check_link(line) == 0 && valid_link(line, res) == 0)
	{
	  if ((res = link_summit(line, res)) == NULL)
	    return (NULL);
	}
      else if (check_comment(line) != 0)
	return (graph);
      graph->summits = res;
      line = get_next_line(0);
    }
  return (graph);
}

t_graph	*get_ants(t_graph *graph)
{
  char	*line;
  char	**tab;

  my_printf(1, 0, "#number_of_ants\n");
  if ((line = get_next_line(0)) == NULL ||
      (tab = my_split(line, " \t")) == NULL)
    return (NULL);
  my_printf(1, 0, "%s\n", tab[0]);
  if (size_array((void *)tab) < 1 ||
      my_str_isnum(line) != 0)
    return (NULL);
  if (size_array((void *)tab) > 1 && tab[1][0] != '#')
    return (NULL);
  if ((graph->ants = my_getnbr(tab[0])) <= 0)
    return (NULL);
  graph->paths = graph->ants / 10;
  if (graph->paths == 0)
    graph->paths = 1;
  else if (graph->paths > 10)
    graph->paths = 10;
  free(line);
  free_array_char(tab, 0);
  return (graph);
}

t_graph		*get_graph()
{
  t_graph	*graph;
  char		*line;

  if ((graph = malloc(sizeof(t_graph))) == NULL ||
      (graph = get_ants(graph)) == NULL ||
      (line = init_graph(graph)) == NULL ||
      (graph->start = get_summit_type(graph->summits, MY_START)) == NULL ||
      (graph->end = get_summit_type(graph->summits, MY_END)) == NULL)
    return (NULL);
  my_printf(1, 0, "#tunnels\n");
  if ((graph = link_summits(graph->summits, line, graph)) == NULL)
    return (NULL);
  graph->size = size_array((void *)graph->summits);
  my_printf(1, 0, "#moves");
  return (graph);
}
