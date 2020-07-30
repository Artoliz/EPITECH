/*
** getnbr.c for my_getnbr in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed May  3 11:38:03 2017 Charles Descoust
** Last update Wed May  3 14:57:56 2017 Charles Descoust
*/

#include "inc/n4s.h"

int	is_num(char c)
{
  if (c > 47 && c < 58)
    return (0);
  return (1);
}

int	add_number(char nb, int result)
{
  result = result * 10 + (nb - 48);
  return (result);
}

int	check_res(int result, int is_neg)
{
  if (is_neg == 1)
    result *= -1;
  return (result);
}

int	my_getnbr(char *str)
{
  int	i;
  int	is_neg;
  int	result;

  i = 0;
  result = 0;
  is_neg = 0;
  while (is_num(str[i]) != 0 && str[i] != '\0')
    i += 1;
  if (i > 0 && str[i - 1] == 45 && result == 0)
    is_neg = 1;
  while (str[i] != '\0')
    {
      if (str[i] == 43 && result == 0)
	is_neg = 0;
      else if (str[i] > 47 && str[i] < 58)
	result = add_number(str[i], result);
      else
	return (check_res(result, is_neg));
      i += 1;
    }
  return (check_res(result, is_neg));
}
