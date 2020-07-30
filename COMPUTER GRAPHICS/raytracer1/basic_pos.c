/*
** basic_pos.c for basic_pos in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Feb 24 16:41:11 2017 Charles Descoust
** Last update Sat Mar 11 14:55:20 2017 Charles Descoust
*/

#include "inc/my.h"

t_my_pos	init_basic()
{
  t_my_pos	basicPos;

  basicPos.screen_size.x = WIDTH;
  basicPos.screen_size.y = HEIGHT;
  basicPos.screen_pos.x = 0;
  basicPos.screen_pos.y = 0;
  basicPos.eye_pos.x = -300;
  basicPos.eye_pos.y = 0;
  basicPos.eye_pos.z = 0;
  basicPos.eye_rotate.x = 0;
  basicPos.eye_rotate.y = 0;
  basicPos.eye_rotate.z = 0;
  basicPos.light_pos.x = -300;
  basicPos.light_pos.y = 0;
  basicPos.light_pos.z = 150;
  return (basicPos);
}

t_my_pos	add_basic()
{
  t_my_pos      basicPos;

  basicPos.screen_size.x = WIDTH;
  basicPos.screen_size.y = HEIGHT;
  basicPos.screen_pos.x = 0;
  basicPos.screen_pos.y = 0;
  return (basicPos);
}

t_my_pos	add_my_basic_pos(t_my_object* obj)
{
  t_my_pos      basicPos;

  basicPos = add_basic();
  while (obj->next != NULL)
    {
      if (my_strcmp(obj->name, "EYE") == 0)
        {
          basicPos.eye_pos.x = obj->coord.x;
          basicPos.eye_pos.y = obj->coord.y;
          basicPos.eye_pos.z = obj->coord.z;
          basicPos.eye_rotate.x = obj->rotate.x;
          basicPos.eye_rotate.y = obj->rotate.y;
          basicPos.eye_rotate.z = obj->rotate.z;
        }
      if (my_strcmp(obj->name, "LIGHT") == 0)
        {
          basicPos.light_pos.x = obj->coord.x;
          basicPos.light_pos.y = obj->coord.y;
          basicPos.light_pos.z = obj->coord.z;
        }
      obj = obj->next;
    }
  return (basicPos);
}
