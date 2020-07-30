/*
** light.c for  in /home/miklox/semestre2/infographie/raytracer2/src
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue Feb 14 09:52:14 2017 Bastien LECUSSAN
** Last update Sun May 28 17:52:33 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

sfColor		get_my_color(t_frame *window, t_my_struct *my_sct,
			     float dist, t_face_vtx *face)
{
  float		coef;
  sfVector3f	normal;
  sfVector3f	intersect;
  sfVector3f	light;
  sfVector3f	rotate;
  float		shadow;

  normal.x = face->face_equa->a;
  normal.y = face->face_equa->b;
  normal.z = face->face_equa->c;
  rotate.x = ROTATION_SCENE_X;
  rotate.y = ROTATION_SCENE_Y;
  rotate.z = ROTATION_SCENE_Z;
  intersect = get_pos_intersect(&my_sct->eye, &my_sct->vector, dist);
  light = get_light_vector(&intersect, &window->light);
  shadow = get_shadow_obj(&intersect, &light, window, face);
  rotate_xyz_obj(&intersect, &rotate);
  rotate_xyz_obj(&window->light, &rotate);
  coef = get_light_coef_obj(&light, &normal);
  return (apply_my_color(sfRed, coef, shadow));
}

sfVector3f	get_pos_intersect(sfVector3f *origins,
				  sfVector3f *vect,
				  float dist)
{
  sfVector3f	pos;

  pos.x = origins->x + vect->x * dist;
  pos.y = origins->y + vect->y * dist;
  pos.z = origins->z + vect->z * dist;
  return (pos);
}

sfVector3f	get_light_vector(sfVector3f *intersect,
				 sfVector3f *light_pos)
{
  sfVector3f	Light;

  Light.x = light_pos->x - intersect->x;
  Light.y = light_pos->y - intersect->y;
  Light.z = light_pos->z - intersect->z;
  return (Light);
}

float	get_light_coef_obj(sfVector3f *light_vector,
			   sfVector3f *normal_vector)
{
  float	coef;
  float	norme;

  norme = sqrt(pow(light_vector->x, 2) + pow(light_vector->y, 2)
	       + pow(light_vector->z, 2));
  light_vector->x /= norme;
  light_vector->y /= norme;
  light_vector->z /= norme;
  norme = sqrt(pow(normal_vector->x, 2) + pow(normal_vector->y, 2)
	       + pow(normal_vector->z, 2));
  normal_vector->x /= norme;
  normal_vector->y /= norme;
  normal_vector->z /= norme;
  coef = light_vector->x * normal_vector->x
    + light_vector->y * normal_vector->y
    + light_vector->z * normal_vector->z;
  if (coef > 0 && coef <= 1)
    return (coef);
  if (coef > 1)
    return (1.0);
  if (coef <= 0)
    return (0.0);
  return (0);
}
