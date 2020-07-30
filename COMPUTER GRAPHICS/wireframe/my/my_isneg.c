/*
** my_isneg.c for my_isneg in /home/descou_c/CPool_Day03
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Oct  5 09:01:48 2016 Charles Descoust
** Last update Thu Nov 24 14:46:56 2016 Charles Descoust
*/

#include "../include/lib.h"

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
