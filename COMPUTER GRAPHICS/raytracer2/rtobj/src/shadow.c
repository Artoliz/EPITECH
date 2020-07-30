/*
** shadow.c for  in /home/miklox/semestre2/infographie/raytracer1
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Thu Mar  9 13:10:16 2017 Bastien LECUSSAN
** Last update Sat May 27 12:42:47 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

void	get_eye_vector(sfVector3f *eye, sfVector3f *vector,
		       sfVector3f *origin, sfVector3f *dir_vect)
{
  eye->x = origin->x;
  eye->y = origin->y;
  eye->z = origin->z;
  vector->x = dir_vect->x;
  vector->y = dir_vect->y;
  vector->z = dir_vect->z;
}

float		get_shadow_obj(sfVector3f *origins, sfVector3f *dir_vect,
			       t_frame *window, t_face_vtx *my_face)
{
  t_smallest	dist;
  t_face_vtx	*tmp;
  t_my_struct	my_sct;

  get_eye_vector(&my_sct.eye, &my_sct.vector, origins, dir_vect);
  dist.dist = -1;
  tmp = window->scene->face;
  while (tmp != NULL)
    {
      if (tmp != my_face)
	if ((dist.res = intersect_face(tmp,
				       &my_sct, window->scene)) != -1)
	  {
	    if (dist.res < dist.dist || dist.dist == -1)
	      dist.dist = dist.res;
	  }
      tmp = tmp->prev;
    }
  if (dist.dist >= 1 || dist.dist <= 0)
    return (-1);
  return (dist.dist);
}
