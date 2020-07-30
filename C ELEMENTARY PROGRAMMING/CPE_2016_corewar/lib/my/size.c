/*
** size.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/Raytracer1/raytracer1/lib/my
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Feb 24 16:50:30 2017 Charles Aubert
** Last update Mon Mar  6 12:37:21 2017 Charles Aubert
*/

#include <stdlib.h>
#include "my.h"

int	size_array_char(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    i += 1;
  return (i);
}

int	size_array_int(int **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    i += 1;
  return (i);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i += 1;
  return (i);
}
