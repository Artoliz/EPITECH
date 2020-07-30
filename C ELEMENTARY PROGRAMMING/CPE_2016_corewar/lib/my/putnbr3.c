/*
** my_putnbr.c for  in /home/charliebegood/delivery/PSU_2016_my_printf
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Nov  7 12:43:24 2016 Charles AUBERT
** Last update Fri Mar  3 18:46:51 2017 Charles Aubert
*/

#include <stdarg.h>
#include "./my.h"

int	my_putnbr_un_list2(unsigned int nbr)
{
  if (nbr > 9)
    my_putnbr_un_list2(nbr / 10);
  my_putchar((nbr % 10) + '0');
  return (0);
}

int     my_putnbr_un_list(va_list ap)
{
  unsigned int	 nbr;

  nbr = va_arg(ap, unsigned int);
  my_putnbr_un_list2(nbr);
  return (0);
}
