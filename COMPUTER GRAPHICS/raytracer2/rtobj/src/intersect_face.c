/*
** intersect_plan.c for  in /home/miklox/semestre2/infographie/rt1test
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue Apr 25 12:16:51 2017 Bastien LECUSSAN
** Last update Sat May 27 22:09:03 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

sfVector3f	*my_middle(t_obj *obj, t_face_vtx *face,
			   sfVector3f *res)
{
  res->x = (obj->pos[face->face[0].v - 1].pos.x
	   + obj->pos[face->face[1].v - 1].pos.x
	   + obj->pos[face->face[2].v - 1].pos.x) / (float)3;
  res->y = (obj->pos[face->face[0].v - 1].pos.y
	   + obj->pos[face->face[1].v - 1].pos.y
	   + obj->pos[face->face[2].v - 1].pos.y) / (float)3;
  res->z = (obj->pos[face->face[0].v - 1].pos.y
	   + obj->pos[face->face[1].v - 1].pos.y
	   + obj->pos[face->face[2].v - 1].pos.y) / (float)3;
  return (res);
}

float		intersect_face(t_face_vtx *a, t_my_struct *my_sct,
			       t_obj *obj)
{
  float		tools;
  float		dist;

  if (point_is_in(my_sct, obj, a->face) == 0)
    {
      if ((tools = a->face_equa->a * my_sct->vector.x + a->face_equa->b
	   * my_sct->vector.y + a->face_equa->c * my_sct->vector.z) != 0)
	dist = -(a->face_equa->a * my_sct->eye.x + a->face_equa->b
		 * my_sct->eye.y + a->face_equa->c * my_sct->eye.z
		 + a->face_equa->d) / tools;
      else
	return (-1);
      if (dist > 0.0)
	return (dist);
    }
  return (-1);
}
