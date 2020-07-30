/*
** my_putchar.c for  in /home/charliebegood/delivery/CPool_Day07/lib/my
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Oct 11 18:17:01 2016 Charles AUBERT
** Last update Sat Mar 25 17:07:47 2017 Charles Aubert
*/

#include <unistd.h>
#include <stdlib.h>
#include "./my.h"

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (1);
  return (0);
}

int	my_putchar_list(va_list ap)
{
  char	c;

  c = va_arg(ap, int);
  if (write(1, &c, 1) == -1)
    return (1);
  return (0);
}
