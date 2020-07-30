/*
** instructions_4.c for instructions_4 in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar 30 18:00:21 2017 Charles Descoust
** Last update Sun Apr  2 15:03:53 2017 Charles Descoust
*/

#include "inc/vm.h"

void	aff_ft(int* map, t_process proc, int* i, t_var* var)
{
  proc.cycle = 2;
  *i = *i + 1;
  my_printf("%c\n", proc.warrior->instru[*i] % 256);
}
