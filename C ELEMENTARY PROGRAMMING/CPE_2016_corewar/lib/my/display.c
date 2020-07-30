/*
** display.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/MatchStick/CPE_2016_matchstick/lib/my
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Feb 13 10:46:20 2017 Charles Aubert
** Last update Sat Mar 25 17:06:01 2017 Charles Aubert
*/

#include <stdlib.h>
#include "my.h"

void	display_array_char(char **array)
{
  int	i;

  i = 0;
  while (array != NULL && array[i] != NULL)
    {
      my_putstr(array[i]);
      my_putchar('\n');
      i += 1;
    }
}

void	display_array_int(int **array, int size)
{
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  while (array != NULL && array[i] != NULL && size > 0)
    {
      i2 = 0;
      while (i2 < size)
	{
	  my_putnbr(array[i][i2]);
	  i2 += 1;
	}
      my_putchar('\n');
      i += 1;
    }
}
