/*
** prog_number.c for prog_number in /home/descou_c/CPE/corewar_vm
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Mar 24 11:16:37 2017 Charles Descoust
** Last update Sun Apr  2 13:59:04 2017 Charles Descoust
*/

#include "inc/vm.h"

int	check_tab_number(int *tab, t_var* var)
{
  int	i;
  int	j;
  int	tmp;

  i = 0;
  while (i < var->cor)
    {
      if (tab[i] != 0)
        {
          tmp = tab[i];
	  j = 0;
          while (j < var->cor)
            {
              if (tmp == tab[j] && j != i)
                return (84);
              j += 1;
            }
        }
      i += 1;
    }
  return (0);
}

int	*init_tab_prog_number(t_header** champ, t_var* var)
{
  int	*tab;
  int	i;

  if ((tab = malloc(sizeof(int) * var->cor)) == NULL)
    return (NULL);
  i = 0;
  while (i < var->cor)
    {
      tab[i] = (*champ)[i].pn;
      i += 1;
    }
  if (check_tab_number(tab, var) == 84)
    return (NULL);
  return (tab);
}

int	insert_prog_number(t_header ** champ, t_var* var, int *tab, int pn)
{
  int	i;
  int	j;

  i = 0;
  while (i < var->cor)
    {
      if ((*champ)[i].pn == 0)
        {
          j = 0;
          while (j < var->cor)
            {
              if (tab[j] == pn)
                {
                  pn = pn + 1;
                  j = 0;
                }
              else
                j = j + 1;
            }
          (*champ)[i].pn = pn;
          tab[i] = pn;
        }
      i += 1;
    }
  return (0);
}

int	add_prog_number(t_header **champ, t_var *var)
{
  int   pn;
  int	*tab;

  if ((tab = init_tab_prog_number(champ, var)) == NULL)
    return (84);
  pn = 1;
  insert_prog_number(champ, var, tab, pn);
  free(tab);
  return (0);
}

t_process	*sort_champ_by_pn(t_process* procs, t_var var)
{
  int           i;
  int           la;
  t_process     tmp;

  i = 0;
  la = 0;
  while (i < var.cor)
    {
      if (i + 1 < var.cor && procs[i].warrior->pn > procs[i + 1].warrior->pn)
        {
          tmp = procs[i];
          procs[i] = procs[i + 1];
          procs[i + 1] = tmp;
        }
      i += 1;
    }
  return (procs);
}
