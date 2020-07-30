/*
** struct.c for struct in /home/descou_c/CPE/CPE_2016_BSQ
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec  6 10:46:28 2016 Charles Descoust
** Last update Wed Dec 14 16:28:30 2016 Charles Descoust
*/

#include "include/bsq.h"

t_square	*add_new(t_square *square, int i, int j, int len)
{
  t_square	*new;

  new = malloc(sizeof(*square));
  new->x = i;
  new->y = j;
  new->len = len;
  new->next = square;
  return (new);
}

t_square	*create_struct()
{
  t_square	*square;

  square = malloc(sizeof(t_square));
  square->x = 0;
  square->y = 0;
  square->len = 0;
  square->next = NULL;
  return (square);
}
