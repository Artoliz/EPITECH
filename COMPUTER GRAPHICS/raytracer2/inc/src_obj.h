/*
** src.h for  in /home/miklox/semestre2/infographie/raytracer1
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue Feb 14 09:57:38 2017 Bastien LECUSSAN
** Last update Sat May 27 12:39:41 2017 Bastien LECUSSAN
*/

#ifndef SRC_H_
# define SRC_H_

sfVector3f		translate(sfVector3f, sfVector3f);
sfVector3f		rotate_zyx(sfVector3f, sfVector3f);
void                    my_put_pixel(t_my_framebuffer *, int, int,
				     sfColor);
void			calc_dir_vector_obj(float, sfVector2i *,
					    sfVector2i *, sfVector3f *);
float			get_light_coef(sfVector3f *, sfVector3f *);

#endif /* !SRC_H_ */
