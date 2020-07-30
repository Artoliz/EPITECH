/*
** write_param.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Sun Mar 26 16:32:50 2017 Bastien LECUSSAN
** Last update Sun Apr  2 15:46:23 2017 Charles Descoust
*/

#include "../include/asm.h"

int	write_type_param(char **my_tab, int fd, t_line *list)
{
  char  *s;
  int   pos;
  int   count;
  int   nb;

  pos = 1;
  count = 0;
  if ((s = malloc(sizeof(char) * 9)) == NULL)
    return (84);
  while (my_tab[count] != NULL  && pos != 9)
    {
      if (check_args(1, 0, 0, my_tab[count]) == 0)
	pos = write_type_in_str(s, pos, "10");
      else if (check_args(0, 1, 0, my_tab[count]) == 0)
	pos = write_type_in_str(s, pos, "11");
      else if (check_args(0, 0, 1, my_tab[count]) == 0)
	pos = write_type_in_str(s, pos, "01");
      count += 1;
    }
  s = complete_str_param(s, pos);
  nb = binar_to_decimal(s);
  if (write(fd, &nb, 1) == -1)
    return (84);
  free(s);
  return (0);
}

int	write_type_in_str(char *str, int pos, char *nb)
{
  str[pos - 1] = nb[0];
  str[pos] = nb[1];
  return (pos + 2);
}

char	*complete_str_param(char *s, int count)
{
  count -= 1;
  while (count < 8)
    {
      s[count] = '0';
      count += 1;
    }
  s[count] = '\0';
  return (s);
}

int	check_typeparam(t_line *list)
{
  if (list->label != NULL && list->label[0]->type == 0)
    {
      if (check_there_is_typeparam(list->my_tab[1]) == 0)
	return (84);
    }
  else if (list->label == NULL || (list->label != NULL
				   && list->label[0]->type == 1))
    if (check_there_is_typeparam(list->my_tab[0]) == 0)
      return (84);
  return (0);
}

int	check_there_is_typeparam(char *str)
{
  if (my_strcmp(str, "live") == 0)
    return (84);
  if (my_strcmp(str, "zjmp") == 0)
    return (84);
  if (my_strcmp(str, "fork") == 0)
    return (84);
  if (my_strcmp(str, "lfork") == 0)
    return (84);
  return (0);
}
