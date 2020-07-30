/*
** my_str.c for my_str in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Feb  9 10:36:41 2017 Charles Descoust
** Last update Tue Mar  7 15:08:37 2017 Charles Descoust
*/

#include "inc/my.h"

char	*my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}

int	my_strlen(char* str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      else if (s1[i] < s2[i])
	return (-1);
      i = i + 1;
    }
  return (0);
}

int	my_strisfloat(char* str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.' ||
	  str[i] == '-')
	i = i + 1;
      else
	return (84);
    }
  return (0);
}

int	my_while_error_file(char** c, int *i)
{
  int           j;

  j = *i;
  while (j < (*i + 4))
    {
      if (my_strisfloat(c[j]) == 84)
	return (84);
      j = j + 1;
    }
  return (0);
}
