/*
** src.h for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/src
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue May  2 21:27:53 2017 Charles Aubert
** Last update Thu May 25 10:18:09 2017 Charles Aubert
*/

#ifndef SRC_H_
# define SRC_H_

#include "rt2.h"

# define PI 3.14159265358979323846

typedef struct  s_cubic
{
  double	q;
  double	r;
  double	bq;
  double	br;
  double	bq3;
  double	br2;
  double	cr2;
  double	cq3;
  double	sqrtbq;
  double	sgnbr;
  double	ratio;
  double	theta;
  double	norm;
  double	r0;
  double	r1;
  double	r2;
  double	ba;
  double	bb;
  int		i;
}		t_cubic;

/* Rotations */
sfVector3f      rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f      rotate_zyx(sfVector3f to_rotate, sfVector3f angles);
sfVector3f      rotate_zyx_in(sfVector3f to_rotate, sfVector3f angles);
sfVector3f      rotate_xyz_in(sfVector3f to_rotate, sfVector3f angles);
sfVector3f      rotate_x(sfVector3f to, float r);
sfVector3f      rotate_y(sfVector3f to, float r);
sfVector3f      rotate_z(sfVector3f to, float r);

/* Intersections */
double          intersect_sphere(sfVector3f e, sfVector3f v, double r);
double          intersect_cylinder(sfVector3f e, sfVector3f v, double r);
double          intersect_plane(sfVector3f e, sfVector3f v);
double          intersect_cone(sfVector3f e, sfVector3f v, double r);
double          intersect_paraboloid(sfVector3f e, sfVector3f v);
double		intersect_ellipsoid(sfVector3f e, sfVector3f v, sfVector3f t,
				    double r);
double		intersect_hyperboloid1(sfVector3f e, sfVector3f v, double r,
				       sfVector3f t);
double		intersect_hyperboloid2(sfVector3f e, sfVector3f v,
				       double r, sfVector3f t);

/* Translations */
sfVector3f      translate(sfVector3f to_translate, sfVector3f translations);
sfVector3f      translate_in(sfVector3f to_translate, sfVector3f translations);
sfVector3f      multiply_vec(sfVector3f v, double m);

/* Normal calculations */
sfVector3f      get_normal_cylinder(sfVector3f i_p);
sfVector3f      get_normal_sphere(sfVector3f i_p);
sfVector3f      get_normal_plane(int upward);
sfVector3f      get_normal_cone(sfVector3f i_p, double semi_angle);
sfVector3f      get_normal_ellipsoid(sfVector3f i_p, sfVector3f coef);
sfVector3f      get_normal_paraboloid(sfVector3f i_p);
sfVector3f      get_normal_hyperboloid1(sfVector3f i_p, sfVector3f coef);
sfVector3f      get_normal_hyperboloid2(sfVector3f i_p, sfVector3f coef);
sfVector3f      get_normal_strip(sfVector3f i_p, double scale);

/* Other tools */
int		double_sign(double x);
int             double_swap(double *a, double *b);
int             solve_cubic(double *a, double *r);
sfVector3f      create_vect3(float a, float b, float c);
double		check_k_value(double delta, double a, double b);
void		init_strip(t_strip m, double *coeff);

#endif /* !SRC_H_ */
