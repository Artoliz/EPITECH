/*
** unedfine.c for  in /home/miklox/semestre2/infographie/raytracer2
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Sun May 28 18:59:13 2017 Bastien LECUSSAN
** Last update Sun May 28 19:00:16 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

char    **get_correct_tab_vtx(char **tab, char **line, int count)
{
  if (count == 0)
    {
      tab[0] = line[0];
      tab[1] = line[1];
      tab[2] = line[2];
      tab[3] = line[3];
      tab[4] = NULL;
      return (tab);
    }
  tab[0] = line[0];
  tab[1] = line[count];
  tab[2] = line[count + 2];
  tab[3] = line[count + 3];
  tab[4] = NULL;
  return (tab);
}

t_face_vtx      *get_undefine_nb_face(char **line, t_face_vtx *face, int size,
				      t_face_vtx *tmp)
{
  int           count;
  char          **tab;

  count = 0;
  if ((tab = malloc(sizeof(*tab) * 5)) == NULL)
    return (NULL);
  while (count < size - 2)
    {
      tab = get_correct_tab_vtx(tab, line, count);
      if (count != 0)
	if ((face = malloc(sizeof(*face))) == NULL)
	  return (NULL);
      if ((tmp = get_one_face(tab, face, 3, tmp)) == NULL)
	return (NULL);
      count += 1;
    }
  free(tab);
  return (face);
}
