/*
** my_sort_tab.c for  in /home/charliebegood/delivery/UNIX_System/Tetris/PSU_2016_tetris/lib/my
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed Mar  1 09:43:43 2017 Charles Aubert
** Last update Wed Mar  1 09:57:14 2017 Charles Aubert
*/

#include <stdlib.h>
#include "my.h"

char	**sort_array_char(char **array)
{
  int	i;
  int	i2;
  char	*temp;

  i = 0;
  while (array[i] != NULL && array[i + 1] != NULL)
    {
      i2 = 0;
      while (array[i2] != NULL && array[i2 + 1] != NULL)
	{
	  if (my_ascii_sort(array[i2], array[i2 + 1]) > 0)
	    {
	      temp = array[i2];
	      array[i2] = array[i2 + 1];
	      array[i2 + 1] = temp;
	    }
	  i2 += 1;
	}
      i += 1;
    }
  return (array);
}
