/*
** my_strcmp.c for  in /home/charliebegood/delivery/CPool_evalexpr/lib/my
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Oct 28 14:48:13 2016 Charles AUBERT
** Last update Wed Apr 12 16:40:22 2017 Charles Aubert
*/

#include "./my.h"

int     my_ascii_sort(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] == s2[i])
	i += 1;
      else if (s1[i] < s2[i])
	return (-1);
      else
	return (1);
    }
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  else if (my_strlen(s1) == my_strlen(s2))
    return (0);
  else
    return (-1);
}

int	my_contain(char *s1, char *s2)
{
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != '\0' && s2[i2] != '\0')
    {
      if (s1[i] == s2[i2])
	i2 += 1;
      else
	i2 = 0;
      i += 1;
    }
  if (s2[i2] == '\0')
    return (0);
  else
    return (1);
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  if (my_strlen(s1) == my_strlen(s2))
    {
      while (s1[i] != '\0')
	{
	  if (s1[i] == s2[i])
	    i += 1;
	  else if (s1[i] < s2[i])
	    return (-1);
	  else
	    return (1);
	}
      return (0);
    }
  else if (my_strlen(s1) > my_strlen(s2))
    return (1);
  else
    return (-1);
}

int     my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
    {
      if (s1[i] == s2[i])
        i += 1;
      else if (s1[i] < s2[i])
        return (-1);
      else
        return (1);
    }
  return (0);
}

int	occurence(char *s1, char *s2, int i)
{
  int	i2;

  if (s1 == NULL || s2 == NULL || i < 0)
    return (1);
  while (s1[i] != '\0')
    {
      i2 = 0;
      while (s2[i2] != s1[i] && s2[i2] != '\0')
	{
	  i2 += 1;
	  i += 1;
	}
      if (s2[i2] == '\0')
	return (0);
      i += 1;
    }
  return (1);
}
