/*
** utils.c for utils in /home/descou_c/Graphic/raytracer1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Mar  7 12:20:56 2017 Charles Descoust
** Last update Tue Mar 14 13:15:43 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	rotate_xyz_inv(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_x(to_rotate, -(angles.x * M_PI / 180));
  to_rotate = rotate_y(to_rotate, -(angles.y * M_PI / 180));
  to_rotate = rotate_z(to_rotate, -(angles.z * M_PI / 180));
  return (to_rotate);
}
