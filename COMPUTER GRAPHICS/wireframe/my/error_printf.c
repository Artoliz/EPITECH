/*
** error_printf.c for error_printf in /home/descou_c/PSU/PSU_2016_my_printf/lib/my
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Nov 14 15:42:31 2016 Charles Descoust
** Last update Sun Dec 11 15:28:29 2016 Charles Descoust
*/

#include "../include/lib.h"

void	check_str(unsigned char *arg)
{
  int   i;

  i = 0;
  while (arg[i] != '\0')
    {
      if (arg[i] > 254)
	my_putstr_err(ERROR);
      i = i + 1;
    }
}

int	my_putstr_err(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i = i + 1;
    }
  return (84);
}
