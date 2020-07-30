/*
** my_putstr.c for my_putstr in /home/descou_c/CPool_Day04
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Oct  6 09:05:01 2016 Charles Descoust
** Last update Thu Nov 24 14:48:17 2016 Charles Descoust
*/

#include "../include/lib.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
