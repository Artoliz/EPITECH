/*
** my_put_nbr_base.c for my_put_nbr_base in /home/descou_c/PSU/PSU_2016_my_printf/lib/my
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Nov  8 16:36:32 2016 Charles Descoust
** Last update Thu Nov 24 14:48:01 2016 Charles Descoust
*/

#include "../include/lib.h"

int	my_put_nbr_base(long nb, char *base)
{
  long	x;
  long	len;
  long	idx;
  int	count;

  len = my_strlen(base);
  x = len;
  count = 0;
  if (nb < 0)
    {
      my_putchar('-');
      count = count + 1;
      nb = nb * -1;
    }
  while ((nb / len) >= x)
    x = len * x;
  while (x != 0)
    {
      idx = nb / x;
      my_putchar(base[idx]);
      count = count + 1;
      nb = nb - (idx * x);
      x = x / len;
    }
  return (count);
}
