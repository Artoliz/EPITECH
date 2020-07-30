/*
** main.c for main in /home/descou_c/Graphic/bswolf3d
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec 13 08:56:11 2016 Charles Descoust
** Last update Mon Jan 23 13:41:51 2017 Charles Descoust
*/

#include "inc/my.h"

int			main(int ac, char **av)
{
  t_my_framebuffer	*framebuffer;
  sfVideoMode		mode;

  if (ac != 2)
    return (84);
  mode = my_create_mode();
  framebuffer = my_framebuffer_create(mode.width, mode.height);
  if (open_window(mode, framebuffer, av[1]) == -1)
    return (84);
  return (0);
}
