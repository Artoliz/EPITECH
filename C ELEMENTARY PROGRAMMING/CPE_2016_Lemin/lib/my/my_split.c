/*
** my_str_to_wordtab.c for  in /home/charliebegood/delivery/CPool_Day08/task04
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Wed Oct 12 14:06:06 2016 Charles AUBERT
** Last update Mon Apr 10 17:03:50 2017 Charles Aubert
*/

#include <stdlib.h>
#include "./my.h"

int	is_alpha(char str, char *sep)
{
  int	i;

  i = 0;
  while (sep[i] != '\0')
    {
      if (str == sep[i])
	return (0);
      i += 1;
    }
  return (1);
}

int	nb_words(char *str, char *sep)
{
  int	i;
  int	counter;
  int   word;

  i = 0;
  word = 0;
  counter = 0;
  while (str[i] != '\0')
    {
      if (is_alpha(str[i], sep) == 1 && word == 0)
	{
	  word += 1;
	  counter += 1;
	}
      else if (is_alpha(str[i], sep) == 0)
	  word = 0;
      i += 1;
    }
  return (counter);
}

char	**init(int *i, int *i3, char *str, char *sep)
{
  char	**tab;

  if (nb_words(str, sep) == 0)
    return (NULL);
  tab = malloc(sizeof(char *) * (nb_words(str, sep) + 1));
  if (tab == NULL)
    return (NULL);
  *i = 0;
  *i3 = 0;
  return (tab);
}

int	word_length(char *str, int i, char *sep)
{
  int	i2;

  i2 = 0;
  while (is_alpha(str[i], sep) == 0 && str[i] != '\0')
    i += 1;
  while (str[i] != '\0')
    {
      if (is_alpha(str[i], sep) == 0)
	return (i2);
      i2 += 1;
      i += 1;
    }
  return (i2);
}

char	**my_split(char *str, char *sep)
{
  int	i;
  char	**tab;
  int	i2;
  int	i3;

  tab = init(&i, &i3, str, sep);
  while (tab != NULL && i < nb_words(str, sep))
    {
      i2 = 0;
      while (is_alpha(str[i3], sep) == 0)
	  i3 += 1;
      if ((tab[i] = malloc(sizeof(char) * (word_length(str, i3, sep) + 1)))
	  == NULL)
	return (NULL);
      while (str[i3] != '\0' && is_alpha(str[i3], sep) == 1 && tab[i] != NULL)
	{
	  tab[i][i2] = str[i3];
	  i2 += 1;
	  i3 += 1;
	}
      tab[i][i2] = '\0';
      i += 1;
      tab[i] = NULL;
    }
  return (tab);
}
