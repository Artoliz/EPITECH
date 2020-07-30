/*
** main.c for main_wirefram in /home/descou_c/Graphic/wireframe
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Nov 24 14:07:20 2016 Charles Descoust
** Last update Sat Dec 10 12:11:29 2016 Charles Descoust
*/

#include "include/wire.h"

int			main(int ac, char **av)
{
  int			i;
  t_tab			tab;
  t_my_framebuffer	*buffer;
  sfVideoMode		mode;

  if (ac != 2)
    return (84);
  i = 0;
  while (av[1][i] != '\0' && av[1][i] != '.')
    i = i + 1;
  if (av[1][i] != '.' && av[1][i + 1] != 'w' && av[1][i + 2] != 'f')
    return (84);
  tab = check_name_file(av[1]);
  mode = my_create_mode();
  buffer = my_framebuffer_create(mode.width, mode.height);
  open_window(tab, buffer, mode);
  free(buffer->pixels);
  free(buffer);
  return (0);
}
