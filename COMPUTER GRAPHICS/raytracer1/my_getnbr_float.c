/*
** my_getnbr_float.c for my_getnbr_float in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sun Feb 12 15:40:31 2017 Charles Descoust
** Last update Tue Mar  7 12:57:30 2017 Charles Descoust
*/

#include <stdio.h>

int	len_before(char* str)
{
  int	i;
  int	bef;

  i = 0;
  bef = 0;
  if (str[0] == '-')
    i = i + 1;
  while (str[i] != '.' && str[i] != '\0')
    {
      bef = bef + 1;
      i = i + 1;
    }
  return (bef);
}

int	len_after(char* str)
{
  int	i;
  int	aft;

  i = 0;
  aft = 0;
  while (str[i] != '.' && str[i] != '\0')
    i = i + 1;
  if (str[i] == '.')
    i = i + 1;
  while (str[i] != '\0')
    {
      aft = aft + 1;
      i = i + 1;
    }
  return (aft);
}

float	calc_integer(int bef, char* str)
{
  int	i;
  int	x;
  float	nb;

  if (str[0] == '-')
    i = 1;
  else
    i = 0;
  x = 1;
  nb = 0.f;
  while (bef > 0)
    {
      x = x * 10;
      bef = bef - 1;
    }
  x = x / 10;
  while (x >= 1)
    {
      nb = nb + (float)((str[i] - 48) * x);
      x = x / 10;
      i = i + 1;
    }
  return (nb);
}

float	calc_decimal(int aft, char* str, float nb)
{
  int	i;
  int	x;

  i = 0;
  x = 10;
  while (str[i] != '.' && str[i] != '\0')
    i = i + 1;
  if (str[i] == '.')
    i = i + 1;
  while (aft > 0)
    {
      nb = nb + (float)(str[i] - 48) / x;
      x = x * 10;
      aft = aft - 1;
      i = i + 1;
    }
  return (nb);
}

float	my_getnbr_float(char* str)
{
  int	bef;
  int	aft;
  float	nb;

  bef = len_before(str);
  aft = len_after(str);
  nb = calc_integer(bef, str);
  nb = calc_decimal(aft, str, nb);
  if (str[0] == '-')
    return (-nb);
  return (nb);
}
