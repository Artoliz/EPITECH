/*
** args.c for CoreWarAsm in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed Mar 22 21:14:29 2017 Charles Aubert
** Last update Tue Mar 28 15:40:28 2017 Charles Aubert
*/

#include "../include/asm.h"

int	check_dir(char *arg)
{
  if (arg[0] != DIRECT_CHAR || my_strlen(arg) < 2)
    return (-1);
  if (arg[1] == LABEL_CHAR)
    {
      if (occurence(arg, LABEL_CHARS, 2) != 0)
	return (-1);
      return (0);
    }
  if (occurence(arg, NUMBERS, 1) != 0)
    return (-1);
  return (0);
}

int	check_ind(char *arg)
{
  if (my_str_isnum(arg) != 0)
    return (-1);
  return (0);
}

int	check_reg(char *arg)
{
  if (arg[0] != 'r' || occurence(arg, NUMBERS, 1) != 0)
    return (-1);
  return (0);
}

int	check_args(int dir, int ind, int reg, char *arg)
{
  if (dir == 1 && check_dir(arg) == 0)
    return (0);
  else if (ind == 1 && check_ind(arg) == 0)
    return (0);
  else if (reg == 1 && check_reg(arg) == 0)
    return (0);
  return (1);
}

int	count_args(char *line)
{
  int	i;
  int	count;
  int	com;

  i = 0;
  com = 0;
  count = 0;
  while (line[i] != '\0')
    {
      if (line[i] == SEPARATOR_CHAR && com == 0)
	count += 1;
      if (line[i] == COMMENT_CHAR)
	com = 1;
      i += 1;
    }
  return (count);
}
