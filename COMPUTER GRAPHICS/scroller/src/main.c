/*
** main.c for main in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 13:23:58 2017 Charles Descoust
** Last update Sun Apr  2 22:45:54 2017 Amardeilh Guilhem
*/

#include "../inc/my.h"

int		aff_while(t_my_win win, t_sprite *sprites, t_oki *time)
{
  time_t	count;

  clock_gettime(CLOCK_REALTIME, &(time->tp));
  count = time->tp.tv_sec - time->start;
  sfRenderWindow_clear(win.window, sfBlack);
  if (count <= 14)
    {
      aff_bg_light(win, sprites, count);
      aff_sun(win, sprites->sun);
      aff_title(win, sprites->title);
    }
  else
    {
      aff_bg_dark(win, sprites);
      aff_sun(win, sprites->luna);
    }
  aff_sky(win, sprites, count);
  squall_event(win, sprites->squall, count);
  fireball_event(win, sprites->fireball, count);
  if ((count >= 14 && count <= 16) || count >= 21)
    aff_fade(win, sprites->fading, count);
  move_pos(sprites->title);
  if (count == 22)
    return (0);
  return (1);
}

int		open_window(t_my_win win, t_sprite *sprites)
{
  sfEvent	event;
  t_oki		*time;

  time = start_clock();
  while (sfRenderWindow_isOpen(win.window))
    {
      while (sfRenderWindow_pollEvent(win.window, &event))
	{
	  if (event.type == sfEvtClosed)
            sfRenderWindow_close(win.window);
          if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(win.window);
	}
      sfTexture_updateFromPixels(win.texture, win.buffer->pixels,
				 WIDTH, HEIGHT, 0, 0);
      if (!aff_while(win, sprites, time))
	return (0);
      sfRenderWindow_drawSprite(win.window, win.sprite, NULL);
      sfRenderWindow_display(win.window);
    }
  return (0);
}

int		window(t_my_win win)
{
  sfMusic	*music;
  t_sprite	*sprites;

  if ((sprites = load_sprites()) == NULL)
    return (84);
  if ((music = sfMusic_createFromFile("./ref/us/Airship.ogg")) == NULL)
    return (84);
  sfMusic_play(music);
  open_window(win, sprites);
  return (0);
}

int			main()
{
  sfVideoMode           mode;
  t_my_framebuffer*     buffer;
  sfTexture*            texture;
  sfSprite*             sprite;
  t_my_win              win;

  mode = create_my_mode();
  if ((buffer = my_framebuffer_create(mode.width, mode.height)) == NULL)
    return (84);
  texture = create_my_texture(mode);
  sprite = create_my_sprite(texture);
  win = create_my_win(mode, buffer, texture, sprite);
  if (window(win) == 84)
    return (84);
  sfSprite_destroy(win.sprite);
  sfTexture_destroy(win.texture);
  sfRenderWindow_destroy(win.window);
  return (0);
}
