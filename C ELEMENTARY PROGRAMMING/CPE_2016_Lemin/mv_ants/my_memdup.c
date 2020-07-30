/*
** my_memdup.c for utils in /home/pierre/epitech/lib/my/src/utils
**
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
**
** Started on  Mon Apr 10 10:50:30 2017 Pierre J. Alderman
** Last update Sat Apr 15 17:17:29 2017 Charles Aubert
*/

#include <stdlib.h>
#include "../include/lemin.h"

void		*my_memndup(void *src, size_t n)
{
  char		*dup;

  dup = malloc(sizeof(*dup) * n);
  if (!dup)
    return (NULL);
  dup = my_memncpy(dup, src, n);
  return (dup);
}
