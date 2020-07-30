/*
** main.c for  in /home/miklox/semestre1/infographie/bsraytracer1
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Mon Feb  6 18:05:43 2017 Bastien LECUSSAN
** Last update Sat May 27 21:44:07 2017 Charles Aubert
*/

#include "raytracer2.h"

int             start_obj(char **argv)
{
  t_frame       *window;

  if ((window = malloc(sizeof(*window))) == NULL)
    return (my_printf(2, 84, "An error occured with malloc.\n"));
  if ((window->total = create_list_vertex(argv[1])) == NULL)
    return (my_printf(2, 84, "An error occured with the scene.\n"));
  window->scene = window->total->obj;
  if (window->scene == NULL)
    return (my_printf(2, 84, "la scene est nulle\n"));
  window->window = create_window_obj("Raytracer2 - Obj", S_WIDTH, S_HEIGHT);
  window->texture = sfTexture_create(S_WIDTH, S_HEIGHT);
  window->sprite = sfSprite_create();
  window->frameb = frameb_create(S_WIDTH, S_HEIGHT);
  sfSprite_setTexture(window->sprite, window->texture, sfTrue);
  sfTexture_updateFromPixels(window->texture, window->frameb->pixels,
			     S_WIDTH, S_HEIGHT, 0, 0);
  if (window_destroy(window) == 84)
    return (84);
  free_list_obj_mtl(window->total);
  my_free(window);
  return (0);
}

void	my_free(t_frame *window)
{
  free(window->frameb->pixels);
  free(window->frameb);
  free(window);
}
