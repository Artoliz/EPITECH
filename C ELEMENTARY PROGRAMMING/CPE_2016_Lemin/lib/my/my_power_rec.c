/*
** my_power_rec.c for  in /home/charliebegood/delivery/CPool_Day05
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Oct  7 15:41:33 2016 Charles AUBERT
** Last update Wed Jan  4 08:59:31 2017 Charles AUBERT
*/

#include "./my.h"

int	my_power_rec(int nb, int p)
{
  int	result;

  if (p > 1)
    {
      result = nb * my_power_rec(nb, p - 1);
      if (result <= 2147483647)
	return (result);
      else
	return (0);
    }
  if (p < 0)
    return (0);
  if (p == 0)
    return (1);
  if (p == 1)
    return (nb);
  else
    return (0);
}
