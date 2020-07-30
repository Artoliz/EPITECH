/*
** conf.h for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/conf_gen
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue May  2 21:34:52 2017 Charles Aubert
** Last update Sun May 28 17:07:40 2017 Charles Descoust
*/

#ifndef CONF_H_
# define CONF_H_

#include "rt2.h"

typedef double	(*prep)(sfVector3f, sfVector3f, double, t_object *);

typedef struct  s_vectors
{
  sfVector3f    eye;
  sfVector3f    r_eye;
  sfVector3f    dir;
  sfVector2i    size;
  sfVector2f    pos;
  sfVector3f    light;
}               t_vectors;

typedef	struct	s_objects
{
  prep		func[OBJ_COUNT];
  t_object	**objs;
  t_object	**lights;
  t_vectors	*vect;
}		t_objects;

typedef struct	s_coef
{
  float		*coef;
  int		*shadow;
  sfColor	*color;
}		t_coef;

t_objects       create_fun_prep(t_objects tools);
int		start_conf(char *name);
t_object        **get_lights(t_object **objs);
t_vectors	*create_vectors(t_object **objs);
sfColor         get_color_average(t_objects tools, float x, float y);
sfColor         no_aliasing(t_objects tools);
sfColor         *init_aliasing(int *i, float *incr);
int             get_smallest(t_object **objs);
sfColor         put_color(t_objects tools);
sfColor         calc(t_objects tools);
double		sphere_prep(sfVector3f e, sfVector3f v,
			    double r, t_object *obj);
double		strip_prep(sfVector3f e, sfVector3f v,
			   double r, t_object *obj);
double		cone_prep(sfVector3f e, sfVector3f v,
			  double r, t_object *obj);
double		cylinder_prep(sfVector3f e, sfVector3f v,
			      double r, t_object *obj);
double		paraboloid_prep(sfVector3f e, sfVector3f v,
				double r, t_object *obj);
double		ellipsoid_prep(sfVector3f e, sfVector3f v,
			       double r, t_object *obj);
double		hyperboloid1_prep(sfVector3f e, sfVector3f v,
				  double r, t_object *obj);
double		hyperboloid2_prep(sfVector3f e, sfVector3f v,
				  double r, t_object *obj);
double		plane_prep(sfVector3f e, sfVector3f v, t_object *obj);
sfVector3f      apply_k(sfVector3f pos, sfVector3f dir, float k);
float		get_coef(t_object *obj, sfVector3f n_pos,
			 sfVector3f dir_light);
sfColor         get_color(sfColor color, int i, t_objects tools);
sfColor		average_color_coef(sfColor *colors, int size,
				   float *coef, float bril);
int             get_shadow(t_objects tools, sfVector3f dir, sfVector3f light,
                           int row);
sfColor         apply_color(sfColor color, t_coef aver, int size, float bril);
sfVector3f      calc_dir_light(sfVector3f pos, sfVector3f light);
float		get_light_coef(sfVector3f l_v, sfVector3f n_v);
sfColor		average_color(sfColor *colors, int size);
float		average_coef(float *coef, int size);
float		average_shadow(int *coef, int size);
sfColor         get_color_average(t_objects tools, float x, float y);
int		light_number(t_object **obj);
sfVector3f      calc_dir_vector(float dist,
                                sfVector2i screen_size, sfVector2f screen_pos);
sfColor         checkboard(sfVector3f v, t_object *);

#endif /* !CONF_H_ */
