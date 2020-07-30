/*
** write_file_cor.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Sun Mar 26 15:27:48 2017 Bastien LECUSSAN
** Last update Sat Apr  1 17:09:41 2017 Charles Descoust
*/

#include "../include/asm.h"

int		write_instructions(t_line *list, int fd)
{
  int		position;
  int		instruction;

  position = 0;
  while (list != NULL)
    {
      if (list->type >= MY_LIVE && list->type <= MY_AFF)
	{
	  instruction = list->type;
	  if (write(fd, &instruction, 1) == -1)
	    return (84);
	  position += 1;
	  if (check_typeparam(list) == 84)
	    {
	      position += 1;
	      if (write_type_param(list->my_tab, fd, list) == 84)
		return (84);
	    }
	  if (write_line(list, fd, &position) == 84)
	    return (84);
	}
      list = list->prev;
    }
  return (0);
}
