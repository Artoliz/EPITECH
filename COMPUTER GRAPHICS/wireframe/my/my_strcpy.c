/*
** my_strcpy.c for my_strcpy in /home/descou_c/CPool_Day06
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Oct 10 09:08:18 2016 Charles Descoust
** Last update Thu Nov 24 14:49:51 2016 Charles Descoust
*/

#include "../include/lib.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
