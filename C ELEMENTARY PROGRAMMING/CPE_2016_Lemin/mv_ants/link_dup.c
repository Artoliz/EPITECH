/*
** link_dup.c for Lem-in in /home/pierre/CPE/CPE_2016_Lemin/mv_ants
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue Apr 11 16:36:53 2017 Pierre J. Alderman
** Last update Wed Apr 12 16:52:37 2017 Pierre J. Alderman
*/

#include "../include/lemin.h"

t_link		*link_dup(t_link *src)
{
  t_link	*dup;
  t_link	*s_dup;
  t_link	*tmp_dup;

  tmp_dup = NULL;
  while (src)
    {
      dup = my_memndup(src, sizeof(*src));
      dup->next = tmp_dup;
      if (tmp_dup)
	tmp_dup->prev = dup;
      else
	s_dup = dup;
      tmp_dup = dup;
      src = src->prev;
    }
  dup->prev = NULL;
  return (s_dup);
}
