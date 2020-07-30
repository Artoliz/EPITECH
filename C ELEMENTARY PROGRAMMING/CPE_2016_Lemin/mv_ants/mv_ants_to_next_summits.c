/*
** mv_ants_to_next_summits.c for Lem-in in /home/pierre/CPE/CPE_2016_Lemin
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Mon Apr 10 17:28:17 2017 Pierre J. Alderman
** Last update Wed Apr 12 16:41:46 2017 Pierre J. Alderman
*/

#include "../include/lemin.h"

void		mv_ants_to_next_summits(t_graph *info,
					t_link **ants,
					int nb_paths)
{
  int		launched_ants_cnt;
  int		i;

  launched_ants_cnt = 0;
  i = 0;
  while (ants[i])
    {
      if ((ants[i])->summit == info->end)
	(ants[i])->summit = NULL;
      if ((ants[i])->summit == info->start && launched_ants_cnt < nb_paths)
	{
	  (ants[i]) = (ants[i])->prev;
	  ++launched_ants_cnt;
	}
      else if ((ants[i])->summit && (ants[i])->summit != info->start)
	(ants[i]) = (ants[i])->prev;
      ++i;
    }
}
