/*
** rotate.c for  in /home/miklox/semestre2/infographie/raytracer2/src
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue Feb 14 09:50:24 2017 Bastien LECUSSAN
** Last update Sat May 27 12:53:19 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

void		rotate_x_obj(sfVector3f *to_rotate,
			 float sin, float cos)
{
  float		save1;
  float		save2;

  save1 = to_rotate->y;
  save2 = to_rotate->z;
  to_rotate->y = (cos * save1) - (sin * save2);
  to_rotate->z = (sin * save1) + (cos * save2);
}

void		rotate_y_obj(sfVector3f *to_rotate,
			 float sin, float cos)
{
  float		save1;
  float		save2;

  save1 = to_rotate->x;
  save2 = to_rotate->z;
  to_rotate->x = (cos * save1) + (sin * save2);
  to_rotate->z = (-sin * save1) + (cos * save2);
}

void		rotate_z_obj(sfVector3f *to_rotate,
			 float sin, float cos)
{
  float		save1;
  float		save2;

  save1 = to_rotate->x;
  save2 = to_rotate->y;
  to_rotate->x = (cos * save1) - (sin * save2);
  to_rotate->y = (sin * save1) + (cos * save2);
}

void		rotate_xyz_obj(sfVector3f *to_rotate,
			   sfVector3f *angles)
{
  float		cos_x;
  float		sin_x;
  float		cos_y;
  float		sin_y;
  float		cos_z;
  float		sin_z;

  cos_x = cos(angles->x * M_PI / 180.f);
  sin_x = sin(angles->x * M_PI / 180.f);
  cos_y = cos(angles->y * M_PI / 180.f);
  sin_y = sin(angles->y * M_PI / 180.f);
  cos_z = cos(angles->z * M_PI / 180.f);
  sin_z = sin(angles->z * M_PI / 180.f);
  rotate_x_obj(to_rotate, sin_x, cos_x);
  rotate_y_obj(to_rotate, sin_y, cos_y);
  rotate_z_obj(to_rotate, sin_z, cos_z);
}
