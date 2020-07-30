/*
** file.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/DraftCoreWar/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Tue Mar 14 21:26:27 2017 Charles Aubert
** Last update Mon Mar 27 16:23:57 2017 Charles Aubert
*/

#include "./include/my.h"
#include "./include/asm.h"

t_line		*init_check(int fd, int *line)
{
  t_line	*list;
  int		sum;

  sum = 0;
  if ((list = loop(fd, line, &sum)) == NULL)
    {
      my_printf("An error occured at line %d of the file.\n", *line);
      return (NULL);
    }
  if (check_labels(list, sum) != 0)
    {
      my_putstr_er("Calling an inexistant label.\n", 0);
      free_list(list);
      return (NULL);
    }
  return (list);
}

t_line		*loop(int fd, int *row, int *sum)
{
  int		type;
  char		*line;
  check		*tab;
  t_line	*list;

  *row = 1;
  list = NULL;
  if ((tab = create_tab()) == NULL ||
      (list = check_begin(list, fd, sum, row)) == NULL)
    return (NULL);
  while ((line = get_next_line(fd)) != NULL)
    {
      if ((type = check_line(line, tab)) == -1)
	return (NULL);
      if (type != MY_IGNORE &&
	  (list = add_object(list, line, type, sum)) == NULL)
	return (NULL);
      *row += 1;
    }
  free(tab);
  return (list);
}
