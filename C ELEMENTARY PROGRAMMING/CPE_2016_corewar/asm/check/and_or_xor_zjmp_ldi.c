/*
** and.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Mon Mar 27 13:29:27 2017 Bastien LECUSSAN
** Last update Sun Apr  2 15:42:30 2017 Charles Descoust
*/

#include "../include/asm.h"

char	*check_type_AND(t_line *list)
{
  char	*s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  return (s);
}

char	*check_type_OR(t_line *list)
{
  char  *s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  return (s);
}

char	*check_type_XOR(t_line *list)
{
  char  *s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  return (s);
}

char	*check_type_ZJMP(t_line *list)
{
  char  *s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  s[0] = '9';
  return (s);
}

char	*check_type_LDI(t_line *list)
{
  char  *s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  s[0] = '9';
  s[1] = '9';
  return (s);
}
