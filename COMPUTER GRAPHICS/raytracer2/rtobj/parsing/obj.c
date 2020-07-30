/*
** obj.c for  in /home/miklox/semestre2/infographie/rt1test/parsing
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Wed May 24 13:35:08 2017 Bastien LECUSSAN
** Last update Sat May 27 11:49:17 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

char	*epur_str_vtx(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    count += 1;
  if (count > 0)
    count -= 1;
  if (str[count] == 13)
    str[count] = '\0';
  return (str);
}

t_obj		*get_obj_return(t_obj *obj, t_tool_obj tmp)
{
  if (tmp.tmp_p == NULL || tmp.tmp_f == NULL)
    return (NULL);
  obj->pos = double_chain_pos_vtx(tmp.tmp_p);
  if (tmp.tmp_t != NULL)
    obj->texture = double_chain_texture_vtx(tmp.tmp_t);
  else
    obj->texture = NULL;
  if (tmp.tmp_n != NULL)
    obj->normal = double_chain_normal_vtx(tmp.tmp_n);
  else
    obj->normal = NULL;
  obj->face = double_chain_face_vtx(tmp.tmp_f);
  return (obj);
}

void		get_obj_loop(int type, char **str, t_tool_obj *tmp,
			     char **my_mtl)
{
  if (type == MY_NORMAL_VTX)
    {
      if ((tmp->tmp_n = get_obj_normal(*str, tmp->tmp_n)) == NULL)
	{
	  my_printf(2, 0, "%s\n", *str);
	  *str = NULL;
	}
    }
  else if (type == MY_FACE_VTX)
    {
      if ((tmp->tmp_f = get_obj_face(*str, tmp->tmp_f, *my_mtl)) == NULL)
	{
	  my_printf(2, 0, "%s\n", *str);
	  *str = NULL;
	}
    }
  else if (type == MY_USEMTL)
    {
      if ((*my_mtl = get_mtl_to_use(*str, *my_mtl)) == NULL)
	*str = print_error_str("Malloc failed.\n");
    }
  else if (type == OTHER_TYPE)
    *str = print_error("Bad file.\n");
}

t_obj           *get_obj(t_obj *obj, int fd, t_tool_obj tmp,
			 char *str)
{
  char          *my_mtl;
  int           type;

  str = NULL;
  my_mtl = NULL;
  while ((str = get_next_line(fd)) != NULL)
    {
      str = epur_str_vtx(str);
      if ((type = get_line_type(str)) == MY_VERTICE_VTX)
	{
	  if ((tmp.tmp_p = get_obj_vertice(str, tmp.tmp_p)) == NULL)
	    return (print_error(str));
	}
      else if (type == MY_TEXTURE_VTX)
	{
	  if ((tmp.tmp_t = get_obj_texture(str, tmp.tmp_t)) == NULL)
	    return (print_error(str));
	}
      else
	get_obj_loop(type, &str, &tmp, &my_mtl);
      if (str == NULL)
	return (NULL);
      free(str);
    }
  return (get_obj_return(obj, tmp));
}

t_obj		*get_list_obj(int fd)
{
  t_obj		*obj;
  t_tool_obj    tmp;
  char		*str;

  tmp.tmp_f = NULL;
  tmp.tmp_t = NULL;
  tmp.tmp_n = NULL;
  tmp.tmp_p = NULL;
  str = NULL;
  if ((obj = malloc(sizeof(*obj))) == NULL)
    return (print_error("Malloc failed.\n"));
  obj->pos = NULL;
  obj->texture = NULL;
  obj->normal = NULL;
  obj->face = NULL;
  if ((obj = get_obj(obj, fd, tmp, str)) == NULL)
    return (NULL);
  return (obj);
}
