/*
** calc_dir_vector.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/Raytracer1/bsraytracer1
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Feb  6 18:24:59 2017 Charles Aubert
** Last update Wed May  3 09:13:42 2017 Charles Aubert
*/

#include "../inc/src.h"

sfVector3f	calc_dir_vector(float dist,
				sfVector2i screen_size, sfVector2f screen_pos)
{
  sfVector3f	result;

  result.x = dist;
  result.y = (float)(screen_size.x / 2) - (float)screen_pos.x;
  result.z = (float)(screen_size.y / 2) - (float)screen_pos.y;
  return (result);
}
