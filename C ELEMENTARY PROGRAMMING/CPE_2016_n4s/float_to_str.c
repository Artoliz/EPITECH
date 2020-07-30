/*
** float_to_str.c for float_to_str.c in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu May  4 13:08:26 2017 Charles Descoust
** Last update Thu May  4 13:08:48 2017 Charles Descoust
*/

#include "inc/n4s.h"

char	*float_to_string2(float nb, int i, char *res)
{
  int   j;
  int   len;

  res[i] = '0';
  i += 1;
  res[i] = '.';
  i += 1;
  j = 0;
  len = 10;
  while (j < 4)
    {
      res[i] = (int)(nb * len) % 10 + 48;
      len *= 10;
      j += 1;
      i += 1;
    }
  res[i] = '\n';
  res[i + 1] = '\0';
  return (res);
}

char	*float_to_string(float nb)
{
  char  *res;
  int   i;

  if ((res = malloc(sizeof(char) * 100)) == NULL)
    return (NULL);
  i = 0;
  if (nb < 0)
    {
      res[i] = '-';
      i += 1;
    }
  if (nb * 10 >= 10 || nb * 10 <= -10)
    {
      res[i] = '1';
      res[i + 1] = '\n';
      res[i + 2] = '\0';
      return (res);
    }
  else
    {
      if (nb < 0)
        nb *= -1;
      res = float_to_string2(nb, i, res);
    }
  return (res);
}
