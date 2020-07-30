/*
** rotate.c for rotate in /home/descou_c/Graphic/raytracer1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 08:56:23 2017 Charles Descoust
** Last update Mon Mar  6 10:47:51 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	rotate_x(sfVector3f to, float x)
{
  float		a;
  float		b;

  a = to.y;
  b = to.z;
  to.y = a * cos(x) + b * -sin(x);
  to.z = a * sin(x) + b * cos(x);
  return (to);
}

sfVector3f	rotate_y(sfVector3f to, float y)
{
  float		a;
  float		b;

  a = to.x;
  b = to.z;
  to.x = a * cos(y) + b * sin(y);
  to.z = a * -sin(y) + b * cos(y);
  return (to);
}

sfVector3f	rotate_z(sfVector3f to, float z)
{
  float		a;
  float		b;

  a = to.x;
  b = to.y;
  to.x = a * cos(z) + b * -sin(z);
  to.y = a * sin(z) + b * cos(z);
  return (to);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_x(to_rotate, angles.x * M_PI / 180);
  to_rotate = rotate_y(to_rotate, angles.y * M_PI / 180);
  to_rotate = rotate_z(to_rotate, angles.z * M_PI / 180);
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_z(to_rotate, angles.z * M_PI / 180);
  to_rotate = rotate_y(to_rotate, angles.y * M_PI / 180);
  to_rotate = rotate_x(to_rotate, angles.x * M_PI / 180);
  return (to_rotate);
}
