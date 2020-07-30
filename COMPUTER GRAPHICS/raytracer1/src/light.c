/*
** light.c for light in /home/descou_c/Graphic/raytracer1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 09:21:57 2017 Charles Descoust
** Last update Mon Mar 13 11:27:01 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	normalize_vect(sfVector3f vect)
{
  float         length;

  length = sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z);
  if (length != 0)
    {
      vect.x = vect.x / length;
      vect.y = vect.y / length;
      vect.z = vect.z / length;
    }
  return (vect);
}

sfVector3f	calc(sfVector3f eye_pos, sfVector3f dir_vector, float k)
{
  sfVector3f	new_pos;

  new_pos.x = eye_pos.x + (k * dir_vector.x);
  new_pos.y = eye_pos.y + (k * dir_vector.y);
  new_pos.z = eye_pos.z + (k * dir_vector.z);
  return (new_pos);
}

sfVector3f	calc_dir_light(sfVector3f new_pos, sfVector3f light_pos)
{
  sfVector3f	dir_light;

  dir_light.x = light_pos.x - new_pos.x;
  dir_light.y = light_pos.y - new_pos.y;
  dir_light.z = light_pos.z - new_pos.z;
  return (dir_light);
}

float	get_light_coef(sfVector3f light_dir, sfVector3f N)
{
  float	coef;

  N = normalize_vect(N);
  light_dir = normalize_vect(light_dir);
  coef = N.x * light_dir.x + N.y * light_dir.y + N.z * light_dir.z;
  if (coef > 0 && coef <= 1)
    return (coef);
  else if (coef > 1)
    return (1);
  else
    return (0);
}
