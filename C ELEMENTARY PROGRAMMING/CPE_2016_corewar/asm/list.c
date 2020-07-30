/*
** list.c for CoreWarAsm in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Mar 21 16:33:45 2017 Charles Aubert
** Last update Sat Mar 25 09:26:36 2017 Charles Aubert
*/

#include "./include/my.h"
#include "./include/asm.h"

t_line		*add_object(t_line *list, char *line, int type, int *label)
{
  t_line	*object;

  if ((object = malloc(sizeof(t_line))) == NULL)
    return (NULL);
  object->line = line;
  object->type = type;
  object->label = get_label(line, label);
  object->next = list;
  return (object);
}
