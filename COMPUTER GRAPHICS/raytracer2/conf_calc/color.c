/*
** color.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/conf_calc
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu May  4 15:39:37 2017 Charles Aubert
** Last update Sun May 28 15:46:04 2017 Charles Aubert
*/

#include "../inc/rt2.h"

float   get_coef(t_object *obj, sfVector3f n_pos,
                 sfVector3f dir_light)
{
  float coef;

  if (obj->t == MY_SPHERE)
    n_pos = get_normal_sphere(n_pos);
  else if (obj->t == MY_CYLINDER)
    n_pos = get_normal_cylinder(n_pos);
  else if (obj->t == MY_CONE)
    n_pos = get_normal_cone(n_pos, obj->r);
  else if (obj->t == MY_PLAN)
    n_pos = get_normal_plane(obj->r);
  else if (obj->t == MY_STRIP)
    n_pos = get_normal_strip(n_pos, obj->r);
  else if (obj->t == MY_PARABOLOID)
    n_pos = get_normal_paraboloid(n_pos);
  else if (obj->t == MY_ELLIPSOID)
    n_pos = get_normal_ellipsoid(n_pos, obj->coef);
  else if (obj->t == MY_HYPERBOLOID1)
    n_pos = get_normal_hyperboloid1(n_pos, obj->coef);
  else if (obj->t == MY_HYPERBOLOID2)
    n_pos = get_normal_hyperboloid2(n_pos, obj->coef);
  coef = get_light_coef(dir_light, n_pos);
  return (coef);
}

int             get_shadow(t_objects t, sfVector3f dir, sfVector3f light,
                           int row)
{
  int           i;
  prep		function;

  i = 0;
  while (t.objs[i] != NULL)
    {
      if (i != row)
        {
          if (t.objs[i]->t >= 0 && t.objs[i]->t < OBJ_COUNT)
	    {
	      function = t.func[t.objs[i]->t];
	      t.objs[i]->k = function(light, dir, t.objs[i]->r, t.objs[i]);
	    }
          else if (t.objs[i]->t == MY_PLAN)
            t.objs[i]->k = plane_prep(light, dir, t.objs[i]);
          else
            t.objs[i]->k = -1.0;
          if (t.objs[i]->k > 0.0 && t.objs[i]->k < 1.0)
            return (100);
        }
      i += 1;
    }
  return (0);
}

sfColor         apply_color(sfColor color, t_coef aver, int size, float bril)
{
  float         ac;
  float         as;
  float         c;
  sfColor       avc;

  avc = average_color_coef(aver.color, size, aver.coef, bril);
  ac = average_coef(aver.coef, size);
  as = average_shadow(aver.shadow, size);
  c = (color.r * ac) +  (float)avc.r;
  color.r = c > 255.0 ? 255 : c;
  c = (color.g * ac) +  (float)avc.g;
  color.g = c > 255.0 ? 255 : c;
  c = (color.b * ac) +  (float)avc.b;
  color.b = c > 255.0 ? 255 : c;
  c = (color.a - as) * ac;
  color.a = c > 255 ? 255 : c;
  free(aver.coef);
  free(aver.shadow);
  return (color);
}

t_coef		calc_average(t_objects tools, int i, int size)
{
  sfVector3f    n_pos;
  sfVector3f    dir_light;
  t_coef	coefs;
  int		i2;

  i2 = 0;
  if ((coefs.coef = malloc(sizeof(float) * size)) == NULL ||
      (coefs.shadow = malloc(sizeof(int) * size)) == NULL ||
      (coefs.color = malloc(sizeof(sfColor) * size)) == NULL)
    return (coefs);
  while (tools.lights[i2] != NULL)
    {
      n_pos = apply_k(tools.vect->eye, tools.vect->dir, tools.objs[i]->k);
      dir_light = calc_dir_light(n_pos, tools.lights[i2]->pos);
      coefs.shadow[i2] = get_shadow(tools, dir_light, n_pos, i);
      dir_light = rotate_xyz_in(dir_light, tools.objs[i]->rot);
      n_pos = rotate_xyz_in(translate_in(n_pos, tools.objs[i]->pos),
                            tools.objs[i]->rot);
      if (tools.objs[i]->b == 1 && tools.objs[i]->t == MY_PLAN)
	tools.objs[i]->c = checkboard(n_pos, tools.objs[i]);
      coefs.coef[i2] = get_coef(tools.objs[i], n_pos, dir_light);
      coefs.color[i2] = tools.lights[i2]->c;
      i2 += 1;
    }
  return (coefs);
}

sfColor         get_color(sfColor color, int i, t_objects tools)
{
  int           size;
  t_coef	coefs;

  size = light_number(tools.lights);
  coefs = calc_average(tools, i, size);
  if (coefs.coef == NULL || coefs.shadow == NULL || coefs.color == NULL)
    return (sfBlack);
  return (apply_color(color, coefs, size, tools.objs[i]->bril));
}
