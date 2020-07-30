/*
** comment_ignore_zjmp.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Mar 23 21:16:18 2017 Charles Aubert
** Last update Tue Mar 28 15:40:52 2017 Charles Aubert
*/

#include "../include/asm.h"

int	check_extension(char *pathname)
{
  int	i;

  i = my_strlen(pathname) - 1;
  if (pathname[i] != 's' || pathname[i - 1] != '.')
    return (0);
  else
    return (open(pathname, O_RDONLY));
}

int	check_line_comment(char *line)
{
  char	**array;
  char	**begin;
  char	**between;
  int	size;

  if ((array = my_str_to_wordtab(line, "\"")) == NULL ||
      (begin = my_str_to_wordtab(array[0], " \t")) == NULL)
    return (MY_IGNORE);
  if ((size = size_array_char(array)) < 2 ||
      (size_array_char(begin) != 1))
    return (free_array_char(array, free_array_char(begin, MY_IGNORE)));
  if ((my_strcmp(begin[0], NAME_CMD_STRING) == 0 &&
       my_strlen(array[1]) < PROG_NAME_LENGTH && check_end(array, 2) == 0))
    return (free_array_char(array, free_array_char(begin, MY_NAME)));
  else if (my_strcmp(begin[0], COMMENT_CMD_STRING) == 0 &&
	   my_strlen(array[1]) < COMMENT_LENGTH &&
	   check_end(array, 2) == 0)
    return (free_array_char(array, free_array_char(begin, MY_COMMENT)));
  return (free_array_char(array, free_array_char(begin, MY_IGNORE)));
}

int	check_line_ignore(char *line)
{
  int	i;

  if (line[0] == COMMENT_CHAR)
    return (MY_IGNORE);
  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
	return (MY_INVALID);
      i += 1;
    }
  return (MY_IGNORE);
}

int	check_line_zjmp(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t")) == NULL ||
      size_array_char(array) < 2 || count_args(line) != 0)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "zjmp") == 0 && array[1][0] == DIRECT_CHAR)
    if (check_args(1, 0, 0, array[1]) == 0 && check_end(array, 2) == 0)
      return (free_array_char(array, MY_ZJMP));
    else
      return (free_array_char(array, MY_INVALID));
  else if (my_strcmp(array[1], "zjmp") == 0 && array[2][0] == DIRECT_CHAR &&
	   array[0][my_strlen(array[0]) - 1] == LABEL_CHAR)
    if (check_args(1, 0, 0, array[2]) == 0 && check_end(array, 3) == 0)
      return (free_array_char(array, MY_ZJMP));
    else
      return (free_array_char(array, MY_INVALID));
  return (free_array_char(array, MY_IGNORE));
}

int	check_line(char *line, check *tab)
{
  int	result;
  check function;
  int	i;

  i = 0;
  result = 0;
  while (tab[i] != NULL)
    {
      function = tab[i];
      if ((result = function(line)) != MY_IGNORE)
	return (result);
      i += 1;
    }
  if (result == MY_IGNORE)
    free(line);
  return (result);
}
