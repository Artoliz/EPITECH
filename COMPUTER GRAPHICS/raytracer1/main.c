/*
** main.c for main in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Feb 14 13:23:58 2017 Charles Descoust
** Last update Wed Apr  5 09:25:47 2017 Charles Descoust
*/

#include "inc/my.h"

int		open_window(t_my_win win)
{
  sfEvent	event;

  while (sfRenderWindow_isOpen(win.window))
    {
      while (sfRenderWindow_pollEvent(win.window, &event))
	{
	  if (event.type == sfEvtClosed)
            sfRenderWindow_close(win.window);
          if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(win.window);
	}
      /* sfTexture_updateFromPixels(win.texture, win.buffer->pixels, */
      /* 				 WIDTH, HEIGHT, 0, 0); */
      /* sfRenderWindow_clear(win.window, sfBlack); */
      /* sfRenderWindow_drawSprite(win.window, win.sprite, NULL); */
      /* sfRenderWindow_display(win.window); */
    }
  return (0);
}

int			create_thread(t_my_win* win)
{
  pthread_t		th[4];
  int			i;
  /* pthread_attr_t	attr; */

  /* if (pthread_attr_init(&attr) != 0) */
  /*   return (84); */
  /* win->mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER; */
  i = 0;
  while (i < 4)
    {
      win->idx = i;
      if (pthread_create(&th[i], NULL, pixels_walk, win) == -1)
        return (84);
      if (pthread_join(th[i], NULL) == -1)
        return (84);
      i += 1;
    }
  /* i = 0; */
  /* while (i < 4) */
  /*   { */
  /*     if (pthread_join(th[i], NULL) == -1) */
  /*       return (84); */
  /*     i += 1; */
  /*   } */
  /* pthread_mutex_destroy(&win->mutex); */
  return (0);
}

void    init_var(t_my_win *win)
{
  win->var[0].pos.x = 0;
  win->var[0].pos.y = 0;
  win->var[0].max.x = WIDTH / 2;
  win->var[0].max.y = HEIGHT / 2;
  win->var[0].save = win->var[0].pos.y;
  win->var[0].color = sfRed;
  win->var[1].pos.x = WIDTH / 2;
  win->var[1].pos.y = 0;
  win->var[1].max.x = WIDTH;
  win->var[1].max.y = HEIGHT / 2;
  win->var[1].save = win->var[1].pos.y;
  win->var[1].color = sfBlue;
  win->var[2].pos.x = 0;
  win->var[2].pos.y = HEIGHT / 2;
  win->var[2].max.x = WIDTH / 2;
  win->var[2].max.y = HEIGHT;
  win->var[2].save = win->var[2].pos.y;
  win->var[2].color = sfGreen;
  win->var[3].pos.x = WIDTH / 2;
  win->var[3].pos.y = HEIGHT / 2;
  win->var[3].max.x = WIDTH;
  win->var[3].max.y = HEIGHT;
  win->var[3].save = win->var[3].pos.y;
  win->var[3].color = sfYellow;
}

int			window(t_my_object *obj, t_my_pos basic)
{
  sfVideoMode           mode;
  t_my_framebuffer*     buffer;
  sfTexture*            texture;
  sfSprite*             sprite;
  t_my_win              win;

  mode = create_my_mode();
  buffer = my_framebuffer_create(mode.width, mode.height);
  texture = create_my_texture(mode);
  sprite = create_my_sprite(texture);
  win = create_my_win(mode, buffer, texture, sprite);
  init_var(&win);
  win.obj = obj;
  win.basic = basic;
  create_thread(&win);
  /* pixels_walk(obj, basic, win); */
  open_window(win);
  sfSprite_destroy(win.sprite);
  sfTexture_destroy(win.texture);
  sfRenderWindow_destroy(win.window);
  return (0);
}

int	let_s_start(int ac, char** av)
{
  t_my_object   *obj;
  t_my_pos      basic;

  if ((obj = malloc(sizeof(*obj))) == NULL)
    return (84);
  if (ac == 1)
    {
      if ((obj = init_basic_objs(obj)) == NULL)
        return (84);
      basic = init_basic();
    }
  else if (ac == 2)
    {
      if ((obj = parse_file(av[1], obj)) == NULL)
        return (84);
      basic = add_my_basic_pos(obj);
      if ((obj = remove_maillon(obj)) == NULL)
        return (84);
    }
  else
    return (84);
  window(obj, basic);
  free(obj);
  return (0);
}

int	check_env(char** env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strcmp(env[i], "DISPLAY=:0") == 0)
	return (0);
      i = i + 1;
    }
  return (84);
}

int		main(int ac, char **av, char **env)
{
  if (check_env(env) == 84)
    {
      write(2, "Where is \"DISPLAY\" environment variable ? ;)\n", 45);
      return (84);
    }
  if (let_s_start(ac, av) == 84)
    return (84);
  return (0);
}
