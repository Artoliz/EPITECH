/*
** get_list_objects.c for  in /home/miklox/semestre2/infographie/file_xml
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Tue Apr 11 08:26:20 2017 Bastien LECUSSAN
** Last update Thu May  4 16:14:30 2017 Charles Aubert
*/

#include "../inc/rt2.h"

/*This function return the radius of the function*/
float	get_radius_obj(int fd)
{
  float	rad;
  char	*buf;
  char	*str;
  int	count;

  if ((buf = get_next_line(fd)) == NULL)
    return (-1);
  if ((count = my_strcmp_start(buf, "RADIUS:")) == -1)
    return (-1);
  if ((str = malloc(sizeof(*str) * (my_strlen(buf) - count + 1))) == NULL)
    return (-1);
  if ((str = my_strcopy_from_to_end(str, buf, count)) == NULL)
    return (-1);
  if (check_nbr(str) == -1)
    return (-1);
  rad = my_getfloat(str);
  free(str);
  free(buf);
  return (rad);
}

/*This function return the position of the object.*/
int		get_pos_rot_obj(int fd, char *compare, t_object *obj)
{
  sfVector3f	pos;
  char		*buf;
  char		**line;
  int		count;

  pos.x = 0;
  pos.y = 0;
  pos.z = 0;
  if ((buf = get_next_line(fd)) == NULL ||
      (count = my_strcmp_start(buf, compare)) == -1 ||
      (line = my_split(buf, ":")) == NULL ||
      (check_requirments_tab(line)) == -1)
    return (my_printf(2, 84, "Invalid requirements in get_pos_rot_obj.\n"));
  pos.x = my_getfloat(line[1]);
  pos.y = my_getfloat(line[2]);
  pos.z = my_getfloat(line[3]);
  if (my_strcmp(compare, "POSITION:") == 0)
    obj->pos = pos;
  else
    obj->rot = pos;
  free(buf);
  free_array_char(line, 0);
  return (0);
}

/*This function returns the color of the object*/
int		get_color_obj(int fd, t_object *obj)
{
  sfColor	my_color;
  char		*buf;
  char		**tab;

  if ((buf = get_next_line(fd)) == NULL ||
      (tab = my_split(buf,  ":")) == NULL ||
      size_array((void *)tab) != 5 || my_strcmp(tab[0], "COLOR") != 0 ||
      my_str_isnum(tab[1]) != 0 || my_str_isnum(tab[2]) != 0 ||
      my_str_isnum(tab[3]) != 0 || my_str_isnum(tab[4]) != 0)
    return (my_printf(2, 84, "Invalid color: could not be created.\n"));
  my_color.r = my_getnbr(tab[1]);
  my_color.g = my_getnbr(tab[2]);
  my_color.b = my_getnbr(tab[3]);
  my_color.a = my_getnbr(tab[4]);
  obj->c = my_color;
  free(buf);
  free_array_char(tab, 0);
  return (0);
}
