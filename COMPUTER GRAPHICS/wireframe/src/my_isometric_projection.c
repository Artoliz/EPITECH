/*
** my_isometric_projection.c for my_isometric_projection in /home/descou_c/Graphic/wireframe
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Dec  9 18:04:41 2016 Charles Descoust
** Last update Sat Dec 10 10:17:48 2016 Charles Descoust
*/

#include "../include/wire.h"

sfVector2i	my_isometric_projection(sfVector3f pos3d)
{
  sfVector2i	pos2d;

  pos2d.x = pos3d.x;
  pos2d.y = pos3d.y;
  return (pos2d);
}
