/*
** algo.c for  in /home/miklox/semestre2/c_prog_elem/CPE_2016_Lemin
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Sun Apr 16 19:01:58 2017 Bastien LECUSSAN
** Last update Sat Apr 29 20:48:02 2017 Bastien LECUSSAN
*/

#include "../include/lemin.h"

t_path		*reverse_path(t_path *path)
{
  t_path	*tmp;
  t_path	*save;

  if (path->next != NULL)
    {
      tmp = path;
      path = path->next;
      tmp->next = NULL;
      save = tmp;
      while (path->next != NULL)
	{
	  tmp = path;
	  path = path->next;
	  tmp->next = save;
	  save = tmp;
	}
      path->next = save;
    }
  return (path);
}

t_link		*delete_summits_end(t_link **tmp, t_link *list,
				    t_link *to_delete, int *count)
{
  if (list->summit == to_delete->summit)
    {
      tmp[0]->next = list->next;
      list = list->next;
    }
  else
    {
      *tmp = list;
      list = list->next;
    }
  *count = 1;
  return (list);
}

void		free_path(t_path *path)
{
  t_path	*tmp;

  while (path != NULL)
    {
      tmp = path;
      free_links(path->path);
      path = path->next;
      free(tmp);
    }
}
