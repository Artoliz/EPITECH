/*
** create_list.c for  in /home/miklox/semestre2/infographie/rt1test/parsing
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue May  9 10:27:47 2017 Bastien LECUSSAN
** Last update Sun May 28 17:16:33 2017 Charles Descoust
*/

#include "raytracer2.h"

char	*get_material(int fd)
{
  char	*buf;
  int	count;

  while ((buf = get_next_line(fd)) != NULL)
    {
      count = 0;
      while (buf[count] == ' ' || buf[count] == '\t')
	count += 1;
      if (get_line_type(buf) == MY_VERTICE_VTX)
	return (print_error("Pas de nom d'objet.\n"));
      if (buf[count] != '#' && get_line_type(buf) != MY_VOID_LINE)
	return (buf);
      free(buf);
    }
  return (NULL);
}

char	*get_real_name(char *name, char *path)
{
  int	count;
  char	*str;

  count = 0;
  if (name[count] == '.' && name[count + 1] == '/')
    {
      while (name[count + 2] != '\0')
	{
	  name[count] = name[count + 2];
	  count += 1;
	}
      name[count] = '\0';
    }
  count = my_strlen(path) - 5;
  while (path[count] != '.' && path[count] != '/' && count != 0)
    count -= 1;
  if (count != 0)
    path[count + 1] = '\0';
  if ((str = join_str_str(path, name)) == NULL)
    return (NULL);
  free(name);
  return (str);
}

char	**get_material_name(char *mtl, char *file)
{
  char	**material;

  if ((material = my_split(mtl, " ")) == NULL)
    return (NULL);
  if (my_strcmp("mtllib", material[0]) != 0)
    return (NULL);
  if ((material[1] = get_real_name(material[1], file)) == NULL)
    return (NULL);
  return (material);
}

t_vtx	*create_list_vertex(char *file)
{
  t_vtx	*obj;
  int	fd;
  char	*mtl;

  if ((obj = malloc(sizeof(*obj))) == NULL)
    return (NULL);
  if (check_extension(file) == -1)
    return (NULL);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((mtl = get_material(fd)) == NULL)
    return (NULL);
  if ((obj->obj = get_list_obj(fd)) == NULL)
    return (NULL);
  free(mtl);
  return (obj);
}
