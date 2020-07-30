/*
** parse_my_xml.c for parse_my_xml in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Feb  9 10:25:24 2017 Charles Descoust
** Last update Tue Mar  7 15:09:43 2017 Charles Descoust
*/

#include "inc/my.h"

t_my_object*	remove_maillon(t_my_object* obj)
{
  t_my_object*  save;

  save = obj;
  while (obj->next != NULL)
    {
      if (my_strcmp(obj->next->name, "LIGHT") == 0)
        {
          obj->next = NULL;
          obj = save;
          return (obj);
        }
      obj = obj->next;
    }
  return (NULL);
}

t_my_object	*create_linked_list(char* buff, t_my_object* obj)
{
  char          **c;
  int           i;

  if ((c = malloc(sizeof(char*) * my_strlen(buff))) == NULL)
    return (NULL);
  if ((c = coord_rotate_radius_in_tab(buff, c)) == NULL)
    return (NULL);
  i = 0;
  while (c[i] != NULL)
    {
      if ((obj = add_maillon(c, obj, &i)) == NULL)
  	{
  	  write(2, "Please, check file values\n", 26);
  	  return (NULL);
  	}
      i = i + 1;
    }
  return (obj);
}

t_my_object	*parse_file(char *file, t_my_object *obj)
{
  char		*buff;
  int		fd;

  if (file[my_strlen(file) - 1] != 't' || file[my_strlen(file) - 2] != 'r' ||
      file[my_strlen(file) - 3] != '.')
    return (NULL);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  while ((buff = get_next_line(fd)) != NULL)
    {
      if ((obj = create_linked_list(buff, obj)) == NULL)
	return (NULL);
    }
  return (obj);
}
