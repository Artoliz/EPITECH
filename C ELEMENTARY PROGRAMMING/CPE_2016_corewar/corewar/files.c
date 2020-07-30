/*
** files.c for files in /home/descou_c/CPE/corewar_vm
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Mar 13 19:05:03 2017 Charles Descoust
** Last update Sat Apr  1 17:57:57 2017 Charles Descoust
*/

#include "inc/vm.h"

t_header	*init_champ(t_var var)
{
  t_header	*champ;
  int		i;

  i = 0;
  if ((champ = malloc(sizeof(t_header) * var.cor)) == NULL)
    return (NULL);
  while (i < var.cor)
    {
      champ[i].magic = 0;
      champ[i].pn = 0;
      champ[i].l_a = 0;
      champ[i].prog_size = 0;
      champ[i].instru = NULL;
      i = i + 1;
    }
  return (champ);
}

t_options	*init_tab()
{
  t_options	*tab;

  if ((tab = malloc(sizeof(t_options) * 4)) == NULL)
    return (NULL);
  tab[0].name = "-dump";
  tab[0].ft = NULL;
  tab[0].cp = init_dump;
  tab[1].name = "-n";
  tab[1].ft = NULL;
  tab[1].cp = init_nb;
  tab[2].name = "-a";
  tab[2].ft = NULL;
  tab[2].cp = init_address;
  tab[3].name = "r";
  tab[3].ft = NULL;
  tab[3].cp = init_champion;
  return (tab);
}

int	check_param(char **av, t_var *var,
		    t_header** champ, t_options* tab)
{
  int	j;
  int	ac;

  ac = var->cor + var->pn*2 + var->la*2 + var->dump*2 + 1;
  while (var->i < ac)
    {
      j = 0;
      while (j < 4)
  	{
  	  if (CMP(av[var->i], tab[j].name) == 0 ||
	      av[var->i][LEN(av[var->i]) - 1] == tab[j].name[0])
  	    {
  	      if (tab[j].cp(var, champ, av) == 84)
  		return (84);
	      break;
  	    }
  	  j = j + 1;
  	}
      var->i = var->i + 1;
    }
  if (add_prog_number(champ, var) == 84)
    return (84);
  return (0);
}

int	check_files(char *name, t_var** var)
{
  int	fd;
  char	buff[124];

  if ((fd = open(name, O_RDWR)) == -1)
    exit_error("Invalid option.\n");
  if (name[LEN(name) - 1] == 'r' && name[LEN(name) - 2] == 'o' &&
      name[LEN(name) - 3] == 'c' && name[LEN(name) - 4] == '.')
    {
      if (read(fd, buff, 123) == -1)
	exit_error("Error: Read file.\n");
      if (buff == '\0')
	exit_error("Error: Empty file.\n");
      if (close(fd) == -1)
	exit_error("Error: Close file.\n");
      (*var)->cor += 1;
      if ((*var)->cor > 4)
	exit_error("The number of champion load is above the limit.\n");
    }
  else
    exit_error("Invalid file.\n");
  return (0);
}
