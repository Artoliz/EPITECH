/*
** my_getnbr.c for my_getnbr in /home/descou_c/CPool_Day07/lib/my
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Oct 11 09:37:03 2016 Charles Descoust
** Last update Fri Dec  9 18:26:40 2016 Charles Descoust
*/

#include "../include/lib.h"

int	mult_mod(char c, int y)
{
  int	i;

  i = c - 48;
  while (y != 1)
    {
      i = i * 10;
      y = y / 10;
    }
  return (i);
}

int	str_len(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 48 && str[i] <= 57)
	{
	  while (str[i] >= 48 && str[i] <= 57)
	    {
	      j = j + 1;
	      i = i + 1;
	    }
	  return (j);
	}
      i = i + 1;
    }
  return (0);
}

int	transfo_ft(char *str, int length, int x, int res)
{
  int	i;

  i = 0;
  while (length > 0)
    {
      x = x * 10;
      length = length - 1;
    }
  while (str[i] != '\0')
    {
      if (str[i] >= 48 && str[i] <= 57)
	{
	  while (str[i] >= 48 && str[i] <= 57)
	    {
	      res = res + mult_mod(str[i], x);
	      x = x / 10;
	      i = i + 1;
	    }
	  res = res / 10;
	  return (res);
	}
      i = i + 1;
    }
  return (0);
}

int	neg_ft(int res, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((str[i] <= 48 || str[i] >= 57) &&
	 str[i] != '\0')
    {
      if (str[i] == '-')
	j = j + 1;
      i = i + 1;
    }
  if (j % 2 == 1)
    return (-res);
  else
    return (res);
}

int	my_getnbr(char *str)
{
  int	x;
  int	res;
  int	length;

  if ((length = str_len(str)) == 0)
    return (0);
  else
    {
      res = 0;
      x = 1;
      length = str_len(str);
      if (length > 9)
	return (0);
      res = transfo_ft(str, length, x, res);
      res = neg_ft(res, str);
      if (res == 0)
	return (0);
      else
	return (res);
    }
}
