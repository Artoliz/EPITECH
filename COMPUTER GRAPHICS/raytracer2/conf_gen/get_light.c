/*
** get_light.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/conf_gen
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed May  3 09:50:36 2017 Charles Aubert
** Last update Thu May  4 16:06:45 2017 Charles Aubert
*/

#include "../inc/rt2.h"

int	count_light(t_object **objs)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (objs[i] != NULL)
    {
      if (objs[i]->t == MY_LIGHT)
	count += 1;
      i += 1;
    }
  return (count);
}

t_object        **get_lights(t_object **objs)
{
  int           count;
  int           i;
  int           i2;
  t_object      **res;

  count = count_light(objs);
  if ((res = malloc(sizeof(t_object *) * (count + 1))) == NULL)
    return (NULL);
  i = 0;
  i2 = 0;
  while (objs[i] != NULL)
    {
      if (objs[i]->t == MY_LIGHT)
        {
          res[i2] = objs[i];
          i2 += 1;
        }
      i += 1;
    }
  res[i2] = NULL;
  return (res);
}
