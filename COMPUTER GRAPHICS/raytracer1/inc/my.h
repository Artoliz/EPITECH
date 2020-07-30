/*
** my.h for my in /home/descou_c/Graphic/RTV1/inc
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Feb  3 14:14:23 2017 Charles Descoust
** Last update Tue Apr  4 15:55:26 2017 Charles Descoust
*/

#ifndef MY_H_
# define MY_H_

#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include <SFML/OpenGL.h>

#define WIDTH	1920
#define HEIGHT	1080

#define READ_SIZE	4096

typedef struct  s_my_framebuffer
{
        sfUint8* pixels;
        int     width;
        int     height;
} t_my_framebuffer;

struct	s_var
{
  sfVector2i    pos;
  sfVector2i	max;
  int           save;
  sfColor       color;
};

typedef struct          s_my_pos
{
  sfVector2i            screen_size;
  sfVector2i            screen_pos;
  sfVector3f            eye_pos;
  sfVector3f            eye_rotate;
  sfVector3f            dir_vector;
  sfVector3f            new_pos;
  float                 k;
  sfVector3f            light_pos;
  sfVector3f            dir_light;
}                       t_my_pos;

typedef struct          s_my_object
{
  char                  *name;
  sfVector3f            coord;
  sfVector3f            rotate;
  float                 radius;
  sfColor               color;
  struct s_my_object    *next;
}                       t_my_object;

typedef struct			s_my_win
{
  sfVideoMode			mode;
  struct s_my_framebuffer*	buffer;
  sfTexture*			texture;
  sfSprite*			sprite;
  sfRenderWindow*		window;
  int				idx;
  struct s_var			var[4];
  t_my_object			*obj;
  t_my_pos			basic;
}				t_my_win;

typedef struct	s_ptr_color
{
  char		*color_name;
  sfColor	(*ft)();
}		t_ptr_color;

typedef struct  s_ptr_ft
{
  char          *name;
  float         (*ft)(sfVector3f, sfVector3f, float);
}               t_ptr_ft;

void		my_put_pixel(t_my_framebuffer*, int, int, sfColor);
sfVector3f	calc_dir_vector(float, sfVector2i, sfVector2i);
float		intersect_plane(sfVector3f, sfVector3f);
sfVector3f	get_normal_plane(int);
float		calc_delta(float, sfVector3f);
float		intersect_sphere(sfVector3f, sfVector3f, float);
sfVector3f	sphere_expr(sfVector3f, sfVector3f, float);
sfVector3f	get_normal_sphere(sfVector3f);
float           intersect_cylinder(sfVector3f, sfVector3f, float);
sfVector3f      cylinder_expr(sfVector3f, sfVector3f, float);
sfVector3f      get_normal_cylinder(sfVector3f);
float		intersect_cone(sfVector3f, sfVector3f, float);
sfVector3f	cone_expr(sfVector3f, sfVector3f, float);
sfVector3f	get_normal_cone(sfVector3f, float);
sfVector3f	translate(sfVector3f, sfVector3f);
sfVector3f	translate_inv(sfVector3f, sfVector3f);
sfVector3f	rotate_xyz(sfVector3f, sfVector3f);
sfVector3f	rotate_xyz_inv(sfVector3f, sfVector3f);
sfVector3f	rotate_zyx(sfVector3f, sfVector3f);
sfVector3f	rotate_x(sfVector3f, float);
sfVector3f	rotate_y(sfVector3f, float);
sfVector3f	rotate_z(sfVector3f, float);
float		get_light_coef(sfVector3f, sfVector3f);
sfVector3f	calc_dir_light(sfVector3f, sfVector3f);
sfVector3f	calc(sfVector3f, sfVector3f, float);
int		window(t_my_object*, t_my_pos);
int		let_s_start(int, char**);
int		check_env(char**);
t_my_pos	add_my_basic_pos(t_my_object*);
t_my_pos	init_basic();
int		open_window(t_my_win);
sfVideoMode	create_my_mode();
t_my_framebuffer*	my_framebuffer_create(int, int);
sfTexture*	create_my_texture(sfVideoMode);
sfSprite*	create_my_sprite(sfTexture*);
t_my_win	create_my_win(sfVideoMode, t_my_framebuffer*,
			      sfTexture*, sfSprite*);
t_my_object*	init_basic_objs(t_my_object*);
char*		get_next_line(const int);
t_my_object*	parse_file(char*, t_my_object*);
char            *my_strcpy(char*, char*);
int             my_strlen(char*);
int             my_strcmp(char*, char*);
int		my_strisfloat(char*);
void		my_putchar(char);
void		my_putstr(char*);
int		my_while_error_file(char**, int*);
float		my_getnbr_float(char*);
float		calc_decimal(int, char*, float);
float		calc_integer(int, char*);
int		len_after(char*);
int		len_before(char*);
sfColor		white_color();
sfColor		black_color();
sfColor		blue_color();
sfColor		green_color();
sfColor		cyan_color();
sfColor		magenta_color();
sfColor		yellow_color();
sfColor		red_color();
t_my_object*	create_linked_list(char*, t_my_object*);
char**		coord_rotate_radius_in_tab(char*, char**);
t_my_object*	add_maillon(char**, t_my_object*, int*);
t_my_object*	add_maillon2(char**, t_my_object*, int*);
t_my_object*	add_maillon_next(char**, t_my_object*, int*);
t_my_object*	add_coord_rotate(t_my_object*, char**, int*, int);
t_my_object*	add_color(char**, int*, t_my_object*);
t_my_object*	remove_maillon(t_my_object*);
void*		pixels_walk(void*);
void		launch_ray(t_my_object*, t_my_pos,
			   t_my_framebuffer*, t_ptr_ft*);
sfColor		what_color(t_my_object*, t_my_pos, t_ptr_ft*);
float		what_k(t_my_object*, t_my_pos*, t_ptr_ft*);
sfColor		new_color(t_my_object*, t_my_pos, sfVector3f, int);
sfVector3f	choose_normale(t_my_object*, sfVector3f);
sfColor		calc_new_color(t_my_object*, t_my_pos,
			       t_my_object*, t_ptr_ft*);
float		calc_shadow(t_my_object*, t_my_pos,
			    t_ptr_ft*, t_my_object*);
void		run_time(t_my_win);
float		intersect_ruban(sfVector3f, sfVector3f, float);

#endif /* !MY_H_ */
