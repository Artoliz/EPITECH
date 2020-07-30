/*
** my_put.c for my_put in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Mar  8 16:40:58 2017 Charles Descoust
** Last update Wed Mar  8 16:41:28 2017 Charles Descoust
*/

#include "inc/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char* str)
{
  write(1, str, my_strlen(str));
}
