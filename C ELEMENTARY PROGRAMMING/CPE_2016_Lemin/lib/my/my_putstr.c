/*
** my_putstr.c for  in /home/charliebegood/delivery/CPool_Day04
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Oct  6 09:27:42 2016 Charles AUBERT
** Last update Fri Apr 21 10:21:43 2017 Charles Aubert
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./my.h"

int	my_putstr_list(va_list ap, int fd)
{
  int	i;
  char	*str;

  str = va_arg(ap, char *);
  i = 0;
  while (str[i] != '\0')
    {
      if (write(fd, &str[i], 1) == -1)
	return (1);
      i += 1;
    }
  return (0);
}

int	my_putstr(char *str, int fd)
{
  write(fd, str, my_strlen(str));
  return (0);
}

int	my_putstr_er(char *str, int error)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (write(2, &str[i], 1) == -1)
	return (error);
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
