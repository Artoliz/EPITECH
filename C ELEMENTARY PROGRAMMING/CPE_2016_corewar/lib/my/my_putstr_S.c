/*
** my_putstr_S.c for  in /home/charliebegood/delivery/UNIX_System/PSU_2016_my_printf
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Nov 15 18:09:10 2016 Charles AUBERT
** Last update Mon Mar  6 12:24:14 2017 Charles Aubert
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int     my_putnbr_oS(int nbr)
{
  char  *str;
  int   i;

  i = 0;
  str = malloc(sizeof(char) * (3 + 1));
  while (nbr != 0)
    {
      str[i] = nbr % 8 + 48;
      nbr /= 8;
      i += 1;
    }
  while (i != 3)
    {
      str[i] = '0';
      i += 1;
    }
  str[i] = '\0';
  str = my_revstr(str);
  my_putstr(str);
  free(str);
  return (0);
}

int	my_putstr_S(va_list ap)
{
  int	i;
  char	*str;

  str = va_arg(ap, char *);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] == 127)
	{
	  my_putchar('\\');
	  my_putnbr_oS(str[i]);
	}
      else
	my_putchar(str[i]);
      i += 1;
    }
  return (0);
}
