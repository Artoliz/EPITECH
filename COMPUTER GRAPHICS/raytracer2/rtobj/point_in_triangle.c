/*
** test.c for  in /home/miklox/semestre2/infographie/rt1test
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Thu May  4 13:28:04 2017 Bastien LECUSSAN
** Last update Sat May 27 12:07:45 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

int             point_is_in(t_my_struct *st,
			    t_obj *obj, t_face *face)
{
  t_point_tri   pt;
  float         det;
  float         u;
  float         v;

  sub_3fptr(&obj->pos[face[2].v - 1].pos,
	    &obj->pos[face[0].v - 1].pos, &pt.point2);
  sub_3fptr(&obj->pos[face[1].v - 1].pos,
	    &obj->pos[face[0].v - 1].pos, &pt.point1);
  prod_vect(&st->vector, &pt.point2, &pt.vec1);
  det = prod_scal(&pt.point1, &pt.vec1);
  if (det > -0.f && det < 0.f)
    return (-1);
  sub_3fptr(&st->eye, &obj->pos[face[0].v - 1].pos, &pt.vec2);
  u = prod_scal(&pt.vec2, &pt.vec1) / det;
  if (u < 0.f || u > 1.f)
    return (-1);
  prod_vect(&pt.vec2, &pt.point1, &pt.vec3);
  v = prod_scal(&st->vector, &pt.vec3) / det;
  if (v < 0.f || u + v > 1.f)
    return (-1);
  return (0);
}
