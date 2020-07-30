/*
** mv_ants.c for Lem-in in /home/pierre/CPE/CPE_2016_Lemin
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Mon Apr 10 16:09:27 2017 Pierre J. Alderman
** Last update Tue Apr 18 18:33:51 2017 Pierre J. Alderman
*/

#include "../include/lemin.h"

static t_link	**init_ants(int nb_ants, t_path *paths)
{
  t_link	**ants;
  t_path	*f_path;
  int		ants_it;

  ants = malloc(sizeof(*ants) * (nb_ants + 1));
  if (!ants)
    return (NULL);
  f_path = paths;
  ants_it = 0;
  while (ants_it < nb_ants)
    {
      ants[ants_it] = link_dup(paths->path);
      paths = (paths->next ? paths->next : f_path);
      ++ants_it;
    }
  ants[ants_it] = NULL;
  return (ants);
}

static int	check_end(t_link **ants)
{
  while (*ants)
    {
      if ((*ants)->summit || (*ants)->summit)
	return (0);
      ++ants;
    }
  return (1);
}

static int	get_nb_paths(t_path *paths)
{
  int	i;

  i = 0;
  while (paths)
    {
      paths = paths->next;
      ++i;
    }
  return (i);
}

int	mv_ants(t_graph *infos, t_path *paths)
{
  t_link	**ants;
  int		nb_paths;

  ants = init_ants(infos->ants, paths);
  nb_paths = get_nb_paths(paths);
  if (!ants)
    return (-1);
  while (!check_end(ants))
    {
      put_ants(ants, infos->start);
      mv_ants_to_next_summits(infos, ants, nb_paths);
    }
  kill_ants(ants);
  return (0);
}
