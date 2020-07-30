/*
** win.c for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2/win_gen
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed May  3 11:08:56 2017 Charles Aubert
** Last update Tue May 23 09:35:38 2017 Charles Aubert
*/

#include "../inc/rt2.h"

int             process_game_loop(sfRenderWindow *window)
{
  while (sfRenderWindow_isOpen(window))
    {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
          sfRenderWindow_close(window);
    }
  return (0);
}

sfRenderWindow          *create_window(char *name)
{
  sfRenderWindow        *window;
  sfVideoMode           mode;

  mode.width = WIDTH;
  mode.height = HEIGHT;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (!window)
    return (NULL);
  return (window);
}

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
  t_my_framebuffer      *new_framebuffer;
  int                   i;

  i = 0;
  if ((new_framebuffer = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  if ((new_framebuffer->pixels = malloc(width * height *
					sizeof(sfUint8) * 4)) == NULL)
    return (NULL);
  new_framebuffer->height = height;
  new_framebuffer->width = width;
  while (i < width * height * 4)
    {
      new_framebuffer->pixels[i] = 0;
      i += 1;
    }
  return (new_framebuffer);
}

int	check_win(t_win res)
{
  if (res.win == NULL || res.sprite == NULL || res.buffer == NULL ||
      res.texture == NULL)
    return (1);
  return (0);
}

t_win	create_win_struct(char *name, int width, int height)
{
  t_win	res;

  res.win = create_window(name);
  res.sprite = sfSprite_create();
  res.buffer = my_framebuffer_create(width, height);
  res.texture = sfTexture_create(width, height);
  sfSprite_setTexture(res.sprite, res.texture, sfTrue);
  return (res);
}
