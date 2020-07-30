/*
** translate.c for translate in /home/descou_c/Graphic/raytracer1/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 08:55:33 2017 Charles Descoust
** Last update Wed Feb 22 18:04:41 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector3f	translate_inv(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x = to_translate.x - translations.x;
  to_translate.y = to_translate.y - translations.y;
  to_translate.z = to_translate.z - translations.z;
  return (to_translate);
}

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x = to_translate.x + translations.x;
  to_translate.y = to_translate.y + translations.y;
  to_translate.z = to_translate.z + translations.z;
  return (to_translate);
}
