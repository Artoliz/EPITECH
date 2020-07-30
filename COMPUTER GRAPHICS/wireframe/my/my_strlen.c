/*
** my_strlen.c for my_strlen in /home/descou_c/CPool_Day04
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Oct  6 09:06:04 2016 Charles Descoust
** Last update Thu Nov 24 14:50:52 2016 Charles Descoust
*/

#include "../include/lib.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
