/*
** win.h for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/inc
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed May  3 11:10:11 2017 Charles Aubert
** Last update Thu May  4 16:07:47 2017 Charles Aubert
*/

#ifndef WIN_H_
# define WIN_H_

#include "rt2.h"

typedef struct	s_variable
{
  sfVector2i	pos;
  sfVector2i    max;
  int           save;
  sfColor	color;
}		t_variable;

typedef struct  s_my_framebuffer
{
  sfUint8*      pixels;
  int           width;
  int           height;
}               t_my_framebuffer;

typedef struct		s_win
{
  pthread_mutex_t	mutex;
  sfVideoMode		mode;
  t_my_framebuffer	*buffer;
  sfTexture*            texture;
  sfSprite*             sprite;
  sfRenderWindow*       win;
  int                   idx;
  t_variable		var[4];
}			t_win;

sfRenderWindow		*create_window(char *name);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
t_win			create_win_struct(char *name, int, int);
int			check_win(t_win res);
int			draw(t_win win);
int			process_game_loop(sfRenderWindow *window);

#endif /* !WIN_H_ */
