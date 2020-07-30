/*
** my_printf_ptr_ft3.c for my_printf_ptr_ft2 in /home/descou_c/PSU/PSU_2016_my_printf/lib/my
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Nov 15 19:13:56 2016 Charles Descoust
** Last update Sun Dec 11 15:29:07 2016 Charles Descoust
*/

#include "../include/lib.h"

int	u_ft(va_list list)
{
  int	count;

  count = my_put_nbr_base(va_arg(list, unsigned int), "0123456789");
  return (count);
}

int	d_ft(va_list list)
{
  int	count;

  count = my_put_nbr_base(va_arg(list, int), "0123456789");
  return (count);
}

int	i_ft(va_list list)
{
  int	count;

  count = my_put_nbr_base(va_arg(list, int), "0123456789");
  return (count);
}
