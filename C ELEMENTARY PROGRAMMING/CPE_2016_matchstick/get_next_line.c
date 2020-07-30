/*
** get_next_line.c for get_next_line in /home/descou_c/CPE/CPE_2016_matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Feb 17 08:48:33 2017 Charles Descoust
** Last update Wed Feb 22 14:41:42 2017 Charles Descoust
*/

#include "inc/my.h"

int	mi_strlen(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    count++;
  return (count);
}

char	*mi_strcpy(char *dest, char *src)
{
  int   count;

  count = 0;
  while (src[count] != '\0')
    {
      dest[count] = src[count];
      count++;
    }
  dest[count] = '\0';
  return (dest);
}

char	*my_realloc(int toadd, char *str)
{
  char	*new;

  if (!(new = malloc(sizeof(char) * (mi_strlen(str) + toadd))))
    return (0);
  mi_strcpy(new, str);
  return (new);
}

int	aff_buffer(int *cstr, int *cbuf, char *buffer, char *str)
{
  int	eol;

  eol = 0;
  if (buffer[*cbuf] == '\n')
    eol = 1;
  else
    {
      str[*cstr] = buffer[*cbuf];
      *cstr = *cstr + 1;
    }
  *cbuf = *cbuf + 1;
  return (eol);
}

char	*get_next_line(const int fd)
{
  static int	rd = READ_SIZE;
  static char	*str;
  static char	buffer[READ_SIZE];
  static int	cbuf;
  int		cstr;
  int		eol;

  cstr = 0;
  eol = 0;
  if (!(str = malloc(sizeof(*str) * READ_SIZE)))
    return (0);
  while (!eol && rd)
    {
      if (cbuf == 0)
	if ((rd = read(fd, buffer, READ_SIZE)) == -1)
	  return (0);
      str = my_realloc(READ_SIZE, str);
      while (cbuf < rd && !eol)
	eol = aff_buffer(&cstr, &cbuf, buffer, str);
      if (cbuf == rd)
	cbuf = 0;
    }
  str[cstr] = '\0';
  if (rd)
    return (&str[0]);
  else return (0);
}
