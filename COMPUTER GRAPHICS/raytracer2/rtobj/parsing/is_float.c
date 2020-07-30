/*
** is_float.c for  in /home/miklox/semestre2/infographie/rt1test/parsing
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Wed May 10 10:19:20 2017 Bastien LECUSSAN
** Last update Fri May 26 12:06:33 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

int	is_float(char *str)
{
  int	count;
  int	point;

  count = 0;
  point = 0;
  while (str[count] != '.' && str[count] != '\0')
    count += 1;
  if (count > 9)
    return (-1);
  count = 0;
  if (str[0] == '-')
    count = 1;
  while (str[count] != '\0')
    {
      if (((str[count] < '0' || str[count] > '9') && str[count] != '.')
	  || (str[count] == '.' && count == 0))
	return (-1);
      if (str[count] == '.')
	point += 1;
      count += 1;
    }
  if (point > 1)
    return (-1);
  return (0);
}
