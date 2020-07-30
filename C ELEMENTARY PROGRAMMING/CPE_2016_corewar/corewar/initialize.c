/*
** utils_corewar.c for utils_corewar in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar 30 13:34:08 2017 Charles Descoust
** Last update Sun Apr  2 14:53:03 2017 Charles Descoust
*/

#include "inc/vm.h"

t_instru	*init_tab_ptr_ft(t_instru* tab)
{
  tab[0].nst = live_ft;
  tab[1].nst = ld_ft;
  tab[2].nst = st_ft;
  tab[3].nst = add_ft;
  tab[4].nst = sub_ft;
  tab[5].nst = and_ft;
  tab[6].nst = or_ft;
  tab[7].nst = xor_ft;
  tab[8].nst = zjmp_ft;
  tab[9].nst = ldi_ft;
  tab[10].nst = sti_ft;
  tab[11].nst = fork_ft;
  tab[12].nst = lld_ft;
  tab[13].nst = lldi_ft;
  tab[14].nst = lfork_ft;
  tab[15].nst = aff_ft;
  tab[16].nst = NULL;
  return (tab);
}

t_instru	*init_tab_instru()
{
  t_instru*	tab;

  if ((tab = malloc(sizeof(t_instru) * 17)) == NULL)
    return (NULL);
  tab[0].code = 0x01;
  tab[1].code = 0x02;
  tab[2].code = 0x03;
  tab[3].code = 0x04;
  tab[4].code = 0x05;
  tab[5].code = 0x06;
  tab[6].code = 0x07;
  tab[7].code = 0x08;
  tab[8].code = 0x09;
  tab[9].code = 0x0a;
  tab[10].code = 0x0b;
  tab[11].code = 0x0c;
  tab[12].code = 0x0d;
  tab[13].code = 0x0e;
  tab[14].code = 0x0f;
  tab[15].code = 0x10;
  tab[16].code = 0x00;
  tab = init_tab_ptr_ft(tab);
  return (tab);
}

int	*init_map()
{
  int*	map;
  int	i;

  if ((map = malloc(sizeof(int) * MEM_SIZE)) == NULL)
    return (NULL);
  i = 0;
  while (i < MEM_SIZE)
    {
      map[i] = 0;
      i += 1;
    }
  return (map);
}

int	*init_registers(int* reg, int pn)
{
  int   i;

  i = 1;
  if ((reg = malloc(sizeof(int) * REG_NUMBER)) == NULL)
    return (NULL);
  reg[0] = pn;
  while (i < REG_NUMBER)
    {
      reg[i] = 0;
      i += 1;
    }
  return (reg);
}

t_process*	init_procs(t_header* champ, t_var var)
{
  t_process*    procs;
  int           i;

  i = 0;
  if ((procs = malloc(sizeof(t_process) * var.cor)) == NULL)
    return (NULL);
  while (i < var.cor)
    {
      procs[i].cycle = 0;
      procs[i].carry = 0;
      procs[i].reg = init_registers(procs[i].reg, champ[i].pn);
      procs[i].warrior = &champ[i];
      i += 1;
    }
  return (procs);
}
