/*
** error.c for  in /home/miklox/semestre2/infographie/rt1test
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Wed May 24 12:38:04 2017 Bastien LECUSSAN
** Last update Fri May 26 10:40:47 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

int		check_correct_obj(t_obj *obj)
{
  t_face_vtx	*tmp;
  int		count;

  tmp = obj->face;
  while (tmp != NULL)
    {
      count = 0;
      while (count < 3)
	{
	  if (tmp->face[count].v > obj->pos_nb || tmp->face[count].v <= 0)
	    return (my_printf(2, 84, "A number into faces is too large.\n"));
	  if ((tmp->face[count].vn > obj->normal_nb
	       || tmp->face[count].vn <= 0) && tmp->face[count].vn != -1)
	    return (my_printf(2, 84, "A number into faces is too large.\n"));
	  if ((tmp->face[count].vt > obj->texture_nb
	       || tmp->face[count].vt <= 0) && tmp->face[count].vt != -1)
	    return (my_printf(2, 84, "A number into faces is too large.\n"));
	  count += 1;
	}
      tmp = tmp->prev;
    }
  return (0);
}

void	*print_error(char *str)
{
  write(2, str, my_strlen(str));
  return (NULL);
}

char	*print_error_str(char *str)
{
  print_error(str);
  return (NULL);
}
