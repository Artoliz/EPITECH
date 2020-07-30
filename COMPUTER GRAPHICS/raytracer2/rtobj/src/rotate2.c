/*
** rotate2.c for  in /home/miklox/semestre2/infographie/raytracer2
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue Mar  7 15:13:58 2017 Bastien LECUSSAN
** Last update Sat May 27 12:53:25 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

void	rotate_xyz_inv_obj(sfVector3f *to_rotate,
			   sfVector3f *translations)
{
  translations->x = -translations->x;
  translations->y = -translations->y;
  translations->z = -translations->z;
  rotate_xyz_obj(to_rotate, translations);
  translations->x = -translations->x;
  translations->y = -translations->y;
  translations->z = -translations->z;
}
