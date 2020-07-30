/*
1;4402;0c** my_parallel_projection.c for my_parallel_projection in /home/descou_c/Graphic/bswireframe_no
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Nov 15 11:32:27 2016 Charles Descoust
** Last update Sun Dec 11 17:18:48 2016 Charles Descoust
*/

#include "../include/wire.h"
#include <math.h>

sfVector2i	my_parallel_projection(sfVector3f pos3d, float angle)
{
  sfVector2i	pos2d;
  float		a;
  float		b;
  float		c;

  a = 300 + (30 / sqrt(2)) * (pos3d.x - pos3d.y);
  b = 500 - (30 * sin(angle) / sqrt(2)) * (pos3d.x + pos3d.y);
  c = b - (30 * cos(angle)) * pos3d.z;
  pos2d.x = a;
  pos2d.y = c;
  return (pos2d);
}
