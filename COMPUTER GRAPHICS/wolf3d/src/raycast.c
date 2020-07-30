/*
** raycast.c for raycast in /home/descou_c/Graphic/bswolf3d/src
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec 13 11:08:58 2016 Charles Descoust
** Last update Thu Jan 12 11:31:10 2017 Charles Descoust
*/

#include "../inc/my.h"

sfVector2f	calc_new_pos(sfVector2f pos, float direction)
{
  sfVector2f	pos1;

  pos1.x = cos(direction * M_PI / 180);
  pos1.y = sin(direction * M_PI / 180);
  pos1.x = pos.x - pos1.x;
  pos1.y = pos.y + pos1.y;
  return (pos1);
}

sfVector2f	calc_vec_dir(sfVector2f pos, sfVector2f pos1)
{
  sfVector2f	vec;

  vec.x = pos1.x - pos.x;
  vec.y = pos1.y - pos.y;
  return (vec);
}

float		raycast(sfVector2f pos, float direction, int **map, sfVector2i mapSize)
{
  sfVector2f	pos1;
  sfVector2f	vec;
  float		i;
  float		x;
  float		y;

  pos1 = calc_new_pos(pos, direction);
  vec = calc_vec_dir(pos, pos1);
  i = 1;
  while (i < sqrt(pow(mapSize.x, 2) + pow(mapSize.y, 2)))
    {
      x = pos.x + i * vec.x;
      y = pos.y + i * vec.y;
      if ((x >= 0 && x < mapSize.x) && (y >= 0 && y < mapSize.y))
	{
	  if (map[(int)y][(int)x] == 1)
	    return (i);
	}
      i = i + 0.005;
    }
}
