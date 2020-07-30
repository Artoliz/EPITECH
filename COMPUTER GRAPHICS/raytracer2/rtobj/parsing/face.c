/*
** parsing.c for  in /home/miklox/semestre2/infographie/rt1test/parsing
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue May  9 13:48:58 2017 Bastien LECUSSAN
** Last update Sun May 28 19:00:25 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

t_face_vtx	*get_face_value_size_three(char **line2, t_face_vtx *face,
					   int count)
{
  if (my_str_isnum(line2[0]) != 0 || my_str_isnum(line2[1]) != 0
      || my_str_isnum(line2[2]) != 0 || my_strlen(line2[0]) > 9
      || my_strlen(line2[1]) > 9 || my_strlen(line2[2]) > 9)
    return (print_error("A param for the face isn't a valid number.\n"));
  face->face[count].v = my_getnbr(line2[0]);
  face->face[count].vt = my_getnbr(line2[1]);
  face->face[count].vn = my_getnbr(line2[2]);
  return (face);
}

t_face_vtx	*get_face_value(char **line2, t_face_vtx *face, int size2,
				int count)
{
  if (size2 == 1)
    {
      if (my_str_isnum(line2[0]) != 0 || my_strlen(line2[0]) > 9)
	return (print_error("A param for the face isn't a valid number.\n"));
      face->face[count].v = my_getnbr(line2[0]);
      face->face[count].vt = -1;
      face->face[count].vn = -1;
    }
  else if (size2 == 2)
    {
      if (my_str_isnum(line2[0]) != 0 || my_str_isnum(line2[1]) != 0
	  || my_strlen(line2[0]) > 9 || my_strlen(line2[1]) > 9)
	return (print_error("A param for the face isn't a valid number.\n"));
      face->face[count].v = my_getnbr(line2[0]);
      face->face[count].vt = -1;
      face->face[count].vn = my_getnbr(line2[1]);
    }
  else if (size2 == 3)
    face = get_face_value_size_three(line2, face, count);
  return (face);
}

t_face_vtx	*get_one_face(char **line, t_face_vtx *face, int size,
			      t_face_vtx *tmp)
{
  int		count;
  int		size2;
  char		**line2;

  count = 0;
  if ((face->face = malloc(sizeof(*face->face) * size)) == NULL)
    return (print_error("Malloc failed.\n"));
  face->size = size;
  while (count < size)
    {
      if ((line2 = my_split(line[count + 1], "/")) == NULL)
	return (print_error("Malloc failed.\n"));
      if ((size2 = size_array_char(line2)) > 3)
	return (print_error("Too much params for a face.\n"));
      if ((face = get_face_value(line2, face, size2, count)) == NULL)
	return (NULL);
      free_array_char(line2, 0);
      count += 1;
    }
  face->next = tmp;
  return (face);
}

t_face_vtx	*get_obj_face(char *str, t_face_vtx *tmp, char *my_mtl)
{
  t_face_vtx	*face;
  char		**line;
  int		size;

  if ((face = malloc(sizeof(*face))) == NULL)
    return (print_error("Malloc failed.\n"));
  if ((line = my_split(str, " \t")) == NULL)
    return (print_error("Malloc failed.\n"));
  if ((size = size_array_char(line) - 1) < 3)
    return (print_error("One face isn't valid.\n"));
  if (size > 3)
    {
      if ((face = get_undefine_nb_face(line, face, size, tmp)) == NULL)
	return (NULL);
    }
  else
    if ((face = get_one_face(line, face, size, tmp)) == NULL)
      return (NULL);
  if (my_mtl != NULL)
    if ((face->usemtl = my_strdup(my_mtl)) == NULL)
      return (print_error("Malloc failed.\n"));
  free_array_char(line, 0);
  return (face);
}
