/*
** free.c for utils in /home/pierre/epitech/lib/my/src
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Mon Apr 10 09:41:16 2017 Pierre J. Alderman
** Last update Tue Apr 18 18:09:31 2017 Pierre J. Alderman
*/

#include "../include/lemin.h"

int	do_free(void **p)
{
  if (!*p)
    return (0);
  free(*p);
  *p = NULL;
  return (1);
}

int	do_freetab(void ***p)
{
  if (!*p)
    return (0);
  while (*p)
    do_free(*(p++));
  free(*p);
  *p = NULL;
  return (1);
}
