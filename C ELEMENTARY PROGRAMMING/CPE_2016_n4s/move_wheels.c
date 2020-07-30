/*
** move_wheels.c for move_wheels in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed May 31 09:41:30 2017 Charles Descoust
** Last update Sun Jun  4 15:19:50 2017 Bryan Medica
*/

#include "inc/n4s.h"

int	move_left_and_right(float neg, char *cmd)
{
  char	**ans;

  write(1, WHEELS, my_strlen(WHEELS));
  if (neg < 0)
    write(1, "-", 1);
  write(1, cmd, my_strlen(cmd));
  if ((ans = my_split(get_next_line(0), ":")) == NULL)
    return (84);
  return (end_of_track(ans));
}

int	check_speed(float middle, char **ans)
{
  if (middle < 200)
    return (speed(ans));
  return (0);
}

char	**init_direct()
{
  char	**tab;

  if ((tab = malloc(9 * sizeof(char *))) == NULL)
     return (NULL);
  tab[0] = "0.005\n";
  tab[1] = "0.01\n";
  tab[2] = "0.1\n";
  tab[3] = "0.2\n";
  tab[4] = "0.3\n";
  tab[5] = "0.4\n";
  tab[6] = "0.6\n";
  tab[7] = "0.8\n";
  tab[8] = NULL;
  return (tab);
}

int	*init_mid_vals()
{
  int	*mid_vals;

  if ((mid_vals = malloc(8 * sizeof(int))) == NULL)
     return (NULL);
  mid_vals[0] = 2000;
  mid_vals[1] = 1500;
  mid_vals[2] = 1000;
  mid_vals[3] = 800;
  mid_vals[4] = 600;
  mid_vals[5] = 400;
  mid_vals[6] = 200;
  mid_vals[7] = -1;
  return (mid_vals);
}

int	move_wheels(char **ans)
{
  float	ray;
  float	middle;
  char	**tab;
  int	*mid_vals;
  int	i;

  i = 0;
  ray = my_getfloat(ans[3]) - my_getfloat(ans[34]);
  middle = my_getfloat(ans[18]);
  if (check_speed(middle, ans) == 1 ||
      (tab = init_direct()) == NULL || (mid_vals = init_mid_vals()) == NULL)
    return (1);
  while (mid_vals[i] >= 0)
    {
      if (middle >= mid_vals[i])
	{
	  free(mid_vals);
	  return (move_left_and_right(ray, tab[i]));
	}
      i++;
    }
  free(mid_vals);
  return (move_left_and_right(ray, tab[i]));
}
