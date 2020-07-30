/*
** get_equation_face.c for  in /home/miklox/semestre2/infographie/rt1test
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Wed Apr 26 10:28:46 2017 Bastien LECUSSAN
** Last update Sat May 27 11:46:29 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

t_face_tools    *get_f_tools_norm(t_face_tools *f_tools, t_face *face,
				  t_obj *obj)
{
  sfVector3f    vector1;
  sfVector3f    vector2;

  vector1.x = obj->pos[face[1].v - 1].pos.x - obj->pos[face[0].v - 1].pos.x;
  vector1.y = obj->pos[face[1].v - 1].pos.y - obj->pos[face[0].v - 1].pos.y;
  vector1.z = obj->pos[face[1].v - 1].pos.z - obj->pos[face[0].v - 1].pos.z;
  vector2.x = obj->pos[face[2].v - 1].pos.x - obj->pos[face[1].v - 1].pos.x;
  vector2.y = obj->pos[face[2].v - 1].pos.y - obj->pos[face[1].v - 1].pos.y;
  vector2.z = obj->pos[face[2].v - 1].pos.z - obj->pos[face[1].v - 1].pos.z;
  f_tools->norm_p.x = (vector1.y * vector2.z) - (vector1.z * vector2.y);
  f_tools->norm_p.y = (vector1.z * vector2.x) - (vector1.x * vector2.z);
  f_tools->norm_p.z = (vector1.x * vector2.y) - (vector1.y * vector2.x);
  return (f_tools);
}

t_face_tools	*get_f_tools(t_face_tools *f_tools, t_face_vtx *face,
			     t_obj *obj)
{
  if (obj->normal != NULL)
    {
      f_tools->norm_p.x = ((float)obj->normal[face->face[0].vn - 1].normal.x
			   + (float)obj->normal[face->face[1].vn - 1].normal.x
			   + (float)obj->normal[face->face[2].vn - 1].normal.x)
	/ (float)3;
      f_tools->norm_p.y = ((float)obj->normal[face->face[0].vn - 1].normal.y
			   + (float)obj->normal[face->face[1].vn - 1].normal.y
			   + (float)obj->normal[face->face[2].vn - 1].normal.y)
	/ (float)3;
      f_tools->norm_p.z = ((float)obj->normal[face->face[0].vn - 1].normal.z
			   + (float)obj->normal[face->face[1].vn - 1].normal.z
			   + (float)obj->normal[face->face[2].vn - 1].normal.z)
	/ (float)3;
    }
  else
    f_tools = get_f_tools_norm(f_tools, face->face, obj);
  f_tools->inconnu.x = -obj->pos[face->face[0].v - 1].pos.x;
  f_tools->inconnu.y = -obj->pos[face->face[0].v - 1].pos.y;
  f_tools->inconnu.z = -obj->pos[face->face[0].v - 1].pos.z;
  return (f_tools);
}

t_obj		*get_equation(t_obj *obj)
{
  t_face_vtx	*tmp;
  t_face_vtx	*save;
  t_face_tools	f_tools;

  tmp = obj->face;
  save = NULL;
  while (tmp != NULL)
    {
      if ((tmp->face_equa =
	   malloc(sizeof(*tmp->face_equa))) == NULL)
	return (NULL);
      get_f_tools(&f_tools, tmp, obj);
      tmp->face_equa->a = f_tools.norm_p.x;
      tmp->face_equa->b = f_tools.norm_p.y;
      tmp->face_equa->c = f_tools.norm_p.z;
      tmp->face_equa->d = (f_tools.norm_p.x * f_tools.inconnu.x)
	+ (f_tools.norm_p.y * f_tools.inconnu.y)
	+ (f_tools.norm_p.z * f_tools.inconnu.z);
      save = tmp;
      tmp = tmp->prev;
    }
  while (save->next != NULL)
    save = save->next;
  obj->face = save;
  return (obj);
}
