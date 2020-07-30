/*
** write_direct_index.c for  in /home/miklox/semestre2/c_prog_elem/ASM/asm
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Tue Mar 28 16:08:16 2017 Bastien LECUSSAN
** Last update Sun Apr  2 15:46:42 2017 Charles Descoust
*/

#include "../include/asm.h"
#include "../include/my.h"

int		get_nb_diff_labels(t_line *list, int cnt, int pos)
{
  int		down;
  int		cpt;
  int		nb;

  cpt = 0;
  nb = 0;
  while (list->label[cpt] != NULL)
    {
      if (my_strcmp_in(list->my_tab[cnt], list->label[cpt]->label) == 0
	  && list->label[cpt]->type == 1)
	nb = get_diff_btw_labels(list, list->label[cpt]->label, cpt, pos);
      cpt += 1;
    }
  return (nb);
}

int	write_index(t_line *list, int count, int fd, int pos)
{
  int   cnt;
  int   nb;

  if (list->label != NULL && list->label[0]->type == 0)
    cnt = 2;
  else
    cnt = 1;
  cnt += count;
  if (list->label != NULL && is_there_a_label(list, cnt) == 0)
    nb = get_nb_diff_labels(list, cnt, pos);
  else
    {
      list->my_tab[cnt] = remove_char(list->my_tab[cnt], "%", 1);
      nb = my_getnbr(list->my_tab[cnt]);
    }
  nb = get_big_endian(nb, 2);
  if (write(fd, &nb, 2) == -1)
    return (84);
  return (0);
}

int		diff_btw_labels(t_line *list, int flag, int pos, char *str)
{
  int		count;
  t_line	*tmp2;

  tmp2 = list;
  while (tmp2 != NULL)
    {
      count = 0;
      if (tmp2->label != NULL)
	while (tmp2->label[count] != NULL)
	  {
	    if (my_strcmp(str, tmp2->label[count]->label) == 0
		&& tmp2->label[count]->type != 1)
	      return (4294967295 - (list->label[flag]->pos
				    - tmp2->label[count]->pos) + pos + 1);
	    count += 1;
	  }
      tmp2 = tmp2->next;
    }
  return (0);
}

int		get_diff_btw_labels(t_line *list, char *str, int flag, int pos)
{
  t_line        *tmp;
  t_line        *tmp2;
  int           count;

  tmp = list;
  tmp2 = list;
  while (tmp != NULL)
    {
      count = 0;
      if (tmp->label != NULL)
	while (tmp->label[count] != NULL)
	  {
	    if (my_strcmp(str, tmp->label[count]->label) == 0
		&& tmp->label[count]->type == 0)
	      return (tmp->label[count]->pos
		      - list->label[flag]->pos + pos);
	    count += 1;
	  }
      tmp = tmp->prev;
    }
  return (diff_btw_labels(list, flag, pos, str));
}

int	write_direct(t_line *list, int count, int fd, int position)
{
  int   cnt;
  int   nb;

  if (list->label != NULL && list->label[0]->type == 0)
    cnt = 2;
  else
    cnt = 1;
  cnt += count;
  if (list->label != NULL && is_there_a_label(list, cnt) == 0)
    nb = get_nb_diff_labels(list, cnt, position);
  else
    {
      list->my_tab[cnt] = remove_char(list->my_tab[cnt], "%", 1);
      nb = my_getnbr(list->my_tab[cnt]);
    }
  nb = get_big_endian(nb, T_DIR);
  if (write(fd, &nb, T_DIR) == -1)
    return (84);
  return (0);
}
