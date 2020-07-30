/*
** raytrace.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/conf_calc
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu May  4 15:06:40 2017 Charles Aubert
** Last update Sun May 28 17:08:37 2017 Charles Descoust
*/

#include "../inc/rt2.h"

sfColor         no_aliasing(t_objects tools)
{
  tools.vect->dir = rotate_xyz(calc_dir_vector(500.0, tools.vect->size,
					       tools.vect->pos),
			       tools.vect->r_eye);
  return (calc(tools));
}

sfColor         *init_aliasing(int *i, float *incr)
{
  sfColor       *colors;

  *i = 0;
  *incr = 1 / ((float)AL / 2);
  if ((colors = malloc(sizeof(sfColor) * (AL * (AL / 4)))) == NULL)
    return (NULL);
  return (colors);
}

void            *raytrace_scene(void *args)
{
  t_data        *data;
  sfVector2i    pos;
  sfColor       color;

  data = (t_data*)args;
  pos.y = data->min_y;
  while (pos.y < data->max_y)
    {
      pos.x = data->min_x;
      while (pos.x < data->max_x)
        {
          data->tools.vect->pos.x = pos.x;
          data->tools.vect->pos.y = pos.y;
          if (pos.x > 0 && pos.y > 0 && AL > 1 && AL % 4 == 0)
            data->tools.vect->pos.y -= 0.5;
          color = get_color_average(data->tools, pos.x, pos.y);
          my_put_pixel(data->buffer, pos.x, pos.y, color);
          pos.x += 1;
        }
      pos.y += 1;
    }
  return (NULL);
}
