/*
** sti.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Mon Mar 27 13:49:19 2017 Bastien LECUSSAN
** Last update Sun Apr  2 15:44:57 2017 Charles Descoust
*/

#include "../include/asm.h"

char	*check_type_STI(t_line *list)
{
  char  *s;
  int	count;

  count = 2;
  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  if (list-> label != NULL)
    if (list->label[0]->type == 0)
      count += 1;
  if (check_args(0, 0, 1, list->my_tab[count]) == 0)
    s[1] = '1';
  else
    s[1] = '9';
  if (check_args(0, 0, 1, list->my_tab[count + 1]) == 0)
    s[2] = '1';
  else
    s[2] = '9';
  return (s);
}

char	*check_type_FORK(t_line *list)
{
  char  *s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  s[0] = '9';
  return (s);
}

char	*check_type_LLD(t_line *list)
{
  char  *s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  return (s);
}

char	*check_type_LLDI(t_line *list)
{
  char  *s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  s[0] = '9';
  s[1] = '9';
  return (s);
}

char	*check_type_LFORK(t_line *list)
{
  char  *s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  s[0] = '9';
  return (s);
}
