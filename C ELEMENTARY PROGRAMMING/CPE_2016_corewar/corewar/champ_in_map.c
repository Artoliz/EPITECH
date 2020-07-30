/*
** champ_in_map.c for champ_in_map in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sun Apr  2 12:32:57 2017 Charles Descoust
** Last update Sun Apr  2 15:52:52 2017 Bastien LECUSSAN
*/

#include "inc/vm.h"

t_process	*sort_champ_by_la(t_process* procs, t_var var)
{
  int		i;
  int		la;
  t_process	tmp;

  i = 0;
  la = 0;
  while (i < var.cor)
    {
      if (i + 1 < var.cor &&
	  procs[i].warrior->l_a == procs[i + 1].warrior->l_a &&
	  procs[i].warrior->l_a != 0)
	return (NULL);
      if (i + 1 < var.cor && procs[i].warrior->l_a > procs[i + 1].warrior->l_a)
	{
	  tmp = procs[i];
	  procs[i] = procs[i + 1];
	  procs[i + 1] = tmp;
	}
      i += 1;
    }
  return (procs);
}

int	*add_in_map_la_know(t_process procs, t_var var, int* map)
{
  int	i;
  int	j;

  i = procs.warrior->l_a;
  if (i + procs.warrior->prog_size >= MEM_SIZE)
    return (NULL);
  j = 0;
  procs.PC = i;
  while (j < procs.warrior->prog_size)
    {
      map[i] = procs.warrior->instru[j];
      i += 1;
      j += 1;
    }
  return (map);
}

int	*add_in_map_la_dont_know(t_process procs, t_var var,
				 int* map, t_trash trash)
{
  while (trash.j < MEM_SIZE)
    {
      if (map[trash.j] == 0)
	{
	  trash.k = trash.j;
	  trash.l = 0;
	  while (trash.j < MEM_SIZE && map[trash.j] == 0)
	    {
	      trash.l += 1;
	      trash.j += 1;
	    }
	  if (trash.l >= procs.warrior->prog_size)
	    {
	      procs.warrior->l_a = trash.k;
	      if ((map = add_in_map_la_know(procs, var, map)) == NULL)
		return (NULL);
	      break;
	    }
	}
      trash.j += 1;
    }
  return (map);
}

int	*add_in_map(t_process *procs, t_var var, int *map, t_trash trash)
{
  while (trash.i < var.cor)
    {
      if (procs[trash.i].warrior->l_a != 0)
        {
          if ((map = add_in_map_la_know(procs[trash.i], var, map)) == NULL)
            return (NULL);
        }
      trash.i += 1;
    }
  trash.i = 0;
  while (trash.i < var.cor)
    {
      if (procs[trash.i].warrior->l_a == 0)
        {
          if ((map = add_in_map_la_dont_know(procs[trash.i],
					     var, map, trash)) == NULL)
            return (NULL);
        }
      trash.i += 1;
    }
  return (map);
}

int		*add_champ_in_map(t_process *procs, t_var var, int *map)
{
  t_trash	trash;

  trash.i = 0;
  trash.j = 0;
  trash.k = 0;
  if ((procs = sort_champ_by_la(procs, var)) == NULL)
    return (NULL);
  if (check_overlap(procs, var) == 84)
    return (NULL);
  if ((map = add_in_map(procs, var, map, trash)) == NULL)
    return (NULL);
  procs = sort_champ_by_pn(procs, var);
  return (map);
}
