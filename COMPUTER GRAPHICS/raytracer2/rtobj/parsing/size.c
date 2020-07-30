/*
** size.c for  in /home/miklox/semestre2/infographie/rt1test
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Fri May 26 18:38:53 2017 Bastien LECUSSAN
** Last update Sun May 28 18:40:25 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

float             max_size_width(t_obj *obj, sfVector3f *eye, float coef2)
{
  int           count;
  float         coef;
  float         nb_max;
  float         nb_min;

  count = 0;
  nb_max = 0;
  nb_min = 0;
  while (count < obj->pos_nb)
    {
      if (obj->pos[count].pos.y > 0 && obj->pos[count].pos.y > nb_max)
	nb_max = obj->pos[count].pos.y;
      else if (obj->pos[count].pos.y < 0 && obj->pos[count].pos.y < nb_min)
	nb_min = obj->pos[count].pos.y;
      count += 1;
    }
  if (nb_max - nb_min != 0.f)
    coef = ((float)S_WIDTH * (3.f / 5.f)) / (nb_max - nb_min);
  else
    return (1);
  eye->y += (nb_max - nb_min) / 2.f;
  if (coef < coef2)
    return (coef);
  return (coef2);
}

int             get_new_size_obj(t_obj *obj, sfVector3f *eye)
{
  int           count;
  float         coef;
  float         nb_max;
  float         nb_min;

  count = 0;
  nb_max = 0;
  nb_min = 0;
  while (count < obj->pos_nb)
    {
      if (obj->pos[count].pos.z > 0 && obj->pos[count].pos.z > nb_max)
	nb_max = obj->pos[count].pos.z;
      else if (obj->pos[count].pos.z < 0 && obj->pos[count].pos.z < nb_min)
	nb_min = obj->pos[count].pos.z;
      count += 1;
    }
  if (nb_max - nb_min != 0.f)
    coef = ((float)S_HEIGHT * (3.f / 5.f)) / (nb_max - nb_min);
  else
    return (0);
  coef = max_size_width(obj, eye, coef);
  eye->x = -DIST / coef;
  return (0);
}
