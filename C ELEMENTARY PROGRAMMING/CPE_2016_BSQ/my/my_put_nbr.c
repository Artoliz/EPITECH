/*
** my_put_nbr.c for my_put_nbr in /home/descou_c/CPool_Day03
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Oct  5 16:14:06 2016 Charles Descoust
** Last update Thu Nov 24 14:48:10 2016 Charles Descoust
*/

#include "../include/lib.h"

int	my_put_nbr(int nb)
{
  int	x;

  x = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  while ((nb / x) >= 10)
    x = x * 10;
  while (x != 0)
    {
      my_putchar((nb / x) % 10 + 48);
      x = x / 10;
    }
  return (0);
}
