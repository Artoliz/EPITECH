/*
** my_strdup.c for  in /home/charliebegood/delivery/CPool_Day08/task01
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Wed Oct 12 08:06:16 2016 Charles AUBERT
** Last update Wed Jan 18 09:13:02 2017 Charles Aubert
*/

#include <stdlib.h>
#include "./my.h"

char	*my_strdup(char *src)
{
  char	*str;
  int	i;
  int	len;

  i = 0;
  len = 0;
  while (src[len] != '\0')
    len += 1;
  str = malloc(sizeof(char) * len + 1);
  if (str == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i += 1;
    }
  str[i] = '\0';
  return (str);
}
