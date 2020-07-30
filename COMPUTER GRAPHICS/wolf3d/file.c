/*
** file.c for file in /home/descou_c/Graphic/wolf3d
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Dec 21 15:08:05 2016 Charles Descoust
** Last update Thu Jan 12 09:47:09 2017 Charles Descoust
*/

#include "inc/my.h"

t_map	add_info(int **map, int lines, int chars)
{
  t_map	info;

  info.map = map;
  info.lines = lines;
  info.chars = chars;
  return (info);
}

int	**my_map(char *buff, int lines, int chars)
{
  int	**map;
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  map = malloc(sizeof(int*) * lines);
  while (buff[i] != '\0')
    {
      map[k] = malloc(sizeof(int) * chars);
      j = 0;
      while (buff[i] != '\n')
	{
	  map[k][j] = buff[i] - 48;
	  j = j + 1;
	  i = i + 1;
	}
      k = k + 1;
      i = i + 1;
    }
  free(buff);
  return (map);
}

t_map	create_map(char *pathname)
{
  t_map	info;
  int	**map;
  int	nb_lines;
  int	nb_chars;
  int	fd;
  char	*buff;

  fd = open(pathname, O_RDONLY);
  buff = malloc(sizeof(char) * READ_SIZE);
  read(fd, buff, READ_SIZE);
  nb_lines = count_lines(buff);
  nb_chars = count_chars(buff);
  map = my_map(buff, nb_lines, nb_chars);
  info = add_info(map, nb_lines, nb_chars);
  return (info);
}
