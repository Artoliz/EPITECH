/*
** printf.c for  in /home/charliebegood/delivery/PSU_2016_my_printf
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Nov  7 12:29:26 2016 Charles AUBERT
** Last update Wed Feb  8 15:35:30 2017 Charles Aubert
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

func		*fill_tab()
{
  func		*tab;

  if ((tab = malloc(sizeof(func) * 14)) == NULL)
    return (NULL);
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
  return (tab);
}

int	option(char *str, int i)
{
  if (str[i] == '#')
    {
      i += 1;
      if (str[i] == 'X')
	my_putstr("0X");
      else if (str[i] == 'x')
	my_putstr("0x");
      else if (str[i] == 'o')
	my_putstr("0");
      return (i);
    }
  else if (str[i] == ' ' || str[i] == '+')
    {
      my_putchar(str[i]);
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

int	match(char *str, int i, va_list ap, func *tab_func)
{
  int	i2;
  char	*flags;
  func	function;

  i2 = 0;
  flags = "csdiubSp%xXol";
  i = non_w(str, i);
  while (str[i] == '#' || str[i] == ' ' || str[i] == '+')
    i = option(str, i);
  while (flags[i2] != '\0')
    {
      if (flags[i2] == str[i])
	{
	  if (flags[i2] == 'l')
	    i += 1;
	  function = tab_func[i2];
	  function(ap);
	  return (i);
	}
      else
	i2 += 1;
    }
  my_putchar(str[i - 1]);
  return (i - 1);
}

int		my_printf(char *str, ...)
{
  int		i;
  va_list	ap;
  func		*tab_func;

  if ((tab_func = fill_tab()) == NULL)
    return (0);
  i = 0;
  va_start(ap, str);
  while (str[i] != '\0')
    {
      if (str[i] == '%')
	i = match(str, i + 1, ap, tab_func);
      else
	my_putchar(str[i]);
      i += 1;
    }
  va_end(ap);
  free(tab_func);
  return (0);
}
