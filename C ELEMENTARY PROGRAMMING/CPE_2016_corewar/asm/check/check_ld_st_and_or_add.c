/*
** check_ld_st_and_or_add.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Mar 23 22:03:52 2017 Charles Aubert
** Last update Sun Apr  2 15:44:35 2017 Charles Descoust
*/

#include "../include/asm.h"

int	check_line_ld(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 3 || count_args(line) != 1)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "ld") == 0)
    if (check_args(1, 1, 0, array[1]) == 0 &&
	check_args(0, 0, 1, array[2]) == 0 && check_end(array, 3) == 0)
      return (free_array_char(array, MY_LD));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 3 && my_strcmp(array[1], "ld") == 0)
    if (check_args(1, 1, 0, array[2]) == 0 &&
	check_args(0, 0, 1, array[3]) == 0 && check_end(array, 4) == 0)
      return (free_array_char(array, MY_LD));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}

int	check_line_st(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 3 || count_args(line) != 1)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "st") == 0)
    if (check_args(0, 0, 1, array[1]) == 0 &&
        check_args(0, 1, 1, array[2]) == 0 && check_end(array, 3) == 0)
      return (free_array_char(array, MY_ST));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 3 && my_strcmp(array[1], "st") == 0)
    if (check_args(0, 0, 1, array[2]) == 0 &&
        check_args(0, 1, 1, array[3]) == 0 && check_end(array, 4) == 0)
      return (free_array_char(array, MY_ST));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}

int	check_line_add(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 4 || count_args(line) != 2)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "add") == 0)
    if (check_args(0, 0, 1, array[1]) == 0 &&
        check_args(0, 0, 1, array[2]) == 0 &&
	check_args(0, 0, 1, array[3]) == 0 && check_end(array, 4) == 0)
      return (free_array_char(array, MY_ADD));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 4 && my_strcmp(array[1], "add") == 0)
    if (check_args(0, 0, 1, array[2]) == 0 &&
        check_args(0, 0, 1, array[3]) == 0 &&
	check_args(0, 0, 1, array[4]) == 0 && check_end(array, 5) == 0)
      return (free_array_char(array, MY_ADD));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}

int	check_line_and(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 4 || count_args(line) != 2)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "and") == 0)
    if (check_args(1, 1, 1, array[1]) == 0 &&
        check_args(1, 1, 1, array[2]) == 0 &&
	check_args(0, 0, 1, array[3]) == 0 &&
	check_end(array, 4) == 0)
      return (free_array_char(array, MY_AND));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 4 && my_strcmp(array[1], "and") == 0)
    if (check_args(1, 1, 1, array[2]) == 0 &&
        check_args(1, 1, 1, array[3]) == 0 &&
	check_args(0, 0, 1, array[4]) == 0 &&
	check_end(array, 5) == 0)
      return (free_array_char(array, MY_AND));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}

int	check_line_or(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 4 || count_args(line) != 2)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "or") == 0)
    if (check_args(1, 1, 1, array[1]) == 0 &&
        check_args(1, 1, 1, array[2]) == 0 &&
	check_args(0, 0, 1, array[3]) == 0 &&
	check_end(array, 4) == 0)
      return (free_array_char(array, MY_OR));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 4 && my_strcmp(array[1], "or") == 0)
    if (check_args(1, 1, 1, array[2]) == 0 &&
        check_args(1, 1, 1, array[3]) == 0 &&
	check_args(0, 0, 1, array[4]) == 0 &&
	check_end(array, 5) == 0)
      return (free_array_char(array, MY_OR));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}
