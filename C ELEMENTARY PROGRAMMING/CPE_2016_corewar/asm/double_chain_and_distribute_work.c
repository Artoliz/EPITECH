/*
** double_chain_distribuate_work.c for  in /home/miklox/semestre2/c_prog_elem/write/asm/write_xor
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Fri Mar 24 10:56:15 2017 Bastien LECUSSAN
** Last update Tue Mar 28 14:53:16 2017 Charles Aubert
*/

#include "./include/asm.h"
#include "./include/my.h"

int		interpret_list_to_cor(t_line *list, char *file_s)
{
  int		fd;
  char		*file_name;
  char		*file_cor;

  if ((file_name = malloc(sizeof(char)
			  * (my_strlen(file_s) - 1))) == NULL)
    return (84);
  file_name = my_strncpy(file_name, file_s, my_strlen(file_s) - 2);
  if ((file_cor = join_str_str(file_name, ".cor")) == NULL)
    return (free_str(file_name, 84));
  if (create_list_prev(list) == 84
      || (list = start_from_the_end(list)) == NULL)
    return (free_str(file_cor, 84));
  if ((fd = open(file_cor, O_WRONLY | O_TRUNC | O_APPEND | O_CREAT,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (free_str(file_cor, 84));
  if (lseek(fd, 0, SEEK_END) == -1)
    return (free_str(file_cor, 84));
  free(file_cor);
  free(file_name);
  if (write_in_cor(list, fd) == 84)
    return (84);
  if (close(fd) < 0)
    return (84);
  return (0);
}

int		create_list_prev(t_line *list)
{
  t_line	*tmp;
  t_line	*save;

  tmp = NULL;
  save = list;
  while (list != NULL)
    {
      list->my_tab = NULL;
      list->type_line = NULL;
      list->prev = tmp;
      tmp = list;
      list = list->next;
    }
  list = save;
  return (0);
}

t_line	*start_from_the_end(t_line *list)
{
  if (list != NULL)
    while (list->next != NULL)
      list = list->next;
  return (list);
}

t_line	*return_NULL_free_str(char *str)
{
  free(str);
  return (NULL);
}
