/*
** utils.c for utils in /home/descou_c/CPE/corewar_vm
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Mar 15 13:08:39 2017 Charles Descoust
** Last update Thu Mar 30 17:37:05 2017 Charles Descoust
*/

#include "inc/vm.h"

void	exit_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(84);
}

int	aff_info(char *bin)
{
  my_printf("USAGE\n\t%s [-dump nbr_cycle] [[-n prog_number] ", bin);
  my_printf("[-a load_address] prog_name] ...\n\nDESCRIPTION\n\t");
  my_printf("-dump nbr_cycle\tdumps the memory after the nbr_cycle execution");
  my_printf(" (if the round isn't\n\t\t\talready over) with the following ");
  my_printf("format: 32 bytes/line in\n\t\t\thexadecimal (A0BCDEFE1DD3...)\n");
  my_printf("\t-n prog_number\tsets the next program's number. By default, ");
  my_printf("the first free number\n\t\t\tin the parameter order\n\t-a ");
  my_printf("load_address\tsets the next program's loading address. ");
  my_printf("When no address is\n\t\t\tspecified, optimize the addresses ");
  my_printf("so that the processes are as far\n\t\t\taway from each other");
  my_printf(" as possible. The addresses are MEM_SIZE modulo\n");
  return (0);
}

int	check_help(int ac, char **av)
{
  int   i;

  i = 0;
  while (i < ac)
    {
      if (CMP(av[i], "-h") == 0 || CMP(av[i], "--help") == 0)
        return (aff_info(av[0]));
      i += 1;
    }
  return (1);
}

int	aff_usage(char *bin)
{
  my_printf("Usage: %s [-dump nbr_cycle] [[-n prog_number] ", bin);
  my_printf("[-a load_address] prog_name]...\nTry %s -h for more", bin);
  my_printf(" information.\n");
  return (84);
}

t_var	init_var()
{
  t_var	var;

  var.dump = 0;
  var.pn = 0;
  var.la = 0;
  var.cor = 0;
  var.i = 1;
  var.j = 0;
  var.nb_live = 0;
  var.idx_live = 0;
  return (var);
}
