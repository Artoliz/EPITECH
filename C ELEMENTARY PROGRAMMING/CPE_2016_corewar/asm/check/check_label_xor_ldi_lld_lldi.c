/*
** check_label_xor_ldi_lld_lldi.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Mar 24 11:43:22 2017 Charles Aubert
** Last update Sun Apr  2 15:43:54 2017 Charles Descoust
*/

#include "../include/asm.h"

int	check_label_creation(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t")) == NULL ||
      count_args(line) != 0)
    return (free_array_char(array, MY_IGNORE));
  if (array[0][my_strlen(array[0]) - 1] != LABEL_CHAR)
    return (free_array_char(array, MY_IGNORE));
  else if (check_end(array, 1) == 0)
    return (free_array_char(array, MY_LABEL));
  else
    return (free_array_char(array, MY_IGNORE));
}

int	check_line_xor(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 4 || count_args(line) != 2)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "xor") == 0)
    if (check_args(1, 1, 1, array[1]) == 0 &&
        check_args(1, 1, 1, array[2]) == 0 &&
        check_args(0, 0, 1, array[3]) == 0 &&
        check_end(array, 4) == 0)
      return (free_array_char(array, MY_XOR));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 4 && my_strcmp(array[1], "xor") == 0)
    if (check_args(1, 1, 1, array[2]) == 0 &&
        check_args(1, 1, 1, array[3]) == 0 &&
        check_args(0, 0, 1, array[4]) == 0 &&
        check_end(array, 5) == 0)
      return (free_array_char(array, MY_XOR));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}

int	check_line_ldi(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 4 || count_args(line) != 2)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "ldi") == 0)
    if (check_args(1, 1, 1, array[1]) == 0 &&
        check_args(1, 0, 1, array[2]) == 0 &&
        check_args(0, 0, 1, array[3]) == 0 &&
        check_end(array, 4) == 0)
      return (free_array_char(array, MY_LDI));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 4 && my_strcmp(array[1], "ldi") == 0)
    if (check_args(1, 1, 1, array[2]) == 0 &&
        check_args(1, 0, 1, array[3]) == 0 &&
        check_args(0, 0, 1, array[4]) == 0 &&
        check_end(array, 5) == 0)
      return (free_array_char(array, MY_LDI));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}

int	check_line_lld(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 3 || count_args(line) != 1)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "lld") == 0)
    if (check_args(1, 1, 0, array[1]) == 0 &&
        check_args(0, 0, 1, array[2]) == 0 &&
        check_end(array, 3) == 0)
      return (free_array_char(array, MY_LLD));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 3 && my_strcmp(array[1], "lld") == 0)
    if (check_args(1, 1, 0, array[2]) == 0 &&
	check_args(0, 0, 1, array[3]) == 0 &&
	check_end(array, 4) == 0)
      return (free_array_char(array, MY_LLD));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}

int	check_line_lldi(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 4 || count_args(line) != 2)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "lldi") == 0)
    if (check_args(1, 1, 1, array[1]) == 0 &&
        check_args(1, 0, 1, array[2]) == 0 &&
        check_args(0, 0, 1, array[3]) == 0 &&
        check_end(array, 4) == 0)
      return (free_array_char(array, MY_LLDI));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 4 && my_strcmp(array[1], "lldi") == 0)
    if (check_args(1, 1, 1, array[2]) == 0 &&
        check_args(1, 0, 1, array[3]) == 0 &&
        check_args(0, 0, 1, array[4]) == 0 &&
        check_end(array, 5) == 0)
      return (free_array_char(array, MY_LLDI));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}
