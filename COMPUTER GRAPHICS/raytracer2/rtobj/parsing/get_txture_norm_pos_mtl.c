/*
** get_txture_norm_pos_mtl.c for  in /home/miklox/semestre2/infographie/rt1test/parsing
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Wed May 24 13:26:12 2017 Bastien LECUSSAN
** Last update Sat May 27 23:42:24 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

t_pos_vtx       *get_obj_vertice(char *str, t_pos_vtx *tmp)
{
  t_pos_vtx     *pos;
  char          **line;

  if ((pos = malloc(sizeof(*pos))) == NULL)
    return (print_error("Malloc failed.\n"));
  if ((line = my_split(str, " \t")) == NULL)
    return (print_error("Malloc failed.\n"));
  if (size_array_char(line) != 4)
    return (print_error("Invalid params number for the vertice position.\n"));
  if (is_float(line[1]) != 0 || is_float(line[2]) != 0
      || is_float(line[3]) != 0)
    return (print_error("A param isn't a valid number into the position.\n"));
  pos->pos.x = my_getfloat(line[1]);
  pos->pos.y = my_getfloat(line[2]);
  pos->pos.z = my_getfloat(line[3]);
  free_array_char(line, 0);
  pos->next = tmp;
  return (pos);
}

t_texture_vtx   *get_obj_texture(char *str, t_texture_vtx *tmp)
{
  t_texture_vtx *txt;
  char          **line;

  if ((txt = malloc(sizeof(*txt))) == NULL)
    return (print_error("Malloc failed.\n"));
  if ((line = my_split(str, " \t")) == NULL)
    return (print_error("Malloc failed.\n"));
  if (size_array_char(line) > 4)
    return (print_error("Invalide number param for the texture\n"));
  txt->texture.x = my_getfloat(line[1]);
  txt->texture.y = my_getfloat(line[2]);
  free_array_char(line, 0);
  txt->next = tmp;
  return (txt);
}

t_normal_vtx    *get_obj_normal(char *str, t_normal_vtx *tmp)
{
  t_normal_vtx  *normal;
  char          **line;

  if ((normal = malloc(sizeof(*normal))) == NULL)
    return (print_error("Malloc failed.\n"));
  if ((line = my_split(str, " \t")) == NULL)
    return (print_error("Malloc failed.\n"));
  if (size_array_char(line) != 4)
    return (print_error("Invalid number of params for a normal.\n"));
  if (is_float(line[1]) != 0 || is_float(line[2]) != 0
      || is_float(line[3]) != 0)
    return (print_error("A param for the normal isn't a valid number.\n"));
  normal->normal.x = my_getfloat(line[1]);
  normal->normal.y = my_getfloat(line[2]);
  normal->normal.z = my_getfloat(line[3]);
  free_array_char(line, 0);
  normal->next = tmp;
  return (normal);
}

char    *get_mtl_to_use(char *str, char *my_mtl)
{
  char  *copy;
  char  **line;

  if (my_mtl != NULL)
    free(my_mtl);
  if ((line = my_split(str, " ")) == NULL)
    return (NULL);
  if (size_array_char(line) != 2)
    return (NULL);
  if (my_strcmp("usemtl", line[0]) != 0)
    return (NULL);
  if ((copy = my_strdup(line[1])) == NULL)
    return (NULL);
  free_array_char(line, 0);
  return (copy);
}
