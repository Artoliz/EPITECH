/*
** my_threads.h for my_thread in /home/descou_c/Graphic/test/raytracer2
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri May 26 11:54:39 2017 Charles Descoust
** Last update Sun May 28 18:44:58 2017 Bastien LECUSSAN
*/

#ifndef MY_THREADS_H_
# define MY_THREADS_H_

typedef struct		s_data
{
  t_objects		tools;
  t_my_framebuffer	*buffer;
  int			max_x;
  int			max_y;
  int			min_x;
  int			min_y;
}			t_data;

int			multi_threads(t_win win,  sfVector2i* pos_min,
				      sfVector2i *pos_max, t_object ***objs);

t_data			init_data(sfVector2i min, sfVector2i max,
				  t_my_framebuffer *buffer, t_object **objs);
sfVector2i		*init_pos_min();
sfVector2i		*init_pos_max();

sfColor			newcolor(t_my_framebuffer* buffer, sfVector2i *pos);
t_my_framebuffer	*calc_new_buffer(t_my_framebuffer* buffer);

t_objects		create_func_prep(t_objects tools);

void			*raytrace_scene(void* args);

#endif /* !MY_THREADS_H_ */
