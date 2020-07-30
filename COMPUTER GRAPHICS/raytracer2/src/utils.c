/*
** utils.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/Raytracer1/raytracer1/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Mar  7 12:22:40 2017 Charles Aubert
** Last update Tue May 23 15:26:21 2017 Charles Aubert
*/

#include "../inc/src.h"

int     double_sign(double x)
{
  if (x < -MY_PRES)
    return (-1);
  return (x > MY_PRES);
}

int		double_swap(double *a, double *b)
{
  double	tmp;

  tmp = *b;
  *b = *a;
  *a = tmp;
  return (0);
}

sfVector3f      rotate_xyz_in(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_x(to_rotate, -angles.x * PI / 180.0);
  to_rotate = rotate_y(to_rotate, -angles.y * PI / 180.0);
  to_rotate = rotate_z(to_rotate, -angles.z * PI / 180.0);
  return (to_rotate);
}

sfVector3f      rotate_zyx_in(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_z(to_rotate, -angles.z * PI / 180.0);
  to_rotate = rotate_x(to_rotate, -angles.x * PI / 180.0);
  to_rotate = rotate_y(to_rotate, -angles.y * PI / 180.0);
  return (to_rotate);
}

sfVector3f	create_vect3(float a, float b, float c)
{
  sfVector3f	res;

  res.x = a;
  res.y = b;
  res.z = c;
  return (res);
}
