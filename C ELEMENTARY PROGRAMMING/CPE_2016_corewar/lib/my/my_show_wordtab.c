/*
** my_show_wordtab.c for  in /home/charliebegood/delivery/CPool_Day08/task03
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Wed Oct 12 13:39:17 2016 Charles AUBERT
** Last update Wed Jan  4 08:57:02 2017 Charles AUBERT
*/

#include "./my.h"

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i += 1;
    }
  return (0);
}
