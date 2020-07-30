/*
** basic_objs.c for basic_objs in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Mar  1 10:07:20 2017 Charles Descoust
** Last update Tue Mar 21 14:24:04 2017 Charles Descoust
*/

#include "inc/my.h"

t_my_object*	add_basic_plane(t_my_object* obj)
{
  t_my_object*	new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->name = "PLANE";
  new->coord.x = 0;
  new->coord.y = 0;
  new->coord.z = -30;
  new->rotate.x = 0;
  new->rotate.y = 0;
  new->rotate.z = 0;
  new->radius = 0;
  new->color = sfCyan;
  new->next = obj;
  obj = new;
  return (obj);
}

t_my_object*	add_basic_sphere(t_my_object* obj)
{
  t_my_object*  new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->name = "SPHERE";
  new->coord.x = 0;
  new->coord.y = 0;
  new->coord.z = 0;
  new->rotate.x = 0;
  new->rotate.y = 0;
  new->rotate.z = 0;
  new->radius = 60;
  new->color = sfRed;
  new->next = obj;
  obj = new;
  return (obj);
}

t_my_object*	init_basic_objs(t_my_object* obj)
{
  if ((obj = add_basic_sphere(obj)) == NULL)
    return (NULL);
  if ((obj = add_basic_plane(obj)) == NULL)
    return (NULL);
  obj->next->next = NULL;
  return (obj);
}
