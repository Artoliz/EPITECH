/*
** search.c for search in /home/descou_c/CPE/CPE_2016_BSQ
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec  6 10:39:47 2016 Charles Descoust
** Last update Sun Dec 18 23:42:03 2016 Charles Descoust
*/

#include "include/bsq.h"

int		while_square(t_map info, t_idx idx)
{
  int		a;
  int		b;

  a = idx.m;
  b = idx.n;
  while (a >= idx.i && b >= idx.j)
    {
      if (info.map[b][a] != '.')
      	return (-1);
      if (info.map[idx.n][a] != '.')
	return (-1);
      if (info.map[b][idx.m] != '.')
	return (-1);
      a = a - 1;
      b = b - 1;
    }
  return (1);
}

t_square	*adjacent_points(t_square *square, t_map info,
				 t_idx idx, int len)
{
  idx.m = idx.i;
  idx.n = idx.j;
  while (idx.m < info.chars && idx.n < info.lines)
    {
      if (while_square(info, idx) == -1)
      	{
      	  if (len > square->len)
      	    square = add_new(square, idx.m - 1, idx.n - 1, len);
      	  return (square);
      	}
      len = len + 1;
      idx.m = idx.m + 1;
      idx.n = idx.n + 1;
    }
  return (square);
}

t_square	*search_square(t_square *square, t_map info, t_idx idx)
{
  int		len;

  while (info.map[idx.j] != NULL)
    {
      idx.i = 0;
      while (info.map[idx.j][idx.i] != '\n' && info.map[idx.j][idx.i] != '\0')
	{
	  len = 0;
	  if (info.map[idx.j][idx.i] == '.')
	    square = adjacent_points(square, info, idx, len);
	  idx.i = idx.i + 1;
	}
      idx.j = idx.j + 1;
    }
  return (square);
}
