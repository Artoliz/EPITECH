/*
** set_pos_label.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Sun Mar 26 19:19:54 2017 Bastien LECUSSAN
** Last update Thu Mar 30 15:21:12 2017 Charles Aubert
*/

#include "./include/asm.h"
#include "./include/my.h"

int	set_pos_label(t_line *list, int count, int *position)
{
  int	cnt;
  int	cpt;

  cpt = 0;
  if (list->label != NULL && list->label[0]->type == 0)
    cnt = 2;
  else
    cnt = 1;
  if (list->label != NULL)
    while (list->label[cpt] != NULL)
      {
	if (my_strcmp_in(list->my_tab[count + cnt], list->label[cpt]->label) == 0
	    && list->label[cpt]->type == 1)
	  list->label[cpt]->pos = position[0];
	cpt += 1;
      }
  return (0);
}

int	interpret_position(t_line *list, int *position)
{
  int	count;

  count = 0;
  position[0] += 1;
  if (check_typeparam(list) == 84)
    position[0] += 1;
  while (list->type_line[count] != '\0' && list->type_line[count] != '0')
    {
      if (set_pos_label(list, count, position) == 84)
	return (84);
      if (list->type_line[count] == '9')
	position[0] += 2;
      else
	position[0] += list->type_line[count] - '0';
      count += 1;
    }
  return (0);
}

char	*get_type_line(t_line *list, int *position, t_ptr *tabptr)
{
  int	count;

  count = 0;
  while (count < 16)
    {
      if (tabptr[count].flag == list->type)
	if ((list->type_line = tabptr[count].fct(list)) == NULL)
	  return (NULL);
      count += 1;
    }
  if (interpret_position(list, position) == 84)
    return (NULL);
  return (list->type_line);
}

int		set_pos(t_line *list, int fd, int position)
{
  t_line	*tmp;
  t_ptr		*tabptr;

  tmp = list;
  if ((tabptr = get_tabptr_cor()) == NULL)
    return (84);
  while (tmp != NULL)
    {
      if (tmp->type >= MY_LIVE && tmp->type <= MY_AFF)
	{
	  if (tmp->label != NULL)
	    if (tmp->label[0]->type == 0)
	      tmp->label[0]->pos = position;
	  if ((tmp->my_tab = my_str_to_wordtab(tmp->line, ", \t")) == NULL)
	    return (84);
	  if ((tmp->type_line = get_type_line(tmp, &position, tabptr)) == NULL)
	    return (84);
	}
      else if (tmp->type == MY_LABEL)
	tmp->label[0]->pos = position;
      tmp = tmp->prev;
    }
  return (write_progsize(position, tabptr, fd));
}
