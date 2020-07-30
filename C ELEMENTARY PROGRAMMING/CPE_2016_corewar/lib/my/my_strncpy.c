/*
** my_strncpy.c for  in /home/charliebegood/delivery/CPool_Day06
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Oct 10 08:26:38 2016 Charles AUBERT
** Last update Tue Nov  8 09:29:49 2016 Charles AUBERT
*/

#include "./my.h"

char	*my_strncpy(char *dest, char *str, int n)
{
  int	i;

  i = 0;
  while (i <= n - 1 && str[i] != '\0')
    {
      dest[i] = str[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}
