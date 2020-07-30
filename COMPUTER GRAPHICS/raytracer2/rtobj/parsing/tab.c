/*
** tab.c for  in /home/miklox/semestre2/infographie/rt1test
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Thu May 25 23:20:59 2017 Bastien LECUSSAN
** Last update Thu May 25 23:22:35 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

t_obj	*get_end_tab_obj(t_obj *obj, float coef)
{
  int	count;

  count = 0;
  while (count < obj->pos_nb)
    {
      obj->pos[count].pos.x *= coef;
      obj->pos[count].pos.y *= coef;
      obj->pos[count].pos.z *= coef;
      count += 1;
    }
  return (obj);
}
