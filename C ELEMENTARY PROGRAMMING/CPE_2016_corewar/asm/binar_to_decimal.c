/*
** binar_to_decimal.c for  in /home/miklox/semestre1/systeme_unix/PSU_2016_navy
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Mon Jan 30 13:55:20 2017 Bastien LECUSSAN
** Last update Tue Mar 28 14:52:09 2017 Charles Aubert
*/

#include "./include/asm.h"
#include "./include/my.h"

int	my_power(int nb, int power)
{
  int	res;
  int	count;

  res = nb;
  if (power == 0)
    res = 1;
  count = 1;
  while (count < power)
    {
      res = res * nb;
      count = count + 1;
    }
  return (res);
}

int	binar_to_decimal(char *str)
{
  int	count;
  int	nb;

  str = my_revstr(str);
  nb = 0;
  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] == '1')
	nb = nb + my_power(2, count);
      count = count + 1;
    }
  return (nb);
}

void	decimal_to_binar(char *str, char *binar, int nb)
{
  int	length_base;
  int	count;

  count = 0;
  length_base = my_strlen(binar);
  while (nb > 0)
    {
      if (nb >= length_base)
	str[count] = binar[(nb % length_base)];
      else
	str[count] = binar[nb];
      count = count + 1;
      nb = nb / length_base;
    }
  str[count] = '\0';
  my_revstr(str);
}
