/*
** init_fct.c for init_fct in /home/descou_c/Graphic/test/raytracer2/threads
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sun May 28 14:18:07 2017 Charles Descoust
** Last update Sun May 28 14:46:33 2017 Charles Descoust
*/

#include "../inc/rt2.h"

sfVector2i	*init_pos_max()
{
  sfVector2i	*pos;

  if ((pos = malloc(sizeof(sfVector2i) * 4)) == NULL)
    return (NULL);

  pos[0].x = WIDTH / 2;
  pos[0].y = HEIGHT / 2;
  pos[1].x = WIDTH;
  pos[1].y = HEIGHT / 2;
  pos[2].x = WIDTH / 2;
  pos[2].y = HEIGHT;
  pos[3].x = WIDTH;
  pos[3].y = HEIGHT;
  return (pos);
}

sfVector2i	*init_pos_min()
{
  sfVector2i	*pos;

  if ((pos = malloc(sizeof(sfVector2i) * 4)) == NULL)
    return (NULL);
  pos[0].x = 0;
  pos[0].y = 0;
  pos[1].x = WIDTH / 2;
  pos[1].y = 0;
  pos[2].x = 0;
  pos[2].y = HEIGHT / 2;
  pos[3].x = WIDTH / 2;
  pos[3].y = HEIGHT / 2;
  return (pos);
}

t_data		init_data(sfVector2i min, sfVector2i max,
			  t_my_framebuffer *buffer, t_object **objs)
{
  t_data	data;

  data.tools.objs = objs;
  data.tools.lights = get_lights(data.tools.objs);
  data.tools.vect = create_vectors(data.tools.objs);
  data.tools = create_func_prep(data.tools);
  data.tools.vect->size.x = WIDTH;
  data.tools.vect->size.y = HEIGHT;
  data.buffer = buffer;
  data.max_x = max.x;
  data.max_y = max.y;
  data.min_x = min.x;
  data.min_y = min.y;
  return (data);
}
