/*
** my.h for my in /home/descou_c/Graphic/bswolf3d/inc
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec 13 08:41:07 2016 Charles Descoust
** Last update Mon Jan 23 13:41:57 2017 Charles Descoust
*/

#ifndef MY_H_
# define MY_H_

#include <math.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include <SFML/OpenGL.h>

#include "file.h"

#define WIDTH   1080
#define HEIGHT  720

typedef struct  s_my_framebuffer
{
	sfUint8* pixels;
	int	width;
	int	height;
} t_my_framebuffer;

typedef struct                  s_my_win
{
  sfRenderWindow                *window;
  struct s_my_framebuffer       *buffer;
  sfVector2i			mapSize;
  int				**map;
}                               t_my_win;

t_my_framebuffer	*my_framebuffer_create(int, int);
sfTexture		*my_create_texture(sfVideoMode);
t_my_win		my_create_window(sfVideoMode, t_my_framebuffer*);
sfVideoMode		my_create_mode();
int			my_win(t_my_win, sfSprite*, sfVector2f, sfTexture*);
int			open_window(sfVideoMode, t_my_framebuffer*, char*);
void			my_put_pixel(t_my_framebuffer*, int, int, sfColor);
void			my_draw_line(t_my_framebuffer*, sfVector2i, sfVector2i, sfColor);
sfVector2f		move_forward(sfVector2f, float, float);
float			raycast(sfVector2f, float, int**, sfVector2i);
sfVector2f		calc_new_pos(sfVector2f, float);
sfVector2f		calc_vec_dir(sfVector2f, sfVector2f);
int			same_x(t_my_framebuffer*, sfVector2i, sfVector2i, sfColor);
int			same_y(t_my_framebuffer*, sfVector2i, sfVector2i, sfColor);
int			max_to_min(t_my_framebuffer*, sfVector2f, sfVector2f, sfColor);
int			min_to_max(t_my_framebuffer*, sfVector2f, sfVector2f, sfColor);
sfVector2f		transform(sfVector2i);
void			aff_no_wall(t_my_framebuffer*);
void			aff_wall(t_my_framebuffer*, sfVector2f, t_my_win, float);
void			wall_sup(t_my_framebuffer*, int, int);
void			wall_inf(t_my_framebuffer*, int, int);
sfColor			sky_color();
sfColor			ground_color();
sfColor			wall_color();

#endif /* !MY_H_ */
