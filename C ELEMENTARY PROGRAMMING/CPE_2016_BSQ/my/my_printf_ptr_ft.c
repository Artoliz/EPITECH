/*
** my_printf_ptr_ft.c for my_printf_ptr_ft in /home/descou_c/PSU/PSU_2016_my_printf/lib/my
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Nov 15 17:41:04 2016 Charles Descoust
** Last update Sun Dec 11 15:29:25 2016 Charles Descoust
*/

#include "../include/lib.h"

int	S_ft(va_list list)
{
  int	count;

  count = put_str_and_octal(va_arg(list, unsigned char*));
  return (count);
}

int	X_ft(va_list list)
{
  int	count;

  count = my_put_nbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
  return (count);
}

int	s_ft(va_list list)
{
  int	count;

  count = my_putstr(va_arg(list, char*));
  return (count);
}

int	c_ft(va_list list)
{
  my_putchar(va_arg(list, int));
  return (1);
}
