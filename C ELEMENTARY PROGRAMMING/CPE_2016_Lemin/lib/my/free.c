/*
** free.c for  in /home/charliebegood/delivery/UNIX_System/Minishell1/PSU_2016_minishell1/lib/my
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Sun Jan 15 11:26:56 2017 Charles Aubert
** Last update Sat Mar 25 16:55:34 2017 Charles Aubert
*/

#include <stdlib.h>
#include "my.h"

int	free_array_char(char **array, int error)
{
  int   i;

  i = 0;
  if (array == NULL)
    return (error);
  while (array[i] != NULL)
    {
      free(array[i]);
      i += 1;
    }
  free(array);
  return (error);
}

int	free_array_int(int **array, int error)
{
  int   i;

  i = 0;
  if (array == NULL)
    return (error);
  while (array[i] != NULL)
    {
      free(array[i]);
      i += 1;
    }
  free(array);
  return (error);
}

int	free_str(char *str, int error)
{
  if (str != NULL)
    free(str);
  return (error);
}
