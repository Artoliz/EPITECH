/*
** write_command.c for write_command in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed May 31 09:36:42 2017 Charles Descoust
** Last update Thu Jun  1 13:24:06 2017 Charles Descoust
*/

#include "inc/n4s.h"

int	write_command(char *str)
{
  char	**buff;

  write(1, str, my_strlen(str));
  if ((buff = my_split(get_next_line(0), ":")) == NULL)
    return (84);
  return (end_of_track(buff));
}
