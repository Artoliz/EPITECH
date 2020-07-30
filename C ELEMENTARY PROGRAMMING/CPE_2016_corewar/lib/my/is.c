/*
** is.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/CPE_2016_corewar/lib/my
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Mar  3 18:50:33 2017 Charles Aubert
** Last update Fri Mar  3 18:53:36 2017 Charles Aubert
*/

#include "my.h"

int     my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 96 && str[i] < 123)
        i += 1;
      else
        return (1);
    }
  return (0);
}

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 47 && str[i] < 58 || str[i] == 45)
        i += 1;
      else
        return (1);
    }
  return (0);
}

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
        i += 1;
      else
        return (1);
    }
  return (0);
}

int     my_str_isalpha(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 96 && str[i] < 123)
        i += 1;
      else if (str[i] > 64 && str[i] < 91)
        i += 1;
      else
        return (1);
    }
  return (0);
}
