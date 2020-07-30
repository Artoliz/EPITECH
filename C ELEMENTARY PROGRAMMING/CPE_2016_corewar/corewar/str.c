/*
** str.c for str in /home/descou_c/CPE/corewar_vm
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Mar 23 17:43:10 2017 Charles Descoust
** Last update Fri Mar 31 17:34:28 2017 Charles Descoust
*/

#include "inc/vm.h"

int	calc_puis(unsigned char nb1, unsigned char nb2)
{
  int	puis1;
  int	puis2;
  int	count1;
  int	count2;

  puis1 = 1;
  puis2 = 1;
  count1 = 0;
  count2 = 0;
  while ((nb1 / puis1) > 1)
    {
      puis1 = puis1 * 10;
      count1 += 1;
    }
  while ((nb2 / puis2) > 1)
    {
      puis2 = puis2 * 10;
      count2 += 1;
    }
  count2 -= count1;
  return (count2);
}

int	get_value(unsigned char *oct, int len)
{
  int	res;
  int	i;
  int	puis;

  i = len - 2;
  res = oct[len - 1];
  while (i >= 0)
    {
      puis = calc_puis(oct[i], res);
      res = res + (oct[i] * my_power_rec(16, puis));
      i -= 1;
    }
  return (res);
}

int	get_size(unsigned char *oct)
{
  int	res;
  int	i;
  int	puis;

  i = 2;
  res = oct[3];
  while (i >= 0)
    {
      puis = calc_puis(oct[i], res);
      res = res + (oct[i] * my_power_rec(16, puis));
      i = i - 1;
    }
  return (res);
}

int	my_copy(t_header **champ, t_var* var, char* tmp, int flag)
{
  int   i;

  i = 0;
  if (flag == 1)
    {
      while (tmp[i] != '\0')
        {
          (*champ)[var->j].prog_name[i] = tmp[i];
          i = i + 1;
        }
      (*champ)[var->j].prog_name[i] = '\0';
    }
  else
    {
      while (tmp[i] != '\0')
        {
          (*champ)[var->j].comment[i] = tmp[i];
          i = i + 1;
        }
      (*champ)[var->j].comment[i] = '\0';
    }
  return (0);
}
