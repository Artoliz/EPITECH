/*
** my_swap.c for my_swap in /home/descou_c/CPool_Day04
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Oct  6 08:52:35 2016 Charles Descoust
** Last update Thu Nov 24 14:51:48 2016 Charles Descoust
*/

#include "../include/lib.h"

int	my_swap(int *a, int *b)
{
  int	*c;

  c = a;
  a = b;
  b = c;
  return (0);
}
