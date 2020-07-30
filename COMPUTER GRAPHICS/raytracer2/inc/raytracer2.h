/*
** raytracer2.h for  in /home/miklox/semestre1/infographie/bsraytracer1
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Mon Feb  6 18:07:13 2017 Bastien LECUSSAN
** Last update Sun May 28 19:03:17 2017 Bastien LECUSSAN
*/

#ifndef RAYTRACER2_H_
# define RAYTRACER2_H_
# define S_WIDTH (1600)
# define S_HEIGHT (800)
# define MY_MACRO_LIGHT_X (0)
# define MY_MACRO_LIGHT_Z (0)
# define ROTATION_SCENE_X (-90)
# define ROTATION_SCENE_Y (0)
# define ROTATION_SCENE_Z (0)
# define ROTATION_OBJ_X (0)
# define ROTATION_OBJ_Y (0)
# define ROTATION_OBJ_Z (0)
# define DIST (500)

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
#include "./position.h"
#include "./obj.h"
#include "../lib/my/my.h"

typedef struct	s_point_tri
{
  sfVector3f	point1;
  sfVector3f	point2;
  sfVector3f	vec1;
  sfVector3f	vec2;
  sfVector3f	vec3;
}		t_point_tri;

typedef struct	s_face_tools
{
  sfVector3f	norm_p;
  sfVector3f	inconnu;
}		t_face_tools;

typedef struct	s_intersct
{
  sfVector3f	point;
  float		dist;
}		t_intersct;

typedef struct	s_smallest
{
  float		dist;
  float		res;
  sfColor	my_color;
  int		count;
}		t_smallest;

typedef struct          s_framebuffer
{
  sfUint8               *pixels;
  int                   width;
  int                   height;
}                       t_my_framebuffer;

typedef struct		s_pos
{
  int			flag;
  sfVector3f		pos;
  float			rad_dist;
  sfVector3f		rotate;
  sfColor		my_color;
  struct s_pos		*next;
}			t_pos;

typedef struct          s_frame
{
  sfRenderWindow        *window;
  sfTexture             *texture;
  sfSprite              *sprite;
  t_my_framebuffer      *frameb;
  sfColor               color;
  t_obj			*scene;
  t_vtx			*total;
  t_pos			*scene_shadow;
  sfVector3f		light;
  t_pos			*save;
  t_face_vtx		*save_face;
}                       t_frame;

typedef struct          s_my_struct
{
  sfVector3f            eye;
  sfVector3f            vector;
  sfVector2i            pos;
  sfVector3f		res;
  t_smallest		dist;
}                       t_my_struct;

#include "./src_obj.h"

t_face_vtx		*get_one_face(char **, t_face_vtx *, int,
				      t_face_vtx *);
t_face_vtx		*get_undefine_nb_face(char **, t_face_vtx *, int,
					       t_face_vtx *);
void			free_list_obj_mtl(t_vtx *list);
sfVector3f		get_light_vector(sfVector3f *, sfVector3f *);
int			check_correct_obj(t_obj *obj);
t_obj			*get_end_tab_obj(t_obj *obj, float coef);
int			get_new_size_obj(t_obj *, sfVector3f *);
t_obj			*get_tab_obj(t_obj *);
float			get_norm_index(t_obj *obj, int nb, char flag);
float			get_pos_index(t_obj *obj, int nb, char flag);
float			prod_scal(sfVector3f *, sfVector3f *);
float			distance_vect(sfVector3f *vect);
int			point_is_in(t_my_struct *, t_obj *, t_face *);
sfVector3f		*sub_3fptr(sfVector3f *, sfVector3f *, sfVector3f *);
sfVector3f		*prod_vect(sfVector3f *, sfVector3f *, sfVector3f *);
sfVector3f		m_3f(sfVector3f, sfVector3f *);
t_obj			*get_equation(t_obj *obj);
float			intersect_face(t_face_vtx *, t_my_struct *, t_obj *);
float			get_shadow_obj(sfVector3f *, sfVector3f *, t_frame *,
				   t_face_vtx *);
sfColor			apply_my_color(sfColor, float, float);
void			rotate_xyz_inv_obj(sfVector3f *, sfVector3f *);
void			rotate_xyz_obj(sfVector3f *, sfVector3f *);
sfVector3f		get_pos_intersect(sfVector3f *, sfVector3f *,
					  float);
void			translate_inv_obj(sfVector3f *, sfVector3f *, sfVector3f *);
float			get_light_coef_obj(sfVector3f *, sfVector3f *);
void			rotate_x_obj(sfVector3f *, float, float);
void			rotate_y_obj(sfVector3f *, float, float);
void			rotate_z_obj(sfVector3f *, float, float);
sfColor			get_my_color(t_frame *, t_my_struct *,
				     float, t_face_vtx *);
void			my_free(t_frame *);
void			my_eye_pos(sfVector3f *);
void			my_screen_pos(sfVector2i *, int, int);
int			window_destroy(t_frame *);
void			window_refresh(t_frame *);
t_my_framebuffer	*frameb_create(int, int);
sfRenderWindow          *create_window_obj(char *, int, int);
int			my_raytracer(t_frame *);
int			my_scene(t_my_struct *, t_frame *,
				 t_smallest *, t_face_vtx *);

#endif /* !RAYTRACER2_H_ */
