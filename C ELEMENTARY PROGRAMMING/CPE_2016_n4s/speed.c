/*
** speed.c for speed in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed May 31 09:32:55 2017 Charles Descoust
** Last update Sun Jun  4 14:40:33 2017 Bryan Medica
*/

#include "inc/n4s.h"

int	check_wheels(char **ans)
{
  float	ray1;
  float	ray32;

  ray1 = my_getfloat(ans[3]);
  ray32 = my_getfloat(ans[34]);
  if (ray1 <= 20 && ray32 >= 500)
    return (move_wheels(ans));
  else if (ray1 >= 500 && ray32 <= 20)
    return (move_wheels(ans));
  return (0);
}

char	**init_carforward()
{
  char	**tab;

  if ((tab = malloc(9 * sizeof(char *))) == NULL)
    return (NULL);
  tab[0] = "CAR_FORWARD:0.9\n";
  tab[1] = "CAR_FORWARD:0.67\n";
  tab[2] = "CAR_FORWARD:0.4\n";
  tab[3] = "CAR_FORWARD:0.3\n";
  tab[4] = "CAR_FORWARD:0.2\n";
  tab[5] = "CAR_FORWARD:0.1\n";
  tab[6] = "CAR_FORWARD:0.05\n";
  tab[7] = "CAR_FORWARD:0.01\n";
  tab[8] = NULL;
  return (tab);
}

int	speed(char **ans)
{
  float	middle;
  char	**tab;
  int	*mid_vals;
  int	i;
  char	*tmp;

  i = -1;
  if (check_wheels(ans) == 1 || (tab = init_carforward()) == NULL
      || (mid_vals = init_mid_vals()) == NULL)
    return (1);
  middle = my_getfloat(ans[18]);
  while (mid_vals[++i] >= 0)
    if (middle >= mid_vals[i])
      {
	free(mid_vals);
	tmp = tab[i];
	free(tab);
	return (write_command(tmp));
      }
  free(mid_vals);
  tmp = tab[i];
  free(tab);
  return (write_command(tmp));
}
