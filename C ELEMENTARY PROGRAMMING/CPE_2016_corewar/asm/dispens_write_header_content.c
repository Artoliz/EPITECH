/*
** dispens_write_header_conten.c for  in /home/miklox/semestre2/c_prog_elem/write/asm/write_cor
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Fri Mar 24 13:24:21 2017 Bastien LECUSSAN
** Last update Thu Mar 30 15:24:54 2017 Charles Aubert
*/

#include "./include/asm.h"
#include "./include/my.h"

int		write_in_cor(t_line *list, int fd)
{
  if ((list = write_header(list, fd)) == NULL)
    return (84);
  if (write_instructions(list, fd) == 84)
    return (84);
  return (0);
}

t_line		*write_header(t_line *list, int fd)
{
  unsigned int	magic;
  int		length;
  char		*s;
  t_line	*tmp;

  magic = COREWAR_EXEC_MAGIC;
  if (write(fd, &magic, sizeof(int)) == -1)
    return (NULL);
  tmp = list;
  while (tmp->type != MY_NAME && tmp != NULL)
    tmp = tmp->next;
  length = PROG_NAME_LENGTH + 1;
  while (length % 4 != 0)
    length += 1;
  if ((s = malloc(sizeof(char) * length)) == NULL)
    return (NULL);
  if (tmp == NULL || (tmp = write_header_name(tmp, fd,
					      length, s)) == NULL)
    return (NULL);
  return (list);
}

t_line	*write_header_name(t_line *list, int fd,
			   int length, char *s)
{
  int	count;
  char	**my_line;

  if ((my_line = my_str_to_wordtab(list->line, "\"")) == NULL)
    return (return_NULL_free_str(s));
  count = 0;
  while (count < length)
    {
      if (count < my_strlen(my_line[1]))
	s[count] = my_line[1][count];
      else
	s[count] = 0;
      count += 1;
    }
  if (write(fd, s, length) == -1)
    {
      free_array_char(my_line, 0);
      return (return_NULL_free_str(s));
    }
  free(s);
  free_array_char(my_line, 0);
  if (write_header_comment(list, fd) == NULL)
    return (NULL);
  return (list);
}

t_line		*write_header_comment(t_line *list, int fd)
{
  int		length;
  char		**my_line;
  t_line	*save;

  save = list;
  while (list->prev != NULL)
    list = list->prev;
  while (list->type != MY_COMMENT && list != NULL)
    list = list->next;
  if (list == NULL || (my_line = my_str_to_wordtab(list->line, "\"")) == NULL)
    return (NULL);
  length = COMMENT_LENGTH + 1;
  while (length % 4 != 0)
    length += 1;
  if (set_pos(save, fd, 0) == 84)
    return (NULL);
  if (write_end_header_comment(my_line, length, fd) == 84)
    return (NULL);
  while (list->prev != NULL)
    list = list->prev;
  return (list);
}

int	write_end_header_comment(char **my_line,
				 int length, int fd)
{
  int	count;
  char	*s;

  count = 0;
  if ((s = malloc(sizeof(char) * length)) == NULL)
    return (free_array_char(my_line, 84));
  while (count < length)
    {
      if (count < my_strlen(my_line[1]))
	s[count] = my_line[1][count];
      else
	s[count] = 0;
      count += 1;
    }
  if (write(fd, s, length) == -1)
    return (free_array_char(my_line, free_str(s, 84)));
  free(s);
  return (free_array_char(my_line, 0));
}
