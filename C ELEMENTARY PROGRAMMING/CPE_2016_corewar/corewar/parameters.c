/*
** parameters.c for parameters in /home/descou_c/CPE/corewar_vm
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Mar 15 14:32:56 2017 Charles Descoust
** Last update Tue Mar 28 09:49:15 2017 Charles Descoust
*/

#include "inc/vm.h"

int	check_header_size(t_var* var, t_header **champ, char** av)
{
  int	head_len;
  int	name_len;
  int	comt_len;
  int	fd;
  int	bytes;
  char	buf;

  head_len = 0;
  bytes = 0;
  if ((fd = open(av[var->i], O_RDONLY)) == -1)
    return (84);
  while (read(fd, &buf, 1) > 0)
    bytes += 1;
  if (close(fd) == -1)
    return (84);
  name_len = PROG_NAME_LENGTH + 1;
  while (name_len % 4 != 0)
    name_len += 1;
  comt_len = COMMENT_LENGTH + 1;
  while (comt_len % 4 != 0)
    comt_len += 1;
  head_len = bytes - (comt_len + name_len + 8);
  if (head_len != (*champ)[var->j].prog_size)
    exit_error("Wrong program size in the header\n");
  return (0);
}

int	init_champion(t_var *var, t_header **champ, char **av)
{
  int	fd;

  if ((fd = open(av[var->i], O_RDONLY)) == -1)
    return (84);
  if (check_exec_magic(fd) == 84)
    return (84);
  if (add_prog_name(champ, fd, var) == 84)
    return (84);
  if (add_size(champ, fd, var) == 84)
    return (84);
  if (add_comment(champ, fd, var) == 84)
    return (84);
  if (add_instructions(champ, fd, var) == 84)
    return (84);
  if (close(fd) == -1)
    return (84);
  if (check_header_size(var, champ, av) == 84)
    return (84);
  var->j = var->j + 1;
  return (0);
}

int	init_dump(t_var *var, t_header **champ, char **av)
{
  int	nb;

  champ = champ;
  var->i += 1;
  nb = my_getnbr(av[var->i]);
  if (nb < 0)
    exit_error("-dump argument is invalid. Please enter a positive number.\n");
  var->dump = nb;
  return (0);
}

int	init_nb(t_var *var, t_header **champ, char **av)
{
  int	nb;

  var->i += 1;
  nb = my_getnbr(av[var->i]);
  if (av[var->i + 1] != NULL && CMP(av[var->i + 1], "-a") == 0)
    {
      var->i += 1;
      init_address(var, champ, av);
    }
  if (av[var->i + 1] != NULL && av[var->i + 1][LEN(av[var->i + 1]) - 1] == 'r')
    {
      (*champ)[var->j].pn = nb;
      var->i += 1;
      if (init_champion(var, champ, av) == 84)
	return (84);
    }
  return (0);
}

int	init_address(t_var *var, t_header **champ, char **av)
{
  int	nb;

  var->i += 1;
  nb = my_getnbr(av[var->i]);
  if (nb < 0)
    exit_error("-a argument is invalid.\nEnter a valid memory offset.\n");
  if (av[var->i + 1] != NULL && CMP(av[var->i + 1], "-n") == 0)
    {
      (*champ)[var->j].l_a = nb;
      var->i += 1;
      init_nb(var, champ, av);
    }
  if (av[var->i + 1] != NULL && av[var->i + 1][LEN(av[var->i + 1]) - 1] == 'r')
    (*champ)[var->j].l_a = nb;
  var->la = nb;
  return (0);
}
