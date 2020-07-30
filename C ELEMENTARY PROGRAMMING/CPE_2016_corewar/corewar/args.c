/*
** args.c for args in /home/descou_c/CPE/corewar_vm
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Mar 13 18:05:57 2017 Charles Descoust
** Last update Sun Apr  2 13:16:06 2017 Charles Descoust
*/

#include "inc/vm.h"

int	check_dump(char** av, int *i, t_var *var)
{
  if (av[*i + 1] == NULL)
    exit_error("-dump argument doesn't exist.\n");
  *i = *i + 1;
  if (my_str_isnum(av[*i]) == 1)
    exit_error("-dump argument is invalid. Please enter a positive number.\n");
  var->dump += 1;
  if (var->dump > 1)
    exit_error("Double definition of option dump.\n");
  return (0);
}

int	check_prog_number(char** av, int *i, t_var *var)
{
  int	nb;

  if (av[*i + 1] == NULL)
    exit_error("-n argument doesn't exist.\n");
  *i = *i + 1;
  if (my_str_isnum(av[*i]) == 1)
    exit_error("-n argument is invalid.\nEnter a number between 1 and 4.\n");
  nb = my_getnbr(av[*i]);
  if (nb < 1 || nb > 4)
    exit_error("-n argument is invalid.\nEnter a number between 1 and 4.\n");
  if (av[*i + 1] != NULL && CMP(av[*i + 1], "-n") == 0)
    exit_error("Invalid option.\n");
  var->pn += 1;
  return (0);
}

int	check_load_address(char** av, int *i, t_var *var)
{
  int	nb;

  if (av[*i + 1] == NULL)
    exit_error("-a argument doesn't exist.\n");
  *i = *i + 1;
  if (my_str_isnum(av[*i]) == 1)
    exit_error("-a argument is invalid.\nEnter a valid memory offset.\n");
  nb = my_getnbr(av[*i]);
  if (nb < 0)
    exit_error("-a argument is invalid.\nEnter a valid memory offset.\n");
  var->la += 1;
  if (av[*i + 1] != NULL && CMP(av[*i + 1], "-a") == 0)
    exit_error("Invalid option.\n");
  return (0);
}

int	what_options(char **av, t_options *tab, int *i, t_var* var)
{
  int	j;

  j = 0;
  while (j < 3)
    {
      if (CMP(av[*i], tab[j].name) == 0)
	tab[j].ft(av, i, var);
      j = j + 1;
    }
  return (0);
}

int		check_args(int ac, char **av, t_var* var)
{
  int		i;
  t_options	tab[]=
    {
      {"-dump", check_dump, NULL},
      {"-n", check_prog_number, NULL},
      {"-a", check_load_address, NULL},
    };

  i = 1;
  while (i < ac)
    {
      if (av[i][0] == '-' && (CMP(av[i], "-dump") == 0 ||
			      CMP(av[i], "-n") == 0 || CMP(av[i], "-a") == 0))
	what_options(av, tab, &i, var);
      else
	check_files(av[i], &var);
      i = i + 1;
    }
  if (var->cor > 1)
    return (0);
  else
    return (84);
}
