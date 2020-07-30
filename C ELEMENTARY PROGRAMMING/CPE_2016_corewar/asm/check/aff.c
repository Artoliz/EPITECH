/*
** aff.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Mon Mar 27 14:15:06 2017 Bastien LECUSSAN
** Last update Sun Apr  2 15:42:08 2017 Charles Descoust
*/

#include "../include/asm.h"

char	*check_type_AFF(t_line *list)
{
  char  *s;

  if ((s = set_type_line_by_default(list)) == NULL)
    return (NULL);
  s[0] = '1';
  return (s);
}
