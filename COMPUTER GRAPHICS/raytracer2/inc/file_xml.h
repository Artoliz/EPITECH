/*
** file_xml.h for file_xml in /home/descou_c/Graphic/rt2_file/file_xml
**
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
**
** Started on  Tue Apr 11 13:18:19 2017 Charles Descoust
** Last update Thu May 25 10:17:52 2017 Charles Aubert
*/

#ifndef FILE_XML_H_
# define FILE_XML_H_

# define MY_SPHERE (0)
# define MY_CONE (1)
# define MY_CYLINDER (2)
# define MY_STRIP (3)
# define MY_PARABOLOID (4)
# define MY_HYPERBOLOID2 (5)
# define MY_HYPERBOLOID1 (6)
# define MY_ELLIPSOID (7)
# define MY_HYPERBOLOIC (8)
# define MY_PLAN (10)
# define MY_EYE (11)
# define MY_LIGHT (12)
# define MY_PRES 1e-9
# define OBJ_COUNT (9)

typedef struct		s_object
{
  int			t;
  float			r;
  sfVector3f		pos;
  sfVector3f		rot;
  sfVector3f		coef;
  sfColor		c;
  sfColor		sc;
  float			bril;
  double		k;
  int			b;
}			t_object;

typedef struct	s_strip
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	e;
  double	f;
  double	g;
}		t_strip;

char		*what_type(int type);
int		requirments_objects(t_object **list);
int		get_color_obj(int fd, t_object *obj);
void		free_list_objects(t_object **list);
int		check_requirments_tab(char **my_line);
int		check_end_of_file(int fd);
int		get_pos_rot_obj(int fd, char *compare, t_object *obj);
float		get_radius_obj(int fd);
int		check_nbr(char *str);
int		get_type_object_macro(char *object);
char		*my_strcopy_from_to_end(char *str, char *src, int start);
int		my_strcmp_start(char *str, char *str2);
t_object	**create_objects_from_file(char *path);
int		get_number_of_objects(int fd);
t_object	**get_all_objects(t_object **objects, int fd, int nb_obj);
int		get_type_obj(int fd);
int		check_for_next_objects(int fd);
int		display_list_objects(t_object **objects);
float		get_bril(int fd, int type);
int		get_texture_mode(int fd, int type);
sfVector3f      get_coefs(int fd, int type);

#endif /* !FILE_XML_H_ */
