/*
** my.h for my in /home/descou_c/Graphic/RTV1/inc
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Feb  3 14:14:23 2017 Charles Descoust
** Last update Sun Apr  2 22:38:24 2017 Amardeilh Guilhem
*/

#ifndef MY_H_
# define MY_H_

#include <math.h>
#include <time.h>
#include <string.h>
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

#define WIDTH		(1920)
#define HEIGHT		(1080)

#define READ_SIZE	(4096)

typedef struct  s_my_framebuffer
{
  sfUint8*	pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef struct			s_my_win
{
  sfVideoMode			mode;
  struct s_my_framebuffer*	buffer;
  sfTexture*			texture;
  sfSprite*			sprite;
  sfRenderWindow*		window;
}				t_my_win;

typedef struct	s_title
{
  sfSprite	*cur;
  sfVector2f	pos;
  sfVector2f	save;
  sfIntRect	size;
}		t_title;

typedef struct	s_sprite
{
  t_title	*title;
  sfSprite	*fading;
  sfSprite	*bg1_sky;
  sfSprite	*bg1_land;
  sfSprite	*bg2_sky;
  sfSprite	*bg2_land;
  sfSprite	*fireball;
  sfSprite	*squall;
  sfSprite	*luna;
  sfSprite	*sun;
  sfSprite	*cloud1;
  sfSprite	*cloud2;
}		t_sprite;

typedef struct		s_oki
{
  struct timespec	tp;
  time_t		start;
}			t_oki;

void			my_put_pixel(t_my_framebuffer*, int, int, sfColor);
int			window();
char**			let_s_start(char**);
char			*get_next_line(int);
sfVideoMode		create_my_mode();
t_my_framebuffer*	my_framebuffer_create(int, int);
sfTexture		*create_my_texture(sfVideoMode);
sfSprite		*create_my_sprite(sfTexture*);
t_my_win		create_my_win(sfVideoMode, t_my_framebuffer*,
				      sfTexture*, sfSprite*);
void			aff_sky(t_my_win, t_sprite*, time_t);
void			aff_sun(t_my_win, sfSprite*);
t_title			*create_title();
sfSprite		*create_sprite(char*);
t_sprite		*create_skystuff(t_sprite*);
void			aff_title(t_my_win, t_title*);
void			move_pos(t_title*);
t_sprite		*create_bg_day(char*, char*, t_sprite*);
t_sprite		*create_bg_night(char*, char*, t_sprite*);
void			aff_bg_light(t_my_win, t_sprite*, time_t);
void			aff_bg_dark(t_my_win, t_sprite*);
sfSprite		**create_sky();
void			aff_sky(t_my_win, t_sprite*, time_t);
sfSprite		*create_fireball(char*);
void			fireball_event(t_my_win, sfSprite*, time_t);
void			squall_event(t_my_win, sfSprite*, time_t);
t_oki			*start_clock();
t_sprite		*load_sprites();
sfIntRect		rectfill(int, int, int, int);
void			aff_fade(t_my_win, sfSprite*, time_t);

#endif /* !MY_H_ */
