/*
** live.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Mon Mar 27 10:44:42 2017 Bastien LECUSSAN
** Last update Tue Mar 28 16:41:13 2017 Bastien LECUSSAN
*/

#include "../include/asm.h"

char	*check_type_LIVE(t_line *list)
{
  char	*s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  s[0] = '4';
  return (s);
}

char	*check_type_LD(t_line *list)
{
  char	*s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  return (s);
}

char	*check_type_ST(t_line *list)
{
  char	*s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  return (s);
}

char	*check_type_ADD(t_line *list)
{
  char	*s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  return (s);
}

char	*check_type_SUBB(t_line *list)
{
  char	*s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  return (s);
}
