/*
** my_putstr.c for  in /home/charliebegood/delivery/CPool_Day04
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Oct  6 09:27:42 2016 Charles AUBERT
** Last update Sat Mar 25 17:07:22 2017 Charles Aubert
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./my.h"

int	my_putstr_list(va_list ap)
{
  int	i;
  char	*str;

  str = va_arg(ap, char *);
  i = 0;
  while (str[i] != '\0')
    {
      if (write(1, &str[i], 1) == -1)
	return (1);
      i += 1;
    }
  return (0);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i += 1;
    }
  return (0);
}

int	my_putstr_er(char *str, int error)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (write(2, &str[i], 1) == -1)
	return (1);
      i += 1;
    }
  return (error);
}

int	my_putstr_in(char *str, int error)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (write(0, &str[i], 1) == -1)
	return (1);
      i += 1;
    }
  return (error);
}
