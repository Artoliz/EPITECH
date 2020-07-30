/*
** sum_stdarg.c for  in /home/charliebegood/delivery/UNIX_System/PSU_2016_my_printf_bootstrap/lib/my
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Nov  8 09:33:05 2016 Charles AUBERT
** Last update Tue Dec 20 10:35:10 2016 Charles AUBERT
*/

#include <stdarg.h>
#include "./my.h"

int		sum_stdarg(int i, int nb, ...)
{
  int		count;
  int		res;
  va_list	ap;

  va_start(ap, nb);
  count = 0;
  res = 0;
  while (count < nb)
    {
      if (i == 0)
	res += va_arg(ap, int);
      else if (i == 1)
	res += my_strlen(va_arg(ap, char *));
      count += 1;
    }
  va_end(ap);
  return (res);
}
