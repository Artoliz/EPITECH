/*
** instructions.c for instructions in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar 30 15:44:48 2017 Charles Descoust
** Last update Sun Apr  2 15:38:57 2017 Charles Descoust
*/

#include "inc/vm.h"

void	live_ft(int* map, t_process proc, int* i, t_var *var)
{
  proc.cycle = 10;
  *i = *i + DIR_SIZE;
  var->nb_live += 1;
  my_printf("The player %d(%s) is alive.\n",
  	    proc.warrior->pn, proc.warrior->prog_name);
  var->idx_live = proc.warrior->pn;
}

void		ld_ft(int* map, t_process proc, int* i, t_var *var)
{
  int		res;
  int		reg;
  int		*type;

  proc.cycle = 5;
  *i += 1;
  type = convert_chain_binar(decimal_to_binar(proc.warrior->instru[*i]));
  *i += 1;
  res = convert(i, proc, type[0]);
  *i += 1;
  reg = proc.warrior->instru[*i];
  proc.reg[reg - 1] = proc.PC + (res % IDX_MOD);
  if (proc.reg[reg - 1] == 0)
    proc.carry = 1;
  else
    proc.carry = 0;
}

void		st_ft(int* map, t_process proc, int* i, t_var *var)
{
  int		reg;
  int		res;
  int		*type;

  proc.cycle = 5;
  *i += 1;
  type = convert_chain_binar(decimal_to_binar(proc.warrior->instru[*i]));
  *i += 1;
  reg = proc.warrior->instru[*i];
  *i += 1;
  if (type[1] == REG_SIZE)
    {
      res = proc.warrior->instru[*i];
      proc.reg[res - 1] = proc.reg[reg - 1];
    }
  else
    {
      res = convert(i, proc, type[1]);
      map[proc.PC + (res % IDX_MOD)] = proc.reg[reg - 1];
    }
}

void	add_ft(int* map, t_process proc, int* i, t_var *var)
{
  int	reg1;
  int	reg2;
  int	reg3;

  proc.cycle = 10;
  *i += 2;
  reg1 = proc.warrior->instru[*i];
  *i += 1;
  reg2 = proc.warrior->instru[*i];
  *i += 1;
  reg3 = proc.warrior->instru[*i];
  proc.reg[reg3 - 1] = proc.reg[reg1 - 1] + proc.reg[reg2 - 1];
  if (proc.reg[reg3 - 1] == 0)
    proc.carry = 1;
  else
    proc.carry = 0;
}

void	sub_ft(int* map, t_process proc, int* i, t_var* var)
{
  int   reg1;
  int   reg2;
  int   reg3;

  proc.cycle = 10;
  *i += 2;
  reg1 = proc.warrior->instru[*i];
  *i += 1;
  reg2 = proc.warrior->instru[*i];
  *i += 1;
  reg3 = proc.warrior->instru[*i];
  proc.reg[reg3 - 1] = proc.reg[reg1 - 1] - proc.reg[reg2 - 1];
  if (proc.reg[reg3 - 1] == 0)
    proc.carry = 1;
  else
    proc.carry = 0;
}
