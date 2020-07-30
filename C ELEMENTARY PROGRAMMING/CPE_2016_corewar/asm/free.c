/*
** free.c for CoreWarAsm in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Mar 23 22:27:36 2017 Charles Aubert
** Last update Sun Apr  2 15:40:46 2017 Charles Descoust
*/

#include "./include/my.h"
#include "./include/asm.h"

int	free_label(t_label **label)
{
  int	i;

  i = 0;
  if (label == NULL)
    return (0);
  while (label[i] != NULL)
    {
      free(label[i]->label);
      free(label[i]);
      i += 1;
    }
  free(label);
  return (0);
}

int		free_list(t_line *list)
{
  t_line        *next;

  next = list->next;
  while (next != NULL)
    {
      if (list->my_tab != NULL)
	free_array_char(list->my_tab, 0);
      if (list->type_line != NULL)
	free(list->type_line);
      free_label(list->label);
      free(list->line);
      free(list);
      list = next;
      next = list->next;
    }
  free(next);
  free_label(list->label);
  free(list->line);
  free(list);
  return (0);
}
