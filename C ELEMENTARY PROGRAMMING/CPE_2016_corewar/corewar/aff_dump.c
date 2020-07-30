/*
** aff_dump.c for aff_dump in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sun Apr  2 14:02:55 2017 Charles Descoust
** Last update Sun Apr  2 14:23:30 2017 Charles Descoust
*/

#include "inc/vm.h"

void	aff_dump(int *map)
{
  int	i;
  int	j;

  i = 0;
  while (i < MEM_SIZE)
    {
      if (i == 0)
	my_printf("0\t:");
      else
	my_printf("%X\t:", i);
      j = i;
      while ((j < i + 32) && j < MEM_SIZE)
	{
	  if (map[j] == 0)
	    my_printf(" 0");
	  else
	    my_printf(" %X", map[j]);
	  j += 1;
	}
      my_printf("\n");
      i += 32;
    }
}

int	remove_cycle_delta(t_var *var, int* map)
{
  int	tmp;

  var->nb_live = 0;
  tmp = var->i - CYCLE_DELTA;
  while (var->i >= tmp)
    {
      if (var->i == var->dump)
	aff_dump(map);
      var->i -= 1;
    }
  return (0);
}
