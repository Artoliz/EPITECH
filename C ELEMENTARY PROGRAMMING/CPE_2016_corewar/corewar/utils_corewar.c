/*
** utils_corewar.c for utils_corewar in /home/descou_c/CPE/CPE_2016_corewar/corewar
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Fri Mar 31 13:29:05 2017 Charles Descoust
** Last update Sun Apr  2 14:34:47 2017 Charles Descoust
*/

#include "inc/vm.h"

int	*convert_chain_binar(char *str)
{
  int   count;
  int   *my_tab;
  int   cnt;

  cnt = 1;
  count = 0;
  if ((my_tab = malloc(sizeof(*my_tab) * 4)) == NULL)
    exit (84);
  while (count < 4)
    {
      if (str[cnt - 1] == '0' && str[cnt] == '1')
        my_tab[count] = REG_SIZE;
      else if (str[cnt - 1] == '1' && str[cnt] == '0')
        my_tab[count] = DIR_SIZE;
      else if (str[cnt - 1] == '1' && str[cnt] == '1')
        my_tab[count] = IND_SIZE;
      else
        my_tab[count] = NULL_SIZE;
      cnt += 2;
      count += 1;
    }
  return (my_tab);
}

char	*complete_with_zero(char *str)
{
  int   count;

  count = 0;
  str = my_revstr(str);
  while (str[count] != '\0')
    count = count + 1;
  while (count < 8)
    {
      str[count] = '0';
      count = count + 1;
    }
  str[count] = '\0';
  str = my_revstr(str);
  return (str);
}

int		convert(int *i, t_process proc, int type)
{
  int           res;
  unsigned char *oct;
  int           j;

  if ((oct = malloc(sizeof(unsigned char) * type)) == NULL)
    exit (84);
  j = 0;
  while (j < type)
    {
      oct[j] = proc.warrior->instru[*i];
      *i += 1;
      j += 1;
    }
  *i -= 1;
  res = get_value(oct, type);
  free(oct);
  return (res);
}

char	*decimal_to_binar(unsigned char nb)
{
  char  *str;
  char  binar[] = "01";
  int   length_base;
  int   count;

  count = 0;
  length_base = 2;
  if ((str = malloc(sizeof(char) * 9)) == NULL)
    exit(84);
  while (nb > 0)
    {
      if (nb >= length_base)
        str[count] = binar[(nb % length_base)];
      else
        str[count] = binar[nb];
      count += 1;
      nb /= length_base;
    }
  str[count] = '\0';
  my_revstr(str);
  str = complete_with_zero(str);
  return (str);
}

int	check_overlap(t_process *procs, t_var var)
{
  int   i;
  int   res1;

  i = 0;
  while (i < var.cor)
    {
      if (i + 1 < var.cor &&
          (procs[i].warrior->l_a != 0 && procs[i + 1].warrior->l_a != 0))
        {
          res1 = procs[i].warrior->l_a + procs[i].warrior->prog_size;
          if (res1 >= procs[i + 1].warrior->l_a)
            return (84);
        }
      i += 1;
    }
  return (0);
}
