/*
** my_strcpy.c for  in /home/charliebegood/delivery/CPool_Day06
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Oct 10 07:54:57 2016 Charles AUBERT
** Last update Tue Apr  4 15:51:53 2017 Charles Aubert
*/

#include "my.h"

char	*my_strcpy(char *dest, char *str, int i2)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      dest[i2] = str[i];
      i += 1;
      i2 += 1;
    }
  dest[i2] = '\0';
  return (dest);
}

char    *my_revstr(char *str)
{
  int   i;
  int   i2;
  char  holder;

  i = 0;
  i2 = my_strlen(str) - 1;
  while (i2 > i)
    {
      holder = str[i];
      str[i] = str[i2];
      str[i2] = holder;
      i2 -= 1;
      i += 1;
    }
  return (str);
}

char    *my_strcat(char *dest, char *str)
{
  int   i;
  int   l;

  l = 0;
  i = 0;
  while (dest[l] != '\0')
    l += 1;
  while (str[i] != '\0')
    {
      dest[l] = str[i];
      l += 1;
      i += 1;
    }
  return (dest);
}

char    *join_str_str(char *from, char *add)
{
  int   len;
  char  *res;

  if (add == NULL)
    return (from);
  len = my_strlen(add);
  if (from != NULL)
    len = my_strlen(from) + my_strlen(add);
  if ((res = malloc(sizeof(char) * len + 1)) == NULL)
    return (NULL);
  if (from != NULL)
    res = my_strcpy(res, from, 0);
  res = my_strcpy(res, add, my_strlen(from));
  res[len] = '\0';
  if (from != NULL)
    free(from);
  return (res);
}

char    *join_str_char(char *from, char add)
{
  int   len;
  char  *res;

  len = my_strlen(from) + 1;
  if ((res = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  if (from != NULL)
    res = my_strcpy(res, from, 0);
  res[my_strlen(from)] = add;
  res[my_strlen(from) + 1] = '\0';
  if (from != NULL)
    free(from);
  return (res);
}
