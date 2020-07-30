/*
** my_strcat.c for my_strcat in /home/descou_c/CPool_Day07
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Oct 11 09:44:22 2016 Charles Descoust
** Last update Thu Nov 24 14:49:37 2016 Charles Descoust
*/

#include "../include/lib.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[j + i] = src[i];
      i++;
    }
  dest[j + i] = '\0';
  return (dest);
}
