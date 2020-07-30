/*
** bellepou.c for bellepou in /home/descou_c/Graphic/wireframe
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Dec  9 14:49:47 2016 Charles Descoust
** Last update Sun Dec 11 16:50:20 2016 Charles Descoust
*/

#include "include/wire.h"

sfVector3f	transfert(int x, int y, int z)
{
  sfVector3f    pos3d;

  pos3d.x = x;
  pos3d.y = y;
  pos3d.z = z;
  return (pos3d);
}

sfVector2f	transform(sfVector2i src)
{
  sfVector2f	dest;

  dest.x = src.x;
  dest.y = src.y;
  return (dest);
}
