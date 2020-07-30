/*
** my_strlowcase.c for  in /home/charliebegood/delivery/CPool_Day06
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Oct 10 13:17:37 2016 Charles AUBERT
** Last update Wed Jan  4 08:58:57 2017 Charles AUBERT
*/

#include "./my.h"

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (64 < str[i] && str[i] < 91)
	  str[i] += 32;
      i += 1;
    }
  return (str);
}
