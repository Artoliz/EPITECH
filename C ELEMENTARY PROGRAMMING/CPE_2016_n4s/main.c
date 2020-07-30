/*
** main.c for main in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon May  1 14:36:32 2017 Charles Descoust
** Last update Thu Jun  1 13:23:56 2017 Charles Descoust
*/

#include "inc/n4s.h"

int	end_of_track(char** ans)
{
  int	i;

  i = 0;
  while (ans[i] != NULL)
    {
      if (my_strcmp(ans[i], END) == 0)
      	return (1);
      i += 1;
    }
  return (0);
}

int	start_race(void)
{
  char	**ans;
  int	ret;

  ret = 0;
  while (42)
    {
      write(1, RAY, my_strlen(RAY));
      if ((ans = my_split(get_next_line(0), ":")) == NULL)
      	return (84);
      if (end_of_track(ans) == 1)
      	break;
      if ((ret = speed(ans)) == 1)
      	break;
      write(1, RAY, my_strlen(RAY));
      if ((ans = my_split(get_next_line(0), ":")) == NULL)
      	return (84);
      if (end_of_track(ans) == 1)
      	break;
      if ((ret = move_wheels(ans)) == 1)
	break;
      if (ret == 84)
	return (84);
    }
  return (0);
}

int	main(int ac, char **av)
{
  char	**ans;

  (void)av;
  if (ac != 1)
    return (84);
  write(1, START, my_strlen(START));
  if ((ans = my_split(get_next_line(0), ":")) == NULL)
    return (84);
  if (start_race() == 84)
    return (put_err("An error occured !\n"));
  write(1, STOP, my_strlen(STOP));
  if ((ans = my_split(get_next_line(0), ":")) == NULL)
    return (84);
  return (0);
}
