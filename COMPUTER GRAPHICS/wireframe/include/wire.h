/*
** wire.h for wire in /home/descou_c/Graphic/wireframe/include
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Nov 24 14:10:57 2016 Charles Descoust
** Last update Sun Dec 11 12:04:49 2016 Charles Descoust
*/

#ifndef WIRE_H_
# define WIRE_H_

#include <math.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef struct			s_my_win
{
  sfRenderWindow		*window;
  struct s_my_framebuffer	*buffer;
}				t_my_win;

typedef struct	s_tab
{
  int		**tab;
  int		lines;
  int		chars;
}		t_tab;

#include "lib.h"
#include "file.h"

#define WIDTH		1920
#define HEIGHT	        1080

int			max_to_min(t_my_framebuffer*, sfVector2f, sfVector2f, sfColor);
int			min_to_max(t_my_framebuffer*, sfVector2f, sfVector2f, sfColor);
int			same_y(t_my_framebuffer*, sfVector2i, sfVector2i, sfColor);
int			same_x(t_my_framebuffer*, sfVector2i, sfVector2i, sfColor);
int			aff_my_y(t_my_win, t_tab);
int			aff_my_z(t_my_win, t_tab);
sfVector2f		transform(sfVector2i);
sfVector3f		transfert(int, int, int);
t_my_framebuffer	*my_framebuffer_create(int, int);
void			my_draw_line(t_my_framebuffer*, sfVector2i, sfVector2i, sfColor);
void			my_put_pixel(t_my_framebuffer*, int, int, sfColor);
sfVector2i		my_parallel_projection(sfVector3f, float);
sfVector2i		my_isometric_projection(sfVector3f);
int			my_window(t_my_win, sfSprite*);
sfVideoMode		my_create_mode();
t_my_win		my_create_window(sfVideoMode, t_my_framebuffer*);
sfTexture		*my_create_texture(sfVideoMode);
int			open_window(t_tab, t_my_framebuffer*, sfVideoMode);
void			update_window(t_my_framebuffer*);

#endif /* !WIRE_H_ */
