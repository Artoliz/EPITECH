/*
** string.c for string in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed May  3 08:45:16 2017 Charles Descoust
** Last update Wed May  3 10:47:58 2017 Charles Descoust
*/

#include "inc/n4s.h"

int	size_array(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

int	my_strcmp(char* s1, char* s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    i += 1;
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}
