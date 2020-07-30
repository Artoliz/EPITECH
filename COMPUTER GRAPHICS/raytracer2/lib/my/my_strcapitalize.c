/*
** my_strcapitalize.c for  in /home/charliebegood/delivery/CPool_Day06
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Oct 10 13:37:46 2016 Charles AUBERT
** Last update Thu Feb  2 16:45:24 2017 Charles Aubert
*/

#include "./my.h"

int	is_low(char c)
{
  if (c > 96 && c < 123)
    return (0);
  return (1);
}

int	is_up(char c)
{
  if (c > 64 && c < 91)
    return (0);
  return (1);
}

int	is_num(char c)
{
  if (c > 47 && c < 58)
    return (0);
  return (1);
}

int	is_alpha_num(char c)
{
  if (is_up(c) == 0 && is_low(c) == 0 && is_num(c) == 0)
    return (0);
  return (1);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (i == 0 && is_low(str[i]) == 0)
	str[i] -= 32;
      else if (i != 0 && is_alpha_num(str[i - 1]) == 1 && is_low(str[i]) == 0)
	str[i] -= 32;
      else if (i != 0 && is_alpha_num(str[i - 1]) == 0 && is_up(str[i]) == 0)
	str[i] += 32;
      i += 1;
    }
  return (str);
}
