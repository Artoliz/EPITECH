/*
** my_printf_ptr_ft2.c for my_printf_ptr_ft2 in /home/descou_c/PSU/PSU_2016_my_printf/lib/my
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Nov 15 18:48:02 2016 Charles Descoust
** Last update Sun Dec 11 15:28:53 2016 Charles Descoust
*/

#include "../include/lib.h"

int	b_ft(va_list list)
{
  int	count;

  count = my_put_nbr_base(va_arg(list, int), "01");
  return (count);
}

int	p_ft(va_list list)
{
  int	count;

  my_putstr("0x");
  count = 2 + my_put_nbr_base(va_arg(list, long), "0123456789abcdef");
  return (count);
}

int	o_ft(va_list list)
{
  int	count;

  count = my_put_nbr_base(va_arg(list, unsigned int), "01234567");
  return (count);
}

int	x_ft(va_list list)
{
  int	count;

  count = my_put_nbr_base(va_arg(list, unsigned int), "0123456789abcdef");
  return (count);
}
