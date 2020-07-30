/*
** my_putaddress.c for  in /home/charliebegood/delivery/UNIX_System/PSU_2016_my_printf
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Nov 15 11:03:31 2016 Charles AUBERT
** Last update Mon Mar  6 12:35:39 2017 Charles Aubert
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int     length_h(long nbr)
{
  int   i;

  i = 0;
  while (nbr > 0)
    {
      nbr /= 16;
      i += 1;
    }
  return (i);
}

int	convert_d_to_h(long nbr)
{
  char          *str;
  char          *base;
  int           i;

  i = 0;
  base = "0123456789abcdef\0";
  if ((str = malloc(sizeof(char) * (length_h(nbr) + 1))) == NULL)
       return (84);
  while (nbr > 0)
    {
      str[i] = base[nbr % 16];
      nbr /= 16;
      i += 1;
    }
  str[i] = '\0';
  str = my_revstr(str);
  my_putstr(str);
  free(str);
  return (0);
}

int	my_putaddress(va_list ap)
{
  long	pointer;

  my_putstr("0x");
  pointer = (long)va_arg(ap, void *);
  convert_d_to_h(pointer);
  return (0);
}
