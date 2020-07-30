/*
** rt2.h for rt2 in /home/descou_c/Graphic/raytracer2/inc
**
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
**
** Started on  Wed Mar 29 10:31:04 2017 Charles Descoust
** Last update Sun May 28 22:12:25 2017 Charles Descoust
*/

#ifndef RT2_H_
# define RT2_H_

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <SFML/Window.h>
# include <SFML/Graphics.h>
# include <SFML/System.h>
# include <SFML/Audio.h>
# include <SFML/Config.h>
# include <SFML/Network.h>
# include <SFML/OpenGL.h>
# include <pthread.h>
# include "../lib/my/my.h"
# include "./file_xml.h"
# include "./conf.h"
# include "./src.h"
# include "./obj.h"
# include "./args.h"
# include "./win.h"
# include "./my_threads.h"

# define WIDTH	1080
# define HEIGHT	720
# define AL 1

int			start_obj(char **argv);
sfVideoMode		create_my_mode();
void			my_put_pixel(t_my_framebuffer*, int, int, sfColor);
void			run(t_win);
int			create_thread(t_win*);
void			init_var(t_win*);

//Error handling and args type
int     get_args_type(char **argv);
int     check_env(char **env);

#endif /* !RT2_H_ */
