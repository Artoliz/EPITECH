/*
** remove.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/lib/my
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Mar 21 17:26:50 2017 Charles Aubert
** Last update Sat Mar 25 17:38:12 2017 Bastien LECUSSAN
*/

#include "my.h"

int	get_count_of_char(char *s, char *r)
{
  int	i;
  int	i2;
  int	count;

  i = 0;
  count = 0;
  while (s[i] != '\0')
    {
      i2 = 0;
      while (r[i2] != '\0' && s[i] != r[i2])
	i2 += 1;
      if (r[i2] == '\0')
	count += 1;
      i += 1;
    }
  return (count);
}

int	char_correspond(char *r, char c)
{
  int	i;

  i = 0;
  while (r[i] != '\0')
    {
      if (c == r[i])
	return (0);
      else
	i += 1;
    }
  return (1);
}

char	*remove_char(char *s, char *r, int flag)
{
  int	count;
  int	i;
  int	i2;
  char	*result;

  count = get_count_of_char(s, r);
  if ((result = malloc(sizeof(char) * count + 1)) == NULL)
    return (NULL);
  i = 0;
  i2 = 0;
  while (s[i] != '\0')
    {
      if (char_correspond(r, s[i]) == 1)
	{
	  result[i2] = s[i];
	  i2 += 1;
	}
      i += 1;
    }
  result[i2] = s[i];
  if (flag)
    free(s);
  return (result);
}
