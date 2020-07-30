/*
** champions.c for champions in /home/descou_c/CPE/corewar_vm
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Mar 15 15:50:41 2017 Charles Descoust
** Last update Tue Mar 28 09:05:24 2017 Charles Descoust
*/

#include "inc/vm.h"

int		check_exec_magic(int fd)
{
  int		i;
  unsigned char	nb;
  int		*tab;

  i = 0;
  nb = 0;
  if ((tab = malloc(sizeof(int) * 4)) == NULL)
    return (84);
  tab[0] = 0;
  tab[1] = 234;
  tab[2] = 131;
  tab[3] = 243;
  while (i < 4)
    {
      if (read(fd, &nb, 1) == -1)
	return (84);
      if (nb != tab[i])
	return (84);
      i += 1;
    }
  free(tab);
  return (0);
}

int	add_prog_name(t_header **champ, int fd, t_var* var)
{
  char	*tmp;
  int	length;

  length = PROG_NAME_LENGTH + 1;
  while (length % 4 != 0)
    length += 1;
  if ((tmp = malloc(sizeof(char) * length)) == NULL)
    return (84);
  if (read(fd, tmp, length) == -1)
    return (84);
  my_copy(champ, var, tmp, 1);
  free(tmp);
  return (0);
}

int		add_size(t_header** champ, int fd, t_var *var)
{
  int		res;
  int		i;
  unsigned char	nb;
  unsigned char	*size;

  i = 0;
  nb = 0;
  if ((size = malloc(sizeof(unsigned char) * 4)) == NULL)
    return (84);
  while (i < 4)
    {
      if (read(fd, &nb, 1) == -1)
	return (84);
      size[i] = nb;
      i = i + 1;
    }
  res = get_size(size);
  (*champ)[var->j].prog_size = res;
  free(size);
  return (0);
}

int	add_comment(t_header** champ, int fd, t_var *var)
{
  char	*tmp;
  int	length;

  length = COMMENT_LENGTH + 1;
  while (length % 4 != 0)
    length += 1;
  if ((tmp = malloc(sizeof(char) * length)) == NULL)
    return (84);
  if (read(fd, tmp, length) == -1)
    return (84);
  my_copy(champ, var, tmp, 2);
  free(tmp);
  return (0);
}

int		add_instructions(t_header** champ, int fd, t_var *var)
{
  int		i;
  int		len;
  int		bytes;
  unsigned char	buf;

  len = (*champ)[var->j].prog_size;
  bytes = 0;
  buf = 0;
  i = 0;
  if (((*champ)[var->j].instru = malloc(sizeof(unsigned char) * len)) == NULL)
    return (84);
  while ((bytes = read(fd, &buf, 1)) > 0)
    {
      (*champ)[var->j].instru[i] = buf;
      i += 1;
    }
  return (0);
}
