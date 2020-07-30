/*
** get_next_line.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CPE_2016_getnextline
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Jan  6 13:31:47 2017 Charles AUBERT
** Last update Sat Mar 25 17:17:00 2017 Charles Aubert
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char            *my_strconcat(char *buff, char *str, int fd, int count)
{
  char          *save;

  if (str == NULL)
    {
      if (fd < 0)
        str = NULL;
      else
        {
          if ((str = malloc(sizeof(*str) * my_strlen(buff) + 1)) == NULL)
            return (NULL);
          while (buff[count] != '\0')
            str[count] = buff[count++];
          str[count] = '\0';
        }
    }
  else
    {
      if ((save = malloc(sizeof(*save) * my_strlen(str) + 1)) == NULL)
        return (NULL);
      while (str[count] != '\0')
        save[count] = str[count++];
      save[count] = '\0';
      str = my_concatenate(buff, save, str, 0);
    }
  return (str);
}

char    *my_concatenate(char *buff, char *save, char *str, int count)
{
  int   count2;

  count2 = 0;
  free(str);
  if ((str = malloc(sizeof(*str) * my_strlen(buff)
                    + my_strlen(save) + 1)) == NULL)
    return (NULL);
  while (save[count] != '\0')
    str[count] = save[count++];
  while (buff[count2] != '\0')
    str[count++] = buff[count2++];
  str[count] = '\0';
  free(save);
  return (str);
}

char    *my_full_line(char *str, char *buff, int count, int bytes)
{
  int   count2;

  count2 = 0;
  if ((buff = malloc(sizeof(*buff) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[count] != '\n' && str[count] != '\0')
    buff[count] = str[count++];
  buff[count] = '\0';
  if (str[count] != '\0')
    count = count + 1;
  while (str[count] != '\0')
    str[count2++] = str[count++];
  str[count2] = '\0';
  return (buff);
}

char	*free_end(char *str)
{
  if (str != NULL)
    free(str);
  return (NULL);
}
char            *get_next_line(const int fd)
{
  static char   *str = NULL;
  char          buff[READ_SIZE + 1];
  int           bytes;
  int           count;
  char          *save;

  count = 0;
  while ((bytes = read(fd, buff, READ_SIZE)) > 0)
    {
      buff[bytes] = '\0';
      if ((str = my_strconcat(buff, str, fd, 0)) == NULL)
        return (NULL);
      while (str[count] != '\0')
        {
          if (str[count] == '\n')
            return (my_full_line(str, buff, 0, 0));
          count = count + 1;
        }
    }
  if ((bytes == -1 || str == NULL || (bytes == 0 && str[0] == '\0')))
    return (free_end(str));
  if (str != NULL)
    return (my_full_line(str, buff, 0, 1));
}
