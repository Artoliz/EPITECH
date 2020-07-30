/*
** corewar.c for corewar in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar 30 13:19:22 2017 Charles Descoust
** Last update Sun Apr  2 15:00:25 2017 Charles Descoust
*/

#include "inc/vm.h"

int	exec_ins(t_process proc, int* map,
		 t_instru* tab, t_var* var)
{
  int	i;
  int	j;

  i = 0;
  while (i < proc.warrior->prog_size)
    {
      j = 0;
      while (tab[j].nst != NULL)
	{
	  if (tab[j].code == proc.warrior->instru[i])
	    {
	      tab[j].nst(map, proc, &i, var);
	      break;
	    }
	  j += 1;
	}
      i += 1;
    }
  return (0);
}

int	how_win(t_process* procs, t_var var)
{
  int	i;

  i = 0;
  while (i < var.cor)
    {
      if (procs[i].warrior->pn == var.idx_live)
	{
	  my_printf("The player %d(%s) has won.\n",
		    procs[i].warrior->pn, procs[i].warrior->prog_name);
	  break;
	}
      i += 1;
    }
  return (0);
}

int	wait_playing(t_process* procs, t_var var)
{
  int	i;

  i = 0;
  while (i < var.cor)
    {
      if (procs[i].cycle > 0)
	procs[i].cycle -= 1;
      i += 1;
    }
  return (0);
}

int	game_loop(t_process* procs, int* map, t_instru* tab, t_var var)
{
  int	idx;

  var.i = CYCLE;
  while (var.i > 0)
    {
      if (var.i == var.dump)
	aff_dump(map);
      if (var.nb_live == NBR_LIVE)
	remove_cycle_delta(&var, map);
      idx = 0;
      while (idx < var.cor)
	{
	  if (procs[idx].cycle == 0)
	    exec_ins(procs[idx], map, tab, &var);
	  idx += 1;
	}
      wait_playing(procs, var);
      var.i -= 1;
    }
  how_win(procs, var);
  return (0);
}

int		corewar(t_header* champ, t_var var)
{
  t_process*	procs;
  int*		map;
  t_instru*	tab;

  if ((map = init_map()) == NULL)
    return (84);
  if ((procs = init_procs(champ, var)) == NULL)
    return (84);
  if ((tab = init_tab_instru()) == NULL)
    return (84);
  if ((map = add_champ_in_map(procs, var, map)) == NULL)
    {
      my_putstr("Overlap detected.\n");
      return (84);
    }
  game_loop(procs, map, tab, var);
  destroy_process_map_tab(procs, var, map, tab);
  return (0);
}
