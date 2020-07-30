/*
** check_label.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Sat Mar 25 09:24:50 2017 Charles Aubert
** Last update Tue Mar 28 15:41:09 2017 Charles Aubert
*/

#include "../include/asm.h"

t_label		**get_all_labels(t_line *list, t_label **labels)
{
  t_line	*tmp;
  int		i;
  int		i2;

  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      if (tmp->label != NULL)
	{
	  i2 = 0;
	  while (tmp->label[i2] != NULL)
	    {
	      labels[i] = tmp->label[i2];
	      i2 += 1;
	      i += 1;
	    }
	}
      tmp = tmp->next;
    }
  labels[i] = NULL;
  return (labels);
}

int		check_defs(t_label **labels, char *label)
{
  int		i;

  i = 0;
  while (labels[i] != NULL)
    {
      if (my_strcmp(label, labels[i]->label) == 0
	  && labels[i]->type == 0)
	return (0);
      i += 1;
    }
  return (1);
}

int		check_calls(t_label **labels)
{
  int		i;

  i = 0;
  while (labels[i] != NULL)
    {
      if (labels[i]->type == 1 && check_defs(labels, labels[i]->label) != 0)
	return (1);
      i += 1;
    }
  return (0);
}

int		check_labels(t_line *list, int count)
{
  t_label	**labels;

  if ((labels = malloc(sizeof(t_label *) * (count + 1))) == NULL)
    return (84);
  labels = get_all_labels(list, labels);
  if (check_calls(labels) != 0)
    return (84);
  free(labels);
  return (0);
}

t_line		*check_begin(t_line *list, int fd, int *sum, int *row)
{
  char		*line;
  char		*line2;

  list = NULL;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (check_line_comment(line) == MY_NAME)
	{
	  if ((line2 = get_next_line(fd)) == NULL)
	    return (NULL);
	  if (check_line_comment(line2) == MY_COMMENT)
	    {
	      list = add_object(list, line, MY_NAME, sum);
	      list = add_object(list, line2, MY_COMMENT, sum);
	      *row += 2;
	      return (list);
	    }
	}
    }
  return (NULL);
}
