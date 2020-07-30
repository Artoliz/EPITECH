/*
** check_aff.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Mar 24 11:55:27 2017 Charles Aubert
** Last update Sun Apr  2 15:42:40 2017 Charles Descoust
*/

#include "../include/asm.h"

int	check_line_aff(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t")) == NULL ||
      size_array_char(array) < 2 || count_args(line) != 0)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "aff") == 0)
    if (check_args(0, 0, 1, array[1]) == 0 && check_end(array, 2) == 0)
      return (free_array_char(array, MY_AFF));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 2 &&
           my_strcmp(array[1], "aff") == 0)
    if (check_args(0, 0, 1, array[2]) == 0 && check_end(array, 3) == 0)
      return (free_array_char(array, MY_AFF));
    else
      return (free_array_char(array, MY_INVALID));
  return (free_array_char(array, MY_IGNORE));
}

int	check_line_sub(char *line)
{
  char  **array;

  if ((array = my_str_to_wordtab(line, " \t,")) == NULL ||
      size_array_char(array) < 4 || count_args(line) != 2)
    return (free_array_char(array, MY_IGNORE));
  if (my_strcmp(array[0], "sub") == 0)
    if (check_args(0, 0, 1, array[1]) == 0 &&
        check_args(0, 0, 1, array[2]) == 0 &&
        check_args(0, 0, 1, array[3]) == 0 && check_end(array, 4) == 0)
      return (free_array_char(array, MY_SUB));
    else
      return (free_array_char(array, MY_INVALID));
  else if (size_array_char(array) > 4 && my_strcmp(array[1], "sub") == 0)
    if (check_args(0, 0, 1, array[2]) == 0 &&
        check_args(0, 0, 1, array[3]) == 0 &&
        check_args(0, 0, 1, array[4]) == 0 && check_end(array, 5) == 0)
      return (free_array_char(array, MY_SUB));
    else
      return (free_array_char(array, MY_INVALID));
  free_array_char(array, 0);
  return (MY_IGNORE);
}
