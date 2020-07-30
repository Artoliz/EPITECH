/*
** putnbr2.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/CPE_2016_corewar/lib/my
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Mar  3 18:44:58 2017 Charles Aubert
** Last update Thu Mar 30 18:12:12 2017 Charles Aubert
*/

#include <stdlib.h>
#include "my.h"

int     length_b(unsigned int nbr)
{
  int   i;

  i = 0;
  while (nbr > 0)
    {
      nbr /= 2;
      i += 1;
    }
  return (i);
}

int             my_putnbr_b(va_list ap, int fd)
{
  unsigned int  nbr;
  char          *str;
  int           length;
  int           i;

  i = 0;
  nbr = va_arg(ap, unsigned int);
  length = length_b(nbr);
  str = malloc(sizeof(char) * (length + 1));
  while (nbr > 0)
    {
      str[i] = nbr % 2 + 48;
      nbr /= 2;
      i += 1;
    }
  str[i] = '\0';
  str = my_revstr(str);
  my_putstr(str, fd);
  free(str);
  return (0);
}

int     length_h_un(unsigned int nbr)
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

int             my_putnbr_h_l(va_list ap, int fd)
{
  unsigned int  nbr;
  char          *str;
  char          *base;
  int           i;

  i = 0;
  base = "0123456789abcdef";
  nbr = va_arg(ap, unsigned int);
  str = malloc(sizeof(char) * (length_h_un(nbr) + 1));
  while (nbr > 0)
    {
      str[i] = base[nbr % 16];
      nbr /= 16;
      i += 1;
    }
  str[i] = '\0';
  str = my_revstr(str);
  my_putstr(str, fd);
  free(str);
  return (0);
}

int             my_putnbr_h_h(va_list ap, int fd)
{
  unsigned int  nbr;
  char          *str;
  char          *base;
  int           i;

  i = 0;
  base = "0123456789ABCDEF";
  nbr = va_arg(ap, unsigned int);
  str = malloc(sizeof(char) * (length_h_un(nbr) + 1));
  while (nbr > 0)
    {
      str[i] = base[nbr%16];
      nbr /= 16;
      i += 1;
    }
  str[i] = '\0';
  str = my_revstr(str);
  my_putstr(str, fd);
  free(str);
  return (0);
}
