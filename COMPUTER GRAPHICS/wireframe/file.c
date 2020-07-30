/*
** file.c for file in /home/descou_c/Graphic/wireframe
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Dec  5 10:54:30 2016 Charles Descoust
** Last update Sun Dec 11 15:25:12 2016 Charles Descoust
*/

#include "include/wire.h"

int	count_chars_per_line(char *str)
{
  int   i;
  int   nb;
  int   fd;
  char  *buff;

  if ((fd = open(str, O_RDONLY)) == -1)
    return (84);
  buff = malloc(sizeof(char) * READ_SIZE);
  if (read(fd, buff, READ_SIZE) == -1)
    return (84);
  i = 0;
  nb = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] >= 48 && buff[i] <= 57)
	nb = nb + 1;
      i = i + 1;
    }
  close(fd);
  free(buff);
  return (nb);
}

int	count_lines(char *str)
{
  int   i;
  int   nb;
  int   fd;
  char  *buff;

  if ((fd = open(str, O_RDONLY)) == -1)
    return (84);
  buff = malloc(sizeof(char) * READ_SIZE);
  if (read(fd, buff, READ_SIZE) == -1)
    return (84);
  i = 0;
  nb = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] == '\n')
	nb = nb + 1;
      i = i + 1;
    }
  close(fd);
  free(buff);
  return (nb);
}

int	**add_to_line(char *buff, int **tab, int i, int j)
{
  int	k;

  k = 0;
  while (buff[i] != '\n' && buff[i] != '\0')
    {
      if (buff[i] >= 48 && buff[i] <= 57)
	{
	  tab[j][k] = (buff[i] - 48);
	  k = k + 1;
	}
      i = i + 1;
    }
  return (tab);
}

int	**add_to_tab(char *str, int **tab, int nb_chars)
{
  int   i;
  int   j;
  int   fd;
  char  *buff;

  fd = open(str, O_RDONLY);
  buff = malloc(sizeof(char) * READ_SIZE);
  read(fd, buff, READ_SIZE);
  i = 0;
  j = 0;
  while (buff[i] != '\0')
    {
      tab[j] = malloc(sizeof(int) * nb_chars);
      tab = add_to_line(buff, tab, i, j);
      j = j + 1;
      i = i + 1 + nb_chars * 2;
    }
  close(fd);
  free(buff);
  return (tab);
}

t_tab	check_name_file(char *str)
{
  t_tab	s;
  int   **tab;
  int	nb_chars;
  int	nb_lines;

  nb_lines = count_lines(str);
  nb_chars = count_chars_per_line(str) / nb_lines;
  tab = malloc(sizeof(int*) * nb_lines);
  tab = add_to_tab(str, tab, nb_chars);
  s.tab = tab;
  s.lines = nb_lines;
  s.chars = nb_chars;
  return (s);
}
