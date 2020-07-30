/*
** kill_ants.c for Lem-in in /home/pierre/CPE/CPE_2016_Lemin/mv_ants
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue Apr 18 18:23:50 2017 Pierre J. Alderman
** Last update Tue Apr 18 18:31:43 2017 Pierre J. Alderman
*/

#include "../include/lemin.h"

static void	kill_ant(t_link *ant)
{
  t_link	*tmp_ant;

  while (ant)
    {
      tmp_ant = ant;
      ant = ant->next;
      do_free((void **)&tmp_ant);
    }
}

void	kill_ants(t_link **ants)
{
  int	i;

  i = 0;
  while (ants[i])
    {
      kill_ant(ants[i]);
      ++i;
    }
  do_free((void *)&ants);
}
