/*
** multi_threads.c for multi_threads in /home/descou_c/Graphic/test/raytracer2/threads
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sun May 28 14:11:37 2017 Charles Descoust
** Last update Sun May 28 17:14:04 2017 Charles Descoust
*/

#include "../inc/rt2.h"

int		multi_threads(t_win win, sfVector2i* pos_min,
			      sfVector2i* pos_max, t_object ***objs)
{
  pthread_t	th[4];
  t_data	data[4];

  data[0] = init_data(pos_min[0], pos_max[0], win.buffer, objs[0]);
  data[1] = init_data(pos_min[1], pos_max[1], win.buffer, objs[1]);
  data[2] = init_data(pos_min[2], pos_max[2], win.buffer, objs[2]);
  data[3] = init_data(pos_min[3], pos_max[3], win.buffer, objs[3]);
  pthread_create(&th[0], NULL, raytrace_scene, (void*)(&data[0]));
  pthread_create(&th[1], NULL, raytrace_scene, (void*)(&data[1]));
  pthread_create(&th[2], NULL, raytrace_scene, (void*)(&data[2]));
  pthread_create(&th[3], NULL, raytrace_scene, (void*)(&data[3]));
  pthread_join(th[0], NULL);
  pthread_join(th[1], NULL);
  pthread_join(th[2], NULL);
  pthread_join(th[3], NULL);
  if (calc_new_buffer(data->buffer) == NULL)
    return (84);
  draw(win);
  process_game_loop(win.win);
  return (0);
}
