/*
** free_list_objects.c for  in /home/miklox/semestre2/infographie/file_xml
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Tue Apr 11 09:06:29 2017 Bastien LECUSSAN
** Last update Thu May  4 14:54:20 2017 Charles Aubert
*/

#include "../inc/rt2.h"

/*This function free the list of objects*/
void	free_list_objects(t_object **list)
{
  int	count;

  count = 0;
  while (list[count] != NULL)
    {
      free(list[count]);
      count += 1;
    }
  free(list);
}
