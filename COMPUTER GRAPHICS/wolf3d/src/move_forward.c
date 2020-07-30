/*
** move_forward.c for move_forward in /home/descou_c/Graphic/bswolf3d/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec 13 09:48:19 2016 Charles Descoust
** Last update Thu Jan 12 09:27:54 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  pos.x = pos.x + distance * cos(direction * (M_PI / 180.f));
  pos.y = pos.y + distance * sin(direction * (M_PI / 180.f));
  return (pos);
}
