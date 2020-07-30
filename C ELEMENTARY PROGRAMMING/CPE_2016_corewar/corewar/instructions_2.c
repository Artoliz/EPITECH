/*
** instructions_2.c for instructions_2 in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar 30 15:45:49 2017 Charles Descoust
** Last update Sun Apr  2 15:37:36 2017 Charles Descoust
*/

#include "inc/vm.h"

void		and_ft(int* map, t_process proc, int* i, t_var* var)
{
  int		res1;
  int		res2;
  int		reg;
  int		*type;

  proc.cycle = 6;
  *i += 1;
  type = convert_chain_binar(decimal_to_binar(proc.warrior->instru[*i]));
  *i += 1;
  if (type[0] == REG_SIZE)
    res1 = proc.reg[proc.warrior->instru[*i] - 1];
  else
    res1 = convert(i, proc, type[0]);
  *i += 1;
  if (type[1] == REG_SIZE)
    res2 = proc.reg[proc.warrior->instru[*i] - 1];
  else
    res2 = convert(i, proc, type[1]);
  *i += 1;
  reg = proc.warrior->instru[*i];
  proc.reg[reg - 1] = res1 & res2;
  if (proc.reg[reg - 1] == 0)
    proc.carry = 1;
  else
    proc.carry = 0;
}

void		or_ft(int* map, t_process proc, int* i, t_var *var)
{
  int           res1;
  int           res2;
  int           reg;
  int		*type;

  proc.cycle = 6;
  *i += 1;
  type = convert_chain_binar(decimal_to_binar(proc.warrior->instru[*i]));
  *i += 1;
  if (type[0] == REG_SIZE)
    res1 = proc.reg[proc.warrior->instru[*i] - 1];
  else
    res1 = convert(i, proc, type[0]);
  *i += 1;
  if (type[1] == REG_SIZE)
    res2 = proc.reg[proc.warrior->instru[*i] - 1];
  else
    res2 = convert(i, proc, type[1]);
  *i += 1;
  reg = proc.warrior->instru[*i];
  proc.reg[reg - 1] = res1 | res2;
  if (proc.reg[reg - 1] == 0)
    proc.carry = 1;
  else
    proc.carry = 0;
}

void		xor_ft(int* map, t_process proc, int* i, t_var *var)
{
  int           res1;
  int           res2;
  int           reg;
  int           *type;

  proc.cycle = 6;
  *i += 1;
  type = convert_chain_binar(decimal_to_binar(proc.warrior->instru[*i]));
  *i += 1;
  if (type[0] == REG_SIZE)
    res1 = proc.reg[proc.warrior->instru[*i] - 1];
  else
    res1 = convert(i, proc, type[0]);
  *i += 1;
  if (type[1] == REG_SIZE)
    res2 = proc.reg[proc.warrior->instru[*i] - 1];
  else
    res2 = convert(i, proc, type[1]);
  *i += 1;
  reg = proc.warrior->instru[*i];
  proc.reg[reg - 1] = res1 ^ res2;
  if (proc.reg[reg - 1] == 0)
    proc.carry = 1;
  else
    proc.carry = 0;
}

void	zjmp_ft(int* map, t_process proc, int* i, t_var *var)
{
  int	res;

  proc.cycle = 20;
  *i += 1;
  if (proc.carry == 1)
    {
      res = convert(i, proc, IND_SIZE);
      proc.PC = proc.PC + res % IDX_MOD;
    }
}

void	ldi_ft(int* map, t_process proc, int* i, t_var *var)
{
  int   res1;
  int   res2;
  int   reg;

  proc.cycle = 25;
  *i += 2;
  res1 = convert(i, proc, IND_SIZE);
  *i += 1;
  res2 = convert(i, proc, IND_SIZE);
  *i += 1;
  reg = proc.warrior->instru[*i];
  map[proc.PC + res1 % IDX_MOD] += res2;
  proc.reg[reg - 1] = map[proc.PC + res1 % IDX_MOD];
  if (proc.reg[reg - 1] == 0)
    proc.carry = 1;
  else
    proc.carry = 0;
}
