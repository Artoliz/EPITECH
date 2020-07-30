/*
** main.c for main in /home/descou_c/CPE/corewar_vm
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Mar 13 13:56:08 2017 Charles Descoust
** Last update Sat Apr  1 17:59:22 2017 Charles Descoust
*/

#include "inc/vm.h"

int		main(int ac, char** av)
{
  t_var		var;
  t_header	*champ;
  t_options	*tab;

  if (ac == 1)
    return (aff_usage(av[0]));
  if (check_help(ac, av) == 0)
    return (0);
  var = init_var();
  if (check_args(ac, av, &var) == 84)
    return (aff_usage(av[0]));
  if ((champ = init_champ(var)) == NULL)
    return (84);
  if ((tab = init_tab()) == NULL)
    return (84);
  if (check_param(av, &var, &champ, tab) == 84)
    return (aff_usage(av[0]));
  if (corewar(champ, var) == 84)
    return (84);
  destroy_champ(champ, var);
  free(tab);
  return (0);
}
