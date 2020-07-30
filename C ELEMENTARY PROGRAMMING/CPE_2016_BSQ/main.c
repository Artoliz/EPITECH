/*
** main.c for main in /home/descou_c/CPE/CPE_2016_BSQ
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec  6 09:02:53 2016 Charles Descoust
** Last update Sun Dec 18 22:20:33 2016 Charles Descoust
*/

#include "include/bsq.h"

t_map		add_map_info(char *path, char **map)
{
  t_map		info;
  int		fd;
  char		*buff;
  struct stat	st;

  fd = open(path, O_RDONLY);
  stat(path, &st);
  buff = malloc(sizeof(char) * st.st_size);
  read(fd, buff, st.st_size);
  info.map = map;
  info.lines = count_lines(buff);
  info.chars = count_chars(buff);
  free(buff);
  return (info);
}

t_idx	create_idx()
{
  t_idx	idx;

  idx.i = 0;
  idx.j = 0;
  idx.k = 0;
  idx.l = 0;
  return (idx);
}

int	destroy(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      free(map[i]);
      i = i + 1;
    }
  free(map);
  return (0);
}

int		main(int ac, char **av)
{
  char		**map;
  t_square	*square;
  t_map		info;
  t_idx		idx;

  if (ac != 2)
    return (84);
  if ((map = open_read_file(av[1])) == NULL)
    return (84);
  square = create_struct();
  idx = create_idx();
  info = add_map_info(av[1], map);
  square = search_square(square, info, idx);
  aff_tab(map, info.lines, info.chars, square);
  destroy(map);
  return (0);
}
