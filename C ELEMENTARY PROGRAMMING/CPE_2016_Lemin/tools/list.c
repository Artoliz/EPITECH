/*
** list.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/Lemin/Charles
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Apr 10 17:43:35 2017 Charles Aubert
** Last update Sat Apr 29 17:48:50 2017 Charles Aubert
*/

#include "../include/lemin.h"

t_link   *double_chain(t_link *list)
{
  t_link *tmp;

  tmp = NULL;
  while (list != NULL)
    {
      list->prev = tmp;
      tmp = list;
      list = list->next;
    }
  list = tmp;
  return (list);
}
