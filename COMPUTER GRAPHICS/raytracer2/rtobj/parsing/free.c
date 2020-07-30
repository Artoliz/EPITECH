/*
** free.c for  in /home/miklox/semestre2/infographie/rt1test
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Wed May 24 12:54:24 2017 Bastien LECUSSAN
** Last update Sun May 28 17:17:10 2017 Charles Descoust
*/

#include "raytracer2.h"

void		free_my_face(t_face_vtx *txt)
{
  t_face_vtx	*tmp;

  while (txt != NULL)
    {
      tmp = txt;
      txt = txt->prev;
      free(tmp->face);
      free(tmp);
    }
}

void		free_list_obj_mtl(t_vtx *list)
{
  if (list->obj->texture != NULL)
    free(list->obj->texture);
  if (list->obj->normal != NULL)
    free(list->obj->normal);
  free_my_face(list->obj->face);
  free(list->obj);
}
