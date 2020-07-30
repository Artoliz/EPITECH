/*
** rotate.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/Raytracer1/raytracer1/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Feb 23 09:57:33 2017 Charles Aubert
** Last update Wed May  3 09:14:25 2017 Charles Aubert
*/

#include "../inc/src.h"

sfVector3f	rotate_x(sfVector3f to, float r)
{
  float		y;
  float		z;

  y = to.y;
  z = to.z;
  to.y = y * cos(r) + z * -sin(r);
  to.z = y * sin(r) + z * cos(r);
  return (to);
}

sfVector3f	rotate_y(sfVector3f to, float r)
{
  float		x;
  float		z;

  x = to.x;
  z = to.z;
  to.x = x * cos(r) + z * sin(r);
  to.z = x * -sin(r) + z * cos(r);
  return (to);
}

sfVector3f	rotate_z(sfVector3f to, float r)
{
  float		x;
  float		y;

  x = to.x;
  y = to.y;
  to.x = x * cos(r) + y * -sin(r);
  to.y = x * sin(r) + y * cos(r);
  return (to);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_x(to_rotate, angles.x * PI / 180.0);
  to_rotate = rotate_y(to_rotate, angles.y * PI / 180.0);
  to_rotate = rotate_z(to_rotate, angles.z * PI / 180.0);
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_z(to_rotate, angles.z * PI / 180.0);
  to_rotate = rotate_y(to_rotate, angles.y * PI / 180.0);
  to_rotate = rotate_x(to_rotate, angles.x * PI / 180.0);
  return (to_rotate);
}
