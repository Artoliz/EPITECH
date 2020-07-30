/*
** my_str_isnum.c for my_str_isnum in /home/descou_c/CPool_Day07/lib/my
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Oct 11 09:39:24 2016 Charles Descoust
** Last update Thu Nov 24 14:50:16 2016 Charles Descoust
*/

#include "../include/lib.h"

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '-')
    i = i + 1;
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
	return (84);
      i = i + 1;
    }
  return (0);
}
