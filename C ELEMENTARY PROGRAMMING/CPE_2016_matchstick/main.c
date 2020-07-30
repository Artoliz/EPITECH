/*
** main.c for main in /home/descou_c/CPE/matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Feb 11 11:22:24 2017 Charles Descoust
** Last update Wed Feb 22 10:28:57 2017 Charles Descoust
*/

#include "inc/my.h"

int	my_putstr_err(char *str)
{
  write(2, str, my_strlen(str));
  return (84);
}

int	transit_main(int nb_lines, int max_match)
{
  char	**map;
  int	kill;

  if ((map = create_map(nb_lines)) == NULL)
    return (84);
  aff_map(map, nb_lines);
  my_putstr("\n");
  if ((kill = game(map, nb_lines, max_match)) == 84)
    return (84);
  return (kill);
}

int	main(int ac, char **av)
{
  int	kill;
  int	max_match;
  int	nb_lines;

  if (ac == 1 || ac > 3)
    return (my_putstr_err("Use : ./matchstick 'n'\n'n' : number of lines\n"));
  if (my_strisnum(av[1]) == 84)
    return (my_putstr_err("Parameters must be an integer\n"));
    nb_lines = my_getnbr(av[1]);
  if (nb_lines < 1 || nb_lines > 100)
    return (my_putstr_err("Number of lines must be between 1 and 100\n"));
  if (ac == 3)
    {
      if (my_strisnum(av[2]) == 84)
	return (my_putstr_err("Parameters must be an integer\n"));
      max_match = my_getnbr(av[2]);
      if (max_match < 1)
	return (my_putstr_err("Number max of matchs (can be taken) must be > 0\n"));
    }
  else
    max_match = 1000000;
  if ((kill = transit_main(nb_lines, max_match)) == 84)
    return (84);
  return (kill);
}
