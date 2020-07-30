/*
** linked_list2.c for linked_list2 in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Mar 14 13:10:55 2017 Charles Descoust
** Last update Tue Mar 14 13:12:40 2017 Charles Descoust
*/

#include "inc/my.h"

t_my_object	*add_maillon_next(char** c, t_my_object* new, int *i)
{
  if (*i == 7)
    {
      if (my_strisfloat(c[*i]) == 84)
        return (NULL);
      new->radius = my_getnbr_float(c[*i]);
      *i = *i + 1;
    }
  if (*i == 8)
    {
      if ((new = add_color(c, i, new)) == NULL)
        return (NULL);
    }
  return (new);
}
