/*
** translate.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/Raytracer1/raytracer1/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed Feb 22 22:42:08 2017 Charles Aubert
** Last update Thu May 25 09:28:57 2017 Charles Aubert
*/

#include "../inc/src.h"

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	result;

  result.x = to_translate.x + translations.x;
  result.y = to_translate.y + translations.y;
  result.z = to_translate.z + translations.z;
  return (result);
}

sfVector3f	translate_in(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	result;

  result.x = to_translate.x - translations.x;
  result.y = to_translate.y - translations.y;
  result.z = to_translate.z - translations.z;
  return (result);
}

sfVector3f	multiply_vec(sfVector3f v, double m)
{
  sfVector3f	result;

  result.x = v.x * m;
  result.y = v.y * m;
  result.z = v.z * m;
  return (result);
}
