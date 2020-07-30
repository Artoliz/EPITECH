/*
** my_str.c for my_str in /home/descou_c/CPE/matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Feb 11 11:27:26 2017 Charles Descoust
** Last update Wed Feb 22 14:49:30 2017 Charles Descoust
*/

#include "inc/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_strlen(char* str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int	my_strisnum(char* str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 48 && str[i] <= 57) || str[i] == '\n')
	i = i + 1;
      else
	return (84);
    }
  return (0);
}

int	my_put_nbr(int nb)
{
  int   x;

  x = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  while ((nb / x) >= 10)
    x = x * 10;
  while (x != 0)
    {
      my_putchar((nb / x) % 10 + 48);
      x = x / 10;
    }
  return (0);
}
