/*
** put_ant.c for Lem-in in /home/pierre/CPE/CPE_2016_Lemin/mv_ants
**
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
**
** Started on  Tue Apr 11 14:20:59 2017 Pierre J. Alderman
** Last update Mon Apr 24 21:49:20 2017 Pierre J. Alderman
*/

#include "../include/lemin.h"

int		put_ants(t_link **ants, t_summit *f_summit)
{
  t_link	**f_ant;
  t_link	*p_ant;

  f_ant = ants;
  p_ant = NULL;
  while (*ants)
    {
      if ((*ants)->summit != NULL && (*ants)->summit != f_summit)
	{
	  if (*ants != *f_ant && (p_ant && p_ant->summit != NULL))
	    my_putchar(' ', 1);
	  my_printf(1, 84, "P%d-%s", (int)(ants - f_ant + 1),
		    (*ants)->summit->name);
	}
      p_ant = *ants;
      ++ants;
    }
  my_printf(1, 0, "%c", '\n');
  return (0);
}
