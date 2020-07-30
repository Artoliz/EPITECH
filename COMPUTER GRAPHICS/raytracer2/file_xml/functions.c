/*
** functions.c for  in /home/miklox/semestre2/infographie/file_xml
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Tue Apr 11 08:11:43 2017 Bastien LECUSSAN
** Last update Fri May 26 12:02:05 2017 Charles Aubert
*/

#include "../inc/rt2.h"

/*This function put in str the part of the string src,
with count as beginning.*/
char	*my_strcopy_from_to_end(char *str, char *src, int count)
{
  int	cnt;

  cnt = 0;
  if (count >= my_strlen(src))
    return (NULL);
  while (src[count] != '\0')
    str[cnt++] = src[count++];
  str[cnt] = '\0';
  return (str);
}

/*This function check that there is one object one eye and
at least one light*/
int	requirments_objects(t_object **list)
{
  int	count;
  int	eye;
  int	object;
  int	light;

  count = 0;
  eye = 0;
  object = 0;
  light = 0;
  while (list[count] != NULL)
    {
      if (list[count]->t == MY_EYE)
	eye += 1;
      else if (list[count]->t == MY_LIGHT)
	light += 1;
      else
	object += 1;
      count += 1;
    }
  if (eye != 1 || object < 1 || light < 1)
    return (-1);
  return (0);
}

float	get_bril(int fd, int type)
{
  char	*line;
  char	**tab;
  float	res;

  res = -1;
  if (type == MY_EYE || type == MY_LIGHT)
    return (0);
  if ((line = get_next_line(fd)) == NULL ||
      (tab = my_split(line, ":")) == NULL ||
      size_array((void *)tab) != 2)
    return (res);
  if (my_strcmp(tab[0], "BRILLANCE") != 0)
    return (res);
  res = my_getfloat(tab[1]);
  free(line);
  free_array_char(tab, 0);
  return (res);
}

int	get_texture_mode(int fd, int type)
{
  char  *line;
  char  **tab;
  int	res;

  if (type == MY_PLAN)
    {
      if ((line = get_next_line(fd)) == NULL ||
	  (tab = my_split(line, ":")) == NULL ||
	  size_array((void *)tab) != 2 ||
	  my_strcmp(tab[0], "CHECKERBOARD") != 0)
	return (0);
      res = my_getnbr(tab[1]);
      free(line);
      free_array_char(tab, 0);
      return (res == 0 ? 0 : 1);
    }
  return (0);
}

sfVector3f	get_coefs(int fd, int type)
{
  char		*line;
  char		**tab;
  sfVector3f	res;

  if (type == MY_PARABOLOID || type == MY_ELLIPSOID ||
      type == MY_HYPERBOLOID1 || type == MY_HYPERBOLOID2)
    {
      if ((line = get_next_line(fd)) == NULL ||
          (tab = my_split(line, ":")) == NULL ||
          size_array((void *)tab) != 4 ||
	  my_strcmp(tab[0], "COEFS") != 0)
	return (create_vect3(-1, -1, -1));
      res = create_vect3(my_getfloat(tab[1]), my_getfloat(tab[2]),
			 my_getfloat(tab[3]));
      free(line);
      free_array_char(tab, 0);
      return (res);
    }
  return (create_vect3(0, 0, 0));
}
