/*
** light.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/Raytracer1/raytracer1/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Feb 27 11:14:07 2017 Charles Aubert
** Last update Mon May  8 15:07:17 2017 Charles Aubert
*/

#include "../inc/src.h"

sfVector3f      normalize(sfVector3f v)
{
  float         norme;

  norme = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
  v.x /= norme;
  v.y /= norme;
  v.z /= norme;
  return (v);
}

sfVector3f	calc_dir_light(sfVector3f pos, sfVector3f light)
{
  sfVector3f	result;

  result.x = light.x - pos.x;
  result.y = light.y - pos.y;
  result.z = light.z - pos.z;
  return (result);
}

float	get_light_coef(sfVector3f l_v, sfVector3f n_v)
{
  float	cos;

  l_v = normalize(l_v);
  n_v = normalize(n_v);
  cos = l_v.x * n_v.x + l_v.y * n_v.y + l_v.z * n_v.z;
  if (cos > 0 && cos <= 1)
    return (cos);
  else if (cos > 1.0)
    return (1.0);
  else
    return (0.0);
}
