/*
** calc_dir_vector.c for  in /home/miklox/semestre1/infographie/bsraytracer1
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Mon Feb  6 18:28:09 2017 Bastien LECUSSAN
** Last update Sat May 27 12:52:44 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

void		calc_dir_vector_obj(float dist_to_plane,
				    sfVector2i *screen_size,
				    sfVector2i *screen_pos,
				    sfVector3f *pos)
{
  pos->x = dist_to_plane;
  pos->y = ((float)screen_size->x / 2.f) - (float)screen_pos->x;
  pos->z = ((float)screen_size->y / 2.f) - (float)screen_pos->y;
}
