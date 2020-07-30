/*
** color.c for  in /home/miklox/semestre2/infographie/raytracer2
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue Mar  7 15:44:36 2017 Bastien LECUSSAN
** Last update Sat May 27 12:52:58 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

sfColor		apply_my_color(sfColor red, float coef,
			       float shadow)
{
  sfColor	my_color;

  my_color.r = red.r * coef;
  my_color.g = red.g * coef;
  my_color.b = red.b * coef;
  if (shadow > 0)
    my_color.a = (red.a * shadow);
  else
    my_color.a = red.a * coef;
  return (my_color);
}
