/*
** algo_start.c for  in /home/miklox/semestre2/c_prog_elem/CPE_2016_Lemin/algo
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Sun Apr 16 17:50:19 2017 Bastien LECUSSAN
** Last update Sat Apr 29 20:46:27 2017 Bastien LECUSSAN
*/

#include "../include/lemin.h"

t_link		*delete_summits(t_link *list, t_link *to_delete)
{
  t_link	*save;
  t_link	*tmp;
  int		count;

  count = 0;
  save = list;
  while (list != NULL)
    {
      if (count == 0 && list->summit == to_delete->summit)
	{
	  save = list->next;
	  list = save;
	  tmp = list;
	  count = 1;
	}
      else
	list = delete_summits_end(&tmp, list, to_delete, &count);
    }
  list = save;
  return (list);
}

t_graph		*delete_summit_links(t_search search, t_graph *graph)
{
  int		count;
  t_link	*save;

  count = 0;
  while (graph->summits[count] != NULL)
    {
      save = search.path;
      while (save != NULL)
	{
	  if (save->summit->type == 0)
	    {
	      graph->summits[count]->links
		= delete_summits(graph->summits[count]->links, save);
	    }
	  save = save->prev;
	}
      count += 1;
    }
  return (graph);
}

int		get_size_of_path(t_link *path)
{
  int		size;
  t_link	*tmp;

  size = 0;
  tmp = path;
  while (tmp != NULL)
    {
      size += 1;
      tmp = tmp->prev;
    }
  return (size);
}

t_path		*my_pathfinding(t_graph *graph)
{
  t_path	*path;
  t_path	*tmp;
  t_search	search;
  int		i;

  i = 0;
  tmp = NULL;
  path = NULL;
  while ((search = init_search(graph->start, graph->end,
			       graph->size)).start != NULL && i < graph->paths)
    {
      if ((path = malloc(sizeof(*path))) == NULL)
	return (NULL);
      path->path = search.path;
      path->size = get_size_of_path(search.path);
      path->next = tmp;
      tmp = path;
      graph = delete_summit_links(search, graph);
      i += 1;
    }
  return (path);
}

int		my_algo(t_graph *graph)
{
  t_path	*path;

  if ((path = my_pathfinding(graph)) == NULL)
    return (84);
  path = reverse_path(path);
  mv_ants(graph, path);
  free_path(path);
  return (0);
}
