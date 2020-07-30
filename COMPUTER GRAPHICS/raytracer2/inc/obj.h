/*
** obj.h for  in /home/miklox/semestre2/infographie/rt1test/parsing
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue May  9 10:22:23 2017 Bastien LECUSSAN
** Last update Sun May 28 17:15:55 2017 Charles Descoust
*/

#ifndef OBJ_H_
# define OBJ_H_

# define MY_COMMENT_VTX (51)
# define MY_VERTICE_VTX (52)
# define MY_TEXTURE_VTX (53)
# define MY_NORMAL_VTX (54)
# define MY_FACE_VTX (55)
# define MY_MTLLIB (61)
# define MY_GROUP_VTX (56)
# define OTHER_TYPE (57)
# define MY_VOID_LINE (58)
# define MY_OBJ_VTX (60)
# define MY_USEMTL (59)

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <SFML/Network.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct  s_face
{
  int           v;
  int           vt;
  int           vn;
}               t_face;

typedef struct		s_pos_vtx
{
  sfVector3f		pos;
  struct s_pos_vtx	*next;
  struct s_pos_vtx	*prev;
}			t_pos_vtx;

typedef struct		s_texture_vtx
{
  sfVector2f		texture;
  struct s_texture_vtx	*next;
  struct s_texture_vtx	*prev;
}			t_texture_vtx;

typedef struct		s_normal_vtx
{
  sfVector3f		normal;
  struct s_normal_vtx	*next;
  struct s_normal_vtx	*prev;
}			t_normal_vtx;

typedef struct		s_equa
{
  float			a;
  float			b;
  float			c;
  float			d;
}			t_equa;

typedef struct		s_face_vtx
{
  t_face		*face;
  t_equa		*face_equa;
  char			*usemtl;
  int			size;
  struct s_face_vtx	*next;
  struct s_face_vtx	*prev;
}			t_face_vtx;

typedef struct	s_obj
{
  t_pos_vtx	*pos;
  t_texture_vtx *texture;
  t_normal_vtx  *normal;
  t_face_vtx    *face;
  int		pos_nb;
  int		texture_nb;
  int		normal_nb;
}               t_obj;

typedef struct	s_tool_obj
{
  t_face_vtx	*tmp_f;
  t_texture_vtx	*tmp_t;
  t_normal_vtx	*tmp_n;
  t_pos_vtx	*tmp_p;
}		t_tool_obj;

typedef struct	s_vtx
{
  t_obj		*obj;
}		t_vtx;

char		*print_error_str(char *str);
t_face_vtx	*get_obj_face(char *str, t_face_vtx *tmp, char *my_mtl);
t_normal_vtx	*get_obj_normal(char *str, t_normal_vtx *tmp);
t_texture_vtx	*get_obj_texture(char *str, t_texture_vtx *tmp);
t_pos_vtx	*get_obj_vertice(char *str, t_pos_vtx *tmp);
char		*get_mtl_to_use(char *str, char *my_mtl);
int		get_line_type(char *str);
int		get_line_type_end(char *str, int count);
t_face_vtx	*double_chain_face_vtx(t_face_vtx *face);
t_texture_vtx	*double_chain_texture_vtx(t_texture_vtx *txt);
t_normal_vtx	*double_chain_normal_vtx(t_normal_vtx *txt);
t_pos_vtx	*double_chain_pos_vtx(t_pos_vtx *txt);
void		*print_error(char *str);
int		is_float(char *str);
char		**my_array_char_realloc(char **my_tab, char *new_str);
t_obj		*get_list_obj(int fd);
t_vtx		*create_list_vertex(char *file);
int		check_extension(char *file);

#endif /*OBJ_H_*/
