/*
** usefull_fonctions.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Mon Mar 27 12:06:44 2017 Bastien LECUSSAN
** Last update Sun Apr  2 15:41:23 2017 Charles Descoust
*/

#include "./include/asm.h"
#include "./include/my.h"

int	is_there_a_label(t_line *list, int cnt)
{
  int	count;

  count = 0;
  if (list->label == NULL)
    return (84);
  while (list->label[count] != NULL)
    {
      if (list->label[count]->type == 1
	  && my_strcmp_in(list->my_tab[cnt], list->label[count]->label) == 0)
	return (0);
      count += 1;
    }
  return (84);
}

int	my_strcmp_in(char *s1, char *s2)
{
  int	count;
  int	cnt;

  count = 0;
  while (s1[count] != '\0')
    {
      cnt = 0;
      while (s1[count] == s2[cnt] && s1[count] != '\0' && s2[cnt] != '\0')
	{
	  count += 1;
	  cnt += 1;
	}
      if (s2[cnt] == '\0')
	return (0);
      count += 1;
    }
  return (84);
}

int	get_big_endian(int position, int size)
{
  if (size == 4)
    position = ((position & 0x000000FF) << (3 * 8)
		| (position & 0x0000FF00) << 8
		| (position & 0x00FF0000) >> 8
		| (position & 0xFF000000) >> (3 * 8));
  else if (size == 2)
    position = ((position & 0x000000FF) << 8
		| (position & 0x0000FF00) >> 8);
  else if (size == 4)
    position = ((position & 0x000000FF) << (2 * 8)
		| (position & 0x00FF0000) >> (2 * 8));
  return (position);
}

char	*set_type_line_by_default(t_line *list)
{
  char  *s;
  int   count;
  int	cnt;

  cnt = 0;
  count = 0;
  if ((s = malloc(sizeof(*s) * 4)) == NULL)
    return (NULL);
  while (count < 3)
    {
      s[count] = '0';
      count += 1;
    }
  s[count] = '\0';
  count = 1;
  if (list->label != NULL)
    if (list->label[0]->type == 0)
      count += 1;
  while (list->my_tab[count] != NULL && cnt != 3)
    {
      s[cnt] = get_type_of_arg(list->my_tab[count]);
      count += 1;
      cnt += 1;
    }
  return (s);
}

char	get_type_of_arg(char *str)
{
  char	c;

  c = '0';
  if (check_args(1, 0, 0, str) == 0)
    c = '4';
  else if (check_args(0, 1, 0, str) == 0)
    c = '2';
  else if (check_args(0, 0, 1, str) == 0)
    c = '1';
  return (c);
}
