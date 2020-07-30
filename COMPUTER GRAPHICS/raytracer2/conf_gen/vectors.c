/*
** vectors.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu May  4 14:35:19 2017 Charles Aubert
** Last update Thu May  4 14:56:35 2017 Charles Aubert
*/

#include "../inc/rt2.h"

t_vectors       *create_vectors(t_object **objs)
{
  t_vectors     *vectors;
  int           eye;
  int           light;
  int           i;

  i = 0;
  eye = 0;
  light = 0;
  if ((vectors = malloc(sizeof(t_vectors))) == NULL)
    return (NULL);
  while (objs[i] != NULL)
    {
      if (objs[i]->t == MY_EYE && (eye = 1))
        {
          vectors->eye = objs[i]->pos;
          vectors->r_eye = objs[i]->rot;
        }
      else if (objs[i]->t == MY_LIGHT && (light = 1))
        vectors->light = objs[i]->pos;
      i += 1;
    }
  if (eye != 1 || light != 1)
    return (NULL);
  return (vectors);
}
