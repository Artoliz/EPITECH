/*
** my_str2.c for my_str in /home/descou_c/CPE/matchstick
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Feb 11 16:16:43 2017 Charles Descoust
** Last update Wed Feb 15 09:04:34 2017 Charles Descoust
*/

#include "inc/my.h"

int	my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (my_strlen(s1) == my_strlen(s2))
    {
      while (s1[i] != '\0')
        {
          if (s1[i] > s2[i])
            return (1);
          else if (s1[i] < s2[i])
            return (-1);
          i = i + 1;
        }
      return (0);
    }
  else if (my_strlen(s1) > my_strlen(s2))
    return (1);
  else
    return (-1);
}
