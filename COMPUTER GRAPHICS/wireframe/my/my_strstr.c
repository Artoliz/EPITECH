/*
** my_strstr.c for my_strstr in /home/descou_c/CPool_Day06
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Oct 10 13:55:47 2016 Charles Descoust
** Last update Thu Nov 24 14:51:36 2016 Charles Descoust
*/

#include "../include/lib.h"

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	match;
  int	length;

  i = 0;
  j = 0;
  length = my_strlen(to_find);
  match = 0;
  while (str[i] != '\0')
    {
      while (to_find[j] != '\0' && to_find[j] == str[i])
  	{
  	  match++;
  	  i++;
  	  j++;
  	}
      i++;
    }
  if (match == length)
    return (to_find);
  else
    return (0);
}
