/*
** my_printf.c for my_printf in /home/descou_c/PSU/PSU_2016_my_printf/lib/my
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Nov  8 15:03:47 2016 Charles Descoust
** Last update Thu Nov 24 14:47:20 2016 Charles Descoust
*/

#include "../include/lib.h"

int	put_str_and_octal(unsigned char *arg)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (arg[i] != '\0')
    {
      if (arg[i] < 32 || arg[i] >= 127)
	{
	  my_putchar('\\');
	  count = count + 1;
	  if (arg[i] < 32)
	    {
	      my_putchar('0');
	      count = count + 1;
	    }
	  count = count + my_put_nbr_base(arg[i], "01234567");
	  i = i + 1;
	}
      my_putchar(arg[i]);
      count = count + 1;
      i = i + 1;
    }
  return (count);
}

int	while_ptr_ft(char *format, int i, va_list list, t_ptr_ft *tab)
{
  int	j;
  int	count;

  j = 0;
  count = 0;
  while (j <= 11)
    {
      if (tab[j].a == format[i + 1])
	count = count + tab[j].ft(list);
      j = j + 1;
    }
  return (count);
}

int	conv_indic_ft(char *format, va_list list, t_ptr_ft *tab)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%' && format[i + 1] == '%')
	{
	  my_putchar(format[i + 1]);
	  i = i + 2;
	}
      else if (format[i] == '%' && format[i + 1] != '%')
	{
	  count = count + while_ptr_ft(format, i, list, tab);
	  i = i + 2;
	}
      else
	{
	  my_putchar(format[i]);
	  count = count + 1;
	  i = i + 1;
	}
    }
  return (count);
}

int		my_printf(char *format, ...)
{
  int		nb_chars;
  va_list	list;
  t_ptr_ft	tab[]=
    {
      {'b', b_ft},
      {'p', p_ft},
      {'o', o_ft},
      {'u', u_ft},
      {'d', d_ft},
      {'i', i_ft},
      {'x', x_ft},
      {'X', X_ft},
      {'s', s_ft},
      {'c', c_ft},
      {'S', S_ft},
    };

  va_start(list, format);
  nb_chars = conv_indic_ft(format, list, tab);
  return (nb_chars);
}
