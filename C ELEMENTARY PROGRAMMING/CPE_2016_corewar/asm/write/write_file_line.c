/*
** write_file_line.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Sun Mar 26 19:18:32 2017 Bastien LECUSSAN
** Last update Sun Apr  2 21:18:15 2017 Bastien LECUSSAN
*/

#include "../include/asm.h"

int	write_line(t_line *list, int fd, int *position)
{
  int	count;
  int	pos;
  int	save;

  count = 0;
  save = position[0] - 1;
  if (check_typeparam(list) == 84)
    save -= 1;
  while (list->type_line[count] != '\0' && list->type_line[count] != '0')
    {
      pos = position[0] - save;
      if (list->type_line[count] == '1')
	if (write_register(list, count, fd) == 84)
	  return (84);
      if (loop_line(list, count, fd, pos) == 84)
	return (84);
      if (list->type_line[count] == '9')
	position[0] += 2;
      else
	position[0] += list->type_line[count] - '0';
      count += 1;
    }
  return (0);
}

int	loop_line(t_line *list, int count, int fd, int pos)
{
  if (list->type_line[count] == '2')
    if (write_indirect(list, count, fd) == 84)
      return (84);
  if (list->type_line[count] == '4')
    if (write_direct(list, count, fd, pos) == 84)
      return (84);
  if (list->type_line[count] == '9')
    if (write_index(list, count, fd, pos) == 84)
      return (84);
  return (0);
}

int	write_indirect(t_line *list, int count, int fd)
{
  int   cnt;
  int   nb;

  if (list->label != NULL && list->label[0]->type == 0)
    cnt = 2;
  else
    cnt = 1;
  cnt += count;
  nb = my_getnbr(list->my_tab[cnt]);
  nb = get_big_endian(nb, T_IND);
  if (write(fd, &nb, T_IND) == -1)
    return (84);
  return (0);
}

int	write_register(t_line *list, int count, int fd)
{
  int	cnt;
  int	nb;

  if (list->label != NULL && list->label[0]->type == 0)
    cnt = 2;
  else
    cnt = 1;
  cnt += count;
  count = 0;
  while (list->my_tab[cnt][count + 1] != '\0')
    {
      list->my_tab[cnt][count] = list->my_tab[cnt][count + 1];
      count += 1;
    }
  list->my_tab[cnt][count] = '\0';
  nb = my_getnbr(list->my_tab[cnt]);
  nb = get_big_endian(nb, T_REG);
  if (write(fd, &nb, T_REG) == -1)
    return (84);
  return (0);
}
