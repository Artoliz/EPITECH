/*
** live_fork.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Mar 23 21:15:57 2017 Charles Aubert
** Last update Sun Apr  2 15:43:24 2017 Charles Descoust
*/

#include "../include/asm.h"

int	check_end(char **array, int i)
{
  int	i2;

  i2 = 0;
  if (array[i] == NULL)
    return (0);
  while (array[i][i2] != '\0' && (array[i][i2] == ' ' || array[i][i2] == '\t'))
    i2 += 1;
  if (array[i][i2] == COMMENT_CHAR)
    return (0);
  else
    return (1);
}

int	check_line_live(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t")) == NULL ||
      size_array_char(array) < 2 || count_args(line) != 0)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "live") == 0 && array[1][0] == DIRECT_CHAR)
    if (check_args(1, 0, 0, array[1]) == 0 && check_end(array, 2) == 0)
      return (free_array_char(array, MY_LIVE));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 2 &&
	   my_strcmp(array[1], "live") == 0 && array[2][0] == DIRECT_CHAR &&
           array[0][my_strlen(array[0]) - 1] == LABEL_CHAR)
    if (check_args(1, 0, 0, array[2]) == 0 && check_end(array, 3) == 0)
      return (free_array_char(array, MY_LIVE));
    else
      return (free_array_char(array, MY_INVALID));
  return (free_array_char(array, MY_IGNORE));
}

int	check_line_fork(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t")) == NULL ||
      size_array_char(array) < 2 || count_args(line) != 0)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "fork") == 0 && array[1][0] == DIRECT_CHAR)
    if (check_args(1, 0, 0, array[1]) == 0 && check_end(array, 2) == 0)
      return (free_array_char(array, MY_FORK));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 2 &&
	   my_strcmp(array[1], "fork") == 0 && array[2][0] == DIRECT_CHAR &&
           array[0][my_strlen(array[0]) - 1] == LABEL_CHAR)
    if (check_args(1, 0, 0, array[2]) == 0 && check_end(array, 3) == 0)
      return (free_array_char(array, MY_FORK));
    else
      return (free_array_char(array, MY_INVALID));
  return (free_array_char(array, MY_IGNORE));
}

int	check_line_lfork(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t")) == NULL ||
      size_array_char(array) < 2 || count_args(line) != 0)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "lfork") == 0 && array[1][0] == DIRECT_CHAR)
    if (check_args(1, 0, 0, array[1]) == 0 && check_end(array, 2) == 0)
      return (free_array_char(array, MY_LFORK));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 2 && my_strcmp(array[1], "lfork") == 0
	   && array[2][0] == DIRECT_CHAR &&
           array[0][my_strlen(array[0]) - 1] == LABEL_CHAR)
    if (check_args(1, 0, 0, array[2]) == 0 && check_end(array, 3) == 0)
      return (free_array_char(array, MY_LFORK));
    else
      return (free_array_char(array, MY_INVALID));
  return (free_array_char(array, MY_IGNORE));
}

int	check_line_sti(char *line)
{
  char	**array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 4 || count_args(line) != 2)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "sti") == 0)
    if (check_args(0, 0, 1, array[1]) == 0 && check_args(1, 1, 1, array[2])
	== 0 && check_args(1, 0, 1, array[3]) == 0
	&& check_end(array, 4) == 0)
      return (free_array_char(array, MY_STI));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 4 && my_strcmp(array[1], "sti") == 0)
    if (check_args(0, 0, 1, array[2]) == 0 && check_args(1, 1, 1, array[3])
	== 0 && check_args(1, 0, 1, array[4]) == 0
	&& check_end(array, 5) == 0)
      return (free_array_char(array, MY_STI));
    else
      return (free_array_char(array, MY_INVALID));
  return (free_array_char(array, MY_IGNORE));
}
