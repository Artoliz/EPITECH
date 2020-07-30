/*
** my_strncat.c for  in /home/charliebegood/delivery/CPool_Day07
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Oct 11 09:04:55 2016 Charles AUBERT
** Last update Tue Nov  8 09:24:25 2016 Charles AUBERT
*/

#include "./my.h"

char	*my_strncat(char *dest, char *str, int nb)
{
  int	i;
  int	l;

  i = 0;
  l = 0;
  while (dest[l] != '\0')
    l += 1;
  while (str[i] != '\0' && i < nb)
    {
      dest[l] = str[i];
      i += 1;
      l += 1;
    }
  return (dest);
}
