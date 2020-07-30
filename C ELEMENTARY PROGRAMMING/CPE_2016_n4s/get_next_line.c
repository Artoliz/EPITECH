/*
** get_next_line.c for get_next_line in /home/Medica31/CPE/CPE_2016_getnextline
** 
** Made by Bryan Medica
** Login   <Medica31@epitech.net>
** 
** Started on  Mon Jan  2 15:55:24 2017 Bryan Medica
** Last update Tue May  2 15:02:11 2017 Charles Descoust
*/

#include "inc/n4s.h"

char		*my_strcat2(char *str2, char *str, int i)
{
  char		*res;
  int		cursor;
  int		len;

  len = -1;
  cursor = 0;
  while (str[++len] != '\0');
  while (str2[++i] != '\0');
  len += i;
  if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  res[len] = 0;
  while (str2[cursor] != '\0')
    {
      res[cursor] = str2[cursor];
      cursor++;
    }
  i = 0;
  while (cursor != len)
    {
      res[cursor] = str[i];
      cursor++;
      i++;
    }
  return (res);
}

char	*my_strdiv(char **src)
{
  char	*dest;
  int  	cursor;
  int	j;

  cursor = 0;
  while ((*src)[cursor] != '\n' && (*src)[cursor] != '\0')
    cursor++;
  if ((*src)[cursor] == '\0')
    return (NULL);
  if ((dest = malloc(sizeof(char) * (cursor + 1))) == NULL)
    return (NULL);
  dest[cursor] = 0;
  j = cursor + 1;
  cursor--;
  while (cursor != -1)
    {
      dest[cursor] = (*src)[cursor];
      cursor--;
    }
  (*src) = &((*src)[j]);
  return (dest);
}

int	is_line(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NO_LINE);
  while (str[i] != '\n' && str[i] != '\0')
    i++;
  if (str[i] == '\n')
    return (0);
  return (NO_LINE);
}

char		*get_next_line(const int fd)
{
  char		buf[READ_SIZE + 1];
  static char	*tmp = "\0";
  char		*result;
  int		ret;
  int		i;

  i = -1;
  buf[0] = 0;
  while (is_line(tmp) == NO_LINE)
    {
      if ((ret = read(fd, buf, READ_SIZE)) == FAIL_READ)
	return (NULL);
      if (ret == 0)
	{
	  if (tmp[0] == '\0')
	    return (NULL);
	  result = tmp;
	  tmp = "\0";
	  return (result);
	}
      buf[ret] = 0;
      tmp = my_strcat2(tmp, buf, i);
    }
  result = my_strdiv(&tmp);
  return (result);
}
