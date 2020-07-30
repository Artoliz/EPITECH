/*
** my_putchar.c for my_putchar in /home/descou_c/CPool_Day07/lib/my
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Oct 11 09:36:38 2016 Charles Descoust
** Last update Thu Nov 24 14:47:52 2016 Charles Descoust
*/

#include "../include/lib.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
