/*
** my_strcmp.c for my_strcmp in /home/descou_c/CPool_Day06
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Oct 10 14:02:43 2016 Charles Descoust
** Last update Thu Nov 24 14:49:44 2016 Charles Descoust
*/

#include "../include/lib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) == my_strlen(s2))
    {
      while (s1[i] != '\0')
	{
	  if (s1[i] > s2[i])
	    return (1);
	  else if (s1[i] < s2[i])
	    return (-1);
	  i = i + 1;
	}
      return (0);
    }
  else if (my_strlen(s1) > my_strlen(s2))
    return (1);
  else
    return (-1);
}
