/*
** instructions_3.c for instructions_3 in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar 30 15:47:10 2017 Charles Descoust
** Last update Sun Apr  2 15:38:31 2017 Charles Descoust
*/

#include "inc/vm.h"

void	sti_ft(int* map, t_process proc, int* i, t_var *var)
{
  int	reg;
  int	res1;
  int	res2;
  int	*type;

  proc.cycle = 25;
  *i += 1;
  type = convert_chain_binar(decimal_to_binar(proc.warrior->instru[*i]));
  *i += 1;
  reg = proc.warrior->instru[*i];
  *i += 1;
  if (type[1] == DIR_SIZE)
    res1 = convert(i, proc, IND_SIZE);
  else
    res1 = proc.reg[proc.warrior->instru[*i] - 1];
  *i += 1;
  if (type[2] == DIR_SIZE)
    res2 = convert(i, proc, IND_SIZE);
  else
    res2 = proc.reg[proc.warrior->instru[*i] - 1];
  map[proc.PC + (res1 + res2) % IDX_MOD] = proc.reg[reg - 1];
}

void		fork_ft(int* map, t_process proc, int* i, t_var *var)
{
  int		res;
  t_process	child;

  child = proc;
  proc.cycle = 800;
  *i += 1;
  res = convert(i, proc, IND_SIZE);
  map[proc.PC + res % IDX_MOD] = child.PC;
}

void	lld_ft(int* map, t_process proc, int* i, t_var *var)
{
  int	res;
  int	reg;
  int	*type;

  proc.cycle = 10;
  *i += 1;
  type = convert_chain_binar(decimal_to_binar(proc.warrior->instru[*i]));
  *i += 1;
  res = convert(i, proc, type[0]);
  *i += 1;
  reg = proc.warrior->instru[*i];
  proc.reg[reg - 1] = proc.PC + res;
  if (proc.reg[reg - 1] == 0)
    proc.carry = 1;
  else
    proc.carry = 0;
}

void	lldi_ft(int* map, t_process proc, int* i, t_var *var)
{
  int	res1;
  int	res2;
  int	reg;
  int	*type;

  proc.cycle = 50;
  *i += 1;
  type = convert_chain_binar(decimal_to_binar(proc.warrior->instru[*i]));
  *i += 1;
  res1 = convert(i, proc, type[0]);
  *i += 1;
  res2 = convert(i, proc, type[1]);
  *i += 1;
  reg = proc.warrior->instru[*i];
  map[proc.PC + res1] += res2;
  proc.reg[reg - 1] = map[proc.PC + res1];
  if (proc.reg[reg - 1] == 0)
    proc.carry = 1;
  else
    proc.carry = 0;
}

void		lfork_ft(int* map, t_process proc, int* i, t_var *var)
{
  int		res;
  t_process	child;

  child = proc;
  proc.cycle = 1000;
  *i += 1;
  res = convert(i, proc, IND_SIZE);
  map[proc.PC + res] = child.PC;
}
