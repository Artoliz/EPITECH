/*
** putnbr.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/CPE_2016_corewar/lib/my
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Mar  3 18:44:00 2017 Charles Aubert
** Last update Mon Mar  6 12:30:50 2017 Charles Aubert
*/

#include <stdlib.h>
#include "my.h"

int     my_putnbr_list(va_list ap)
{
  int   nbr;

  nbr = va_arg(ap, int);
  my_putnbr(nbr);
  return (0);
}

int     my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      my_putchar('-');
      if (nbr < -9)
        my_putnbr((nbr / 10 * -1));
      my_putchar((nbr % 10 * -1) + 48);
    }
  else
    {
      if (nbr > 9)
        my_putnbr(nbr / 10);
      my_putchar((nbr % 10) + 48);
    }
  return (0);
}

int             my_putnbr_long(va_list ap)
{
  long int      nbr;

  nbr = va_arg(ap, long int);
  if (nbr < 0)
    {
      my_putchar('-');
      if (nbr < -9)
        my_putnbr((nbr / 10 * -1));
      my_putchar((nbr % 10 * -1) + 48);
    }
  else
    {
      if (nbr > 9)
        my_putnbr(nbr / 10);
      my_putchar((nbr % 10) + 48);
    }
  return (0);
}

int     length_o(int nbr)
{
  int   i;

  i = 0;
  if (nbr < 0)
    {
      while (nbr < 0)
        {
          nbr /= 8;
          i += 1;
        }
    }
  else
    {
      while (nbr > 0)
        {
          nbr /= 8;
          i += 1;
        }
    }
  return (i);
}

int     my_putnbr_o(va_list ap)
{
  int   nbr;
  char  *str;
  int   i;

  i = 0;
  nbr = va_arg(ap, int);
  str = malloc(sizeof(char) * (length_o(nbr) + 1));
  if (nbr < 0)
    my_putchar('-');
  while (nbr != 0)
    {
      if (nbr < 0)
        str[i] = (nbr % 8 + 48) * -1;
      str[i] = nbr % 8 + 48;
      nbr /= 8;
      i += 1;
    }
  str[i] = '\0';
  str = my_revstr(str);
  my_putstr(str);
  free(str);
  return (0);
}
