/*
** header_end.c for  in /home/miklox/semestre2/c_prog_elem/write/asm2
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Mon Mar 27 19:14:31 2017 Bastien LECUSSAN
** Last update Tue Mar 28 14:42:19 2017 Charles Aubert
*/

#include "./include/asm.h"
#include "./include/my.h"

int	write_progsize(int position, t_ptr *tabptr,
		       int fd)
{
  position = get_big_endian(position, 4);
  if (write(fd, &position, 4) == -1)
    return (84);
  free(tabptr);
  return (0);
}
