/*
** main.c for  in /home/miklox/semestre2/infographie/file_xml
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Mon Apr 10 15:43:58 2017 Bastien LECUSSAN
** Last update Sun May 28 22:50:49 2017 Charles Aubert
*/

#include "../inc/rt2.h"

/*This function is the start of the create_objects_from_file.*/
t_object	**create_objects_from_file(char *path)
{
  t_object	**objects;
  int		fd;
  int		nb;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  if ((nb = get_number_of_objects(fd)) == -1)
    return (NULL);
  if ((objects = malloc(sizeof(*objects) * (nb + 1))) == NULL)
    return (NULL);
  if ((objects = get_all_objects(objects, fd, nb)) == NULL)
    return (NULL);
  if (close(fd) == -1)
    return (NULL);
  if (requirments_objects(objects) == -1)
    return (NULL);
  return (objects);
}

/*This function get the nb of objects which is the first argument
given in the file. If an error occured or argument is incorrect, -1
is return.*/
int	get_number_of_objects(int fd)
{
  char	*buf;
  int	count;
  int	nb;
  int	point;

  point = 0;
  count = 0;
  if ((buf = get_next_line(fd)) == NULL)
    return (-1);
  while (buf[count] != '\0')
    {
      if ((buf[count] < '0' || buf[count] > '9') && buf[count] != '.')
	return (-1);
      if (buf[count] == '.' && count == 0)
	return (-1);
      if (buf[count] == '.')
	point += 1;
      count += 1;
    }
  nb = my_getnbr(buf);
  if (nb == 0 || point > 1)
    return (-1);
  free(buf);
  return (nb);
}

/*This function is a loop which put the objects into the tab
structure of objects.*/
t_object	**get_all_objects(t_object **objs, int fd, int nb_obj)
{
  int		i;

  i = 0;
  while (i < nb_obj)
    {
      if (check_for_next_objects(fd) == -1 ||
	  (objs[i] = malloc(sizeof(**objs))) == NULL ||
	  (objs[i]->t = get_type_obj(fd)) == -1 ||
	  (objs[i]->r = get_radius_obj(fd)) == -1 ||
	  get_pos_rot_obj(fd, "POSITION:", objs[i]) != 0 ||
	  get_pos_rot_obj(fd, "ROTATION:", objs[i]) != 0 ||
	  get_color_obj(fd, objs[i]) != 0 ||
	  (objs[i]->bril = get_bril(fd, objs[i]->t)) == -1 ||
	  (objs[i]->b = get_texture_mode(fd, objs[i]->t)) == -1 ||
	  (objs[i]->coef = get_coefs(fd, objs[i]->t)).x == -1)
	return (NULL);
      objs[i]->k = -1.0;
      objs[i]->sc = objs[i]->c;
      i += 1;
    }
  objs[i] = NULL;
  if (check_end_of_file(fd) == -1)
    return (NULL);
  return (objs);
}

/*This function return the macro equal to the type of object
loaded from the file.*/
int	get_type_obj(int fd)
{
  int	type;
  char	*buf;
  char	*str;
  int	count;

  type = 0;
  if ((buf = get_next_line(fd)) == NULL)
    return (-1);
  if ((count = my_strcmp_start(buf, "OBJECT:")) == -1)
    return (-1);
  if ((str = malloc(sizeof(*str) * (my_strlen(buf) - count + 1))) == NULL)
    return (-1);
  if ((str = my_strcopy_from_to_end(str, buf, count)) == NULL)
    return (-1);
  if ((type = get_type_object_macro(str)) == -1)
    return (-1);
  free(str);
  free(buf);
  return (type);
}

/*This function returns the macro equal to the object given or -1
if an error occured.*/
int	get_type_object_macro(char *str)
{
  if (my_strcmp(str, "SPHERE") == 0)
    return (MY_SPHERE);
  if (my_strcmp(str, "PLANE") == 0)
    return (MY_PLAN);
  if (my_strcmp(str, "CYLINDER") == 0)
    return (MY_CYLINDER);
  if (my_strcmp(str, "CONE") == 0)
    return (MY_CONE);
  if (my_strcmp(str, "EYE") == 0)
    return (MY_EYE);
  if (my_strcmp(str, "LIGHT") == 0)
    return (MY_LIGHT);
  if (my_strcmp(str, "STRIP") == 0)
    return (MY_STRIP);
  if (my_strcmp(str, "PARABOLOID") == 0)
    return (MY_PARABOLOID);
  if (my_strcmp(str, "ELLIPSOID") == 0)
    return (MY_ELLIPSOID);
  if (my_strcmp(str, "HYPERBOLOID1") == 0)
    return (MY_HYPERBOLOID1);
  if (my_strcmp(str, "HYPERBOLOID2") == 0)
    return (MY_HYPERBOLOID2);
  return (-1);
}
