/*
** my_putpercent.c for  in /home/charliebegood/delivery/UNIX_System/PSU_2016_my_printf
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Nov 15 10:57:44 2016 Charles AUBERT
** Last update Wed Apr 26 09:20:18 2017 Charles Aubert
*/

#include <stdarg.h>
#include "my.h"

int	my_putpercent(va_list ap, int fd)
{
  (void)ap;
  my_putchar('%', fd);
  return (0);
}
