/*
** my_revstr.c for my_revstr in /home/descou_c/CPool_Day06
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Oct 10 13:48:33 2016 Charles Descoust
** Last update Thu Nov 24 14:48:27 2016 Charles Descoust
*/

#include "../include/lib.h"

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	buff;

  i = 0;
  j = my_strlen(str) - 1;
  while (i <= j)
    {
      buff = str[i];
      str[i] = str[j];
      str[j] = buff;
      j--;
      i++;
    }
  return (str);
}
