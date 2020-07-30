/*
** calc.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/conf_calc
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu May  4 15:14:43 2017 Charles Aubert
** Last update Thu May 25 10:14:44 2017 Charles Aubert
*/

#include "../inc/rt2.h"

int     light_number(t_object **obj)
{
  int   i;

  i = 0;
  while (obj[i] != NULL)
    i += 1;
  return (i);
}

sfVector3f      apply_k(sfVector3f pos, sfVector3f dir, float k)
{
  sfVector3f    result;

  result.x = pos.x + dir.x * k;
  result.y = pos.y + dir.y * k;
  result.z = pos.z + dir.z * k;
  return (result);
}

sfColor         put_color(t_objects tools)
{
  int           i;

  i = get_smallest(tools.objs);
  if (tools.objs[i]->k <= 0.0)
    return (sfBlack);
  else
    return (get_color(sfColor_fromRGBA(tools.objs[i]->c.r, tools.objs[i]->c.g,
				       tools.objs[i]->c.b, tools.objs[i]->c.a), i, tools));
}

int             get_smallest(t_object **objs)
{
  int           i;
  t_object      *obj;
  int           save;

  i = 0;
  obj = objs[0];
  save = i;
  while (objs[i] != NULL)
    {
      if (objs[i]->k > 0.0)
        {
          if (obj->k <= 0.0)
            {
              obj = objs[i];
              save = i;
            }
          else if (obj->k > 0.0 && objs[i]->k < obj->k)
            {
              obj = objs[i];
              save = i;
            }
        }
      i += 1;
    }
  return (save);
}

sfColor         calc(t_objects tools)
{
  int           i;
  prep		function;

  i = 0;
  while (tools.objs[i] != NULL)
    {
      if (tools.objs[i]->t >= 0 && tools.objs[i]->t < OBJ_COUNT)
	{
	  function = tools.func[tools.objs[i]->t];
	  tools.objs[i]->k = function(tools.vect->eye,
				      tools.vect->dir, tools.objs[i]->r, tools.objs[i]);
	}
      else if (tools.objs[i]->t == MY_PLAN)
        tools.objs[i]->k = plane_prep(tools.vect->eye, tools.vect->dir,
				      tools.objs[i]);
      else
        tools.objs[i]->k = -1.0;
      i += 1;
    }
  return (put_color(tools));
}
