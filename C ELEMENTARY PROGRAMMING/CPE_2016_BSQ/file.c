/*
** file.c for file in /home/descou_c/CPE/CPE_2016_BSQ
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec  6 09:05:23 2016 Charles Descoust
** Last update Wed Dec 14 08:44:06 2016 Charles Descoust
*/

#include "include/bsq.h"

int	len_first_line(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '\n' && buff[i] != '\0')
    i = i + 1;
  return (i + 1);
}

char	**str_to_tab(char *buff, int lines, int chars)
{
  int	i;
  int	j;
  int	k;
  char	**map;

  j = 0;
  k = len_first_line(buff);
  map = malloc(sizeof(char*) * lines + 1);
  while (j != lines)
    {
      i = 0;
      map[j] = malloc(sizeof(char) * chars + 1);
      while (i != chars)
	{
	  map[j][i] = buff[k];
	  k = k + 1;
	  i = i + 1;
	}
      map[j][i] = '\0';
      k = k + 1;
      j = j + 1;
    }
  map[j] = NULL;
  return (map);
}

int	count_lines(char *buff)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  j = 0;
  tmp = malloc(sizeof(char) * 10 + 1);
  while (buff[i] != '\0')
    {
      if (buff[i] >= 48 && buff[i] <= 57)
	{
	  while (buff[i] >= 48 && buff[i] <= 57)
	    {
	      tmp[j] = buff[i];
	      j = j + 1;
	      i = i + 1;
	    }
	  tmp[j] = '\0';
	  return (my_getnbr(tmp));
	}
      i = i + 1;
    }
  return (-1);
}

int	count_chars(char *buff)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (buff[i] != '\n' && buff[i] != '\0')
    i = i + 1;
  i = i + 1;
  while (buff[i] != '\n' && buff[i] != '\0')
    {
      count = count + 1;
      i = i + 1;
    }
  return (count);
}

char	**open_read_file(char *pathname)
{
  int		fd;
  char		*buff;
  char		**map;
  struct stat	st;

  if ((fd = open(pathname, O_RDONLY)) == -1)
    return (NULL);
  stat(pathname, &st);
  buff = malloc(sizeof(char) * st.st_size);
  if (read(fd, buff, st.st_size) == -1)
    return (NULL);
  map = str_to_tab(buff, count_lines(buff), count_chars(buff));
  free(buff);
  return (map);
}
