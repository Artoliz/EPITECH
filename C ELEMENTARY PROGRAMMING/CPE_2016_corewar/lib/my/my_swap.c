/*
** my_swap.c for  in /home/charliebegood/delivery/CPool_Day04
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Oct  6 08:24:46 2016 Charles AUBERT
** Last update Wed Jan  4 09:00:42 2017 Charles AUBERT
*/

#include "./my.h"

int	my_swap(int *a, int *b)
{
  int	h;

  h = *a;
  *a = *b;
  *b = h;
  return (0);
}
