/*
** my_putchar.c for  in /home/charliebegood/delivery/CPool_Day07/lib/my
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Oct 11 18:17:01 2016 Charles AUBERT
** Last update Thu Mar 30 18:02:55 2017 Charles Aubert
*/

#include <unistd.h>
#include <stdlib.h>
#include "./my.h"

int	my_putchar(char c, int fd)
{
  if (write(fd, &c, 1) == -1)
    return (1);
  return (0);
}

int	my_putchar_list(va_list ap, int fd)
{
  char	c;

  c = va_arg(ap, int);
  if (write(fd, &c, 1) == -1)
    return (1);
  return (0);
}
