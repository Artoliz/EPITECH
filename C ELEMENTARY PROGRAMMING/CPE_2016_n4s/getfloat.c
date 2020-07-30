/*
** getfloat.c for my_getfloat in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed May  3 11:37:55 2017 Charles Descoust
** Last update Wed May  3 11:37:56 2017 Charles Descoust
*/

#include "inc/n4s.h"

int     get_num(char *str, int i)
{
  int   is_neg;
  int   result;

  result = 0;
  is_neg = 0;
  while (str[i] != '\0')
    {
      if (str[i] == 43 && result == 0)
        is_neg = 0;
      else if (str[i] == 45 && result == 0)
        is_neg = 1;
      else if (str[i] > 47 && str[i] < 58)
        result = add_number(str[i], result);
      else
        return (check_res(result, is_neg));
      i += 1;
    }
  return (check_res(result, is_neg));
}

float	pow_10(int nbr)
{
  float	r;

  r = 0.1;
  while (nbr > 9)
    {
      nbr /= 10.0;
      r /= 10.0;
    }
  return (r);
}

float	my_getfloat(char *line)
{
  int	bef;
  int	af;
  int	i;
  float	result;

  bef = get_num(line, 0);
  result = 0.0;
  i = 0;
  while (line[i] != '.' && line[i + 1] != '\0')
    i += 1;
  af = get_num(line, i + 1);
  result += bef;
  if (bef < 0)
    result += af * pow_10(af) * -1;
  else
    result += af * pow_10(af);
  return (result);
}
