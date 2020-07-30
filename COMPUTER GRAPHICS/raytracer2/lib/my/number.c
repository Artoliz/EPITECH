/*
** number.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/CPE_2016_corewar/lib/my
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Mar  3 18:43:24 2017 Charles Aubert
** Last update Fri Mar  3 18:44:19 2017 Charles Aubert
*/

#include "./my.h"

int     my_power_rec(int nb, int p)
{
  int   result;

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
