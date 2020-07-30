/*
** destroy.c for destroy in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar 30 15:53:03 2017 Charles Descoust
** Last update Thu Mar 30 16:46:14 2017 Charles Descoust
*/

#include "inc/vm.h"

int	destroy_champ(t_header* champ, t_var var)
{
  int   i;

  i = 0;
  while (i < var.cor)
    {
      free(champ[i].instru);
      i += 1;
    }
  free(champ);
  return (0);
}

void	destroy_process_map_tab(t_process* procs, t_var var,
				int* map, t_instru* tab)
{
  int   i;

  i = 0;
  while (i < var.cor)
    {
      free(procs[i].reg);
      i += 1;
    }
  free(tab);
  free(map);
  free(procs);
}
