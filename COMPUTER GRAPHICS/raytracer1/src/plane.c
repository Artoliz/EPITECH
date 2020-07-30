/*
** plane.c for plane in /home/descou_c/Graphic/raytracer1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 09:01:22 2017 Charles Descoust
** Last update Thu Feb 23 16:37:46 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	N;

  N.x = 0;
  N.y = 0;
  if (upward == 0)
    N.z = -100;
  else if (upward == 1)
    N.z = 100;
  return (N);
}

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float k;

  if (dir_vector.z == 0)
    return (-1.0f);
  k = -(eye_pos.z / dir_vector.z);
  if (k < 0)
    return (-1.0f);
  return (k);
}
