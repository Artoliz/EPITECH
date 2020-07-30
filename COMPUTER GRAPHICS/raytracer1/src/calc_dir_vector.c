/*
** raytrace.c for raytrace in /home/descou_c/Graphic/RTV1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Feb  6 17:23:38 2017 Charles Descoust
** Last update Fri Feb 24 10:14:03 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screenSize,
				sfVector2i screenPos)
{
  sfVector3f	dir_vector;

  dir_vector.x = dist_to_plane;
  dir_vector.y = (float)((screenSize.x / 2.f) - screenPos.x);
  dir_vector.z = (float)((screenSize.y / 2.f) - screenPos.y);
  return (dir_vector);
}
