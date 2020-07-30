/*
** window.c for  in /home/miklox/semestre1/infographie/bsraytracer1
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Mon Feb  6 18:09:01 2017 Bastien LECUSSAN
** Last update Sat May 27 12:46:09 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

int		window_destroy(t_frame *window)
{
  sfEvent	close;

  if ((window->scene = get_tab_obj(window->scene)) == NULL
      || check_correct_obj(window->scene) == 84)
    return (84);
  if ((window->scene = get_equation(window->scene)) == NULL)
    return (84);
  if (my_raytracer(window) == 84)
    return (84);
  while (sfRenderWindow_isOpen(window->window))
    {
      window_refresh(window);
      while (sfRenderWindow_pollEvent(window->window, &close))
	{
	  if (close.type == sfEvtClosed)
	    sfRenderWindow_close(window->window);
	  if (close.key.code == sfKeyEscape)
	    sfRenderWindow_close(window->window);
	}
    }
  sfRenderWindow_destroy(window->window);
  sfSprite_destroy(window->sprite);
  sfTexture_destroy(window->texture);
  return (0);
}

void    window_refresh(t_frame *window)
{
  sfRenderWindow_clear(window->window, sfBlack);
  sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
  sfRenderWindow_display(window->window);
  sfTexture_updateFromPixels(window->texture, window->frameb->pixels,
			     S_WIDTH, S_HEIGHT, 0, 0);
}

t_my_framebuffer        *frameb_create(int width,
				       int height)
{
  int                   count;
  sfUint8               *pixels;
  t_my_framebuffer      *frameb;

  count = 0;
  frameb = malloc(sizeof(*frameb));
  pixels = malloc(sizeof(*pixels) * width * height * 4);
  if (pixels == NULL)
    return (0);
  while (count < width * height * 4)
    {
      pixels[count] = 0;
      count = count + 1;
    }
  frameb->pixels = pixels;
  frameb->width = width;
  frameb->height = height;
  return (frameb);
}

sfRenderWindow          *create_window_obj(char *name, int width, int height)
{
  sfVideoMode           mode;
  sfRenderWindow        *window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (window);
  return (window);
}
