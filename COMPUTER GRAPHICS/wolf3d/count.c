/*
** count.c for count in /home/descou_c/Graphic/wolf3d
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Dec 21 15:28:05 2016 Charles Descoust
** Last update Wed Dec 21 15:33:56 2016 Charles Descoust
*/

#include "inc/my.h"

int	count_lines(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

int	count_chars(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n')
    i = i + 1;
  return (i);
}
