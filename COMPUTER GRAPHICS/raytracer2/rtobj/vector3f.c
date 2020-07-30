/*
** vector3f2.c for  in /home/miklox/semestre2/infographie/rt1test
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Thu Apr 27 15:25:21 2017 Bastien LECUSSAN
** Last update Sat May 27 12:07:55 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

float		distance_vect(sfVector3f *vect)
{
  return (sqrt(pow(vect->x, 2) + pow(vect->y, 2) + pow(vect->z, 2)));
}

sfVector3f      *sub_3fptr(sfVector3f *vect1, sfVector3f *vect2,
			   sfVector3f *res)
{
  res->x = vect1->x - vect2->x;
  res->y = vect1->y - vect2->y;
  res->z = vect1->z - vect2->z;
  return (res);
}

float	prod_scal(sfVector3f *vect1, sfVector3f *vect2)
{
  return (vect1->x * vect2->x + vect1->y * vect2->y + vect1->z * vect2->z);
}

sfVector3f	m_3f(sfVector3f vect1, sfVector3f *vect2)
{
  sfVector3f	res;

  res.x = vect1.x * vect2->x;
  res.y = vect1.y * vect2->y;
  res.z = vect1.z * vect2->z;
  return (res);
}

sfVector3f	*prod_vect(sfVector3f *vect1, sfVector3f *vect2,
			    sfVector3f *res)
{
  res->x = (vect1->y * vect2->z) - (vect1->z * vect2->y);
  res->y = (vect1->z * vect2->x) - (vect1->x * vect2->z);
  res->z = (vect1->x * vect2->y) - (vect1->y * vect2->x);
  return (res);
}
