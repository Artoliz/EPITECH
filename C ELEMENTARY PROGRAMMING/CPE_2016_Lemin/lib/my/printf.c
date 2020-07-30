/*
** printf.c for  in /home/charliebegood/delivery/PSU_2016_my_printf
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Nov  7 12:29:26 2016 Charles AUBERT
** Last update Mon Apr 10 14:30:47 2017 Charles Aubert
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void	fill_tab(func tab[14])
{
  tab[0] = my_putchar_list;
  tab[1] = my_putstr_list;
  tab[2] = my_putnbr_list;
  tab[3] = my_putnbr_list;
  tab[4] = my_putnbr_un_list;
  tab[5] = my_putnbr_b;
  tab[6] = my_putstr_S;
  tab[7] = my_putaddress;
  tab[8] = my_putpercent;
  tab[9] = my_putnbr_h_l;
  tab[10] = my_putnbr_h_h;
  tab[11] = my_putnbr_o;
  tab[12] = my_putnbr_long;
  tab[13] = NULL;
}

int	option(char *str, int i, int fd)
{
  if (str[i] == '#')
    {
      i += 1;
      if (str[i] == 'X')
	my_putstr("0X", fd);
      else if (str[i] == 'x')
	my_putstr("0x", fd);
      else if (str[i] == 'o')
	my_putstr("0", fd);
      return (i);
    }
  else if (str[i] == ' ' || str[i] == '+')
    {
      my_putchar(str[i], fd);
      return (i + 1);
    }
  return (i);
}

int	non_w(char *str, int i)
{
  char	*non_wanted;
  int	i2;

  i2 = 0;
  non_wanted = "-0123456789";
  while (non_wanted[i2] != '\0')
    {
      if (non_wanted[i2] == str[i])
	i += 1;
      else
	return (i);
    }
  return (i);
}

int	match(char *str, t_print p, va_list ap, func *tab_func)
{
  int	i2;
  char	*flags;
  func	function;

  i2 = 0;
  flags = "csdiubSp%xXol";
  p.i += 1;
  p.i = non_w(str, p.i);
  while (str[p.i] == '#' || str[p.i] == ' ' || str[p.i] == '+')
    p.i = option(str, p.i, p.fd);
  while (flags[i2] != '\0')
    {
      if (flags[i2] == str[p.i])
	{
	  if (flags[i2] == 'l')
	    p.i += 1;
	  function = tab_func[i2];
	  function(ap, p.fd);
	  return (p.i);
	}
      else
	i2 += 1;
    }
  my_putchar(str[p.i - 1], p.fd);
  return (p.i - 1);
}

int		my_printf(int fd, int er, char *str, ...)
{
  va_list	ap;
  func		tab_func[14];
  t_print	param;

  fill_tab(tab_func);
  param.i = 0;
  param.fd = fd;
  va_start(ap, str);
  while (str[param.i] != '\0')
    {
      if (str[param.i] == '%')
	param.i = match(str, param, ap, tab_func);
      else
	my_putchar(str[param.i], fd);
      param.i += 1;
    }
  va_end(ap);
  return (er);
}
