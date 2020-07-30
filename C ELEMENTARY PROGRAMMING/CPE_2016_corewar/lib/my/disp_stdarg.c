/*
** disp_stdarg.c for  in /home/charliebegood/delivery/UNIX_System/PSU_2016_my_printf_bootstrap/lib/my
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Nov  8 09:46:59 2016 Charles AUBERT
** Last update Tue Dec 20 10:36:42 2016 Charles AUBERT
*/

#include <stdarg.h>
#include "./my.h"

int		disp_stdarg(char *s, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, s);
  while (s[i] != '\0')
    {
      if (s[i] == 'i')
	my_putnbr(va_arg(ap, int));
      else if (s[i] == 'c')
	my_putchar(va_arg(ap, int));
      else if (s[i] == 's')
	my_putstr(va_arg(ap, char *));
      my_putchar('\n');
      i += 1;
    }
  va_end(ap);
  return (0);
}
