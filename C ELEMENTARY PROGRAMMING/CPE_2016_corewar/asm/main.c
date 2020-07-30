/*
** main.c for CoreWarAsm in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Wed Mar 22 21:14:10 2017 Charles Aubert
** Last update Sun Apr  2 15:40:55 2017 Charles Descoust
*/

#include "./include/my.h"
#include "./include/asm.h"

int	display_label(t_label **label)
{
  int	i;

  i = 0;
  if (label == NULL)
    return (0);
  while (label[i] != NULL)
    {
      my_printf("label%d type:%d = %s\n", i, label[i]->type, label[i]->label);
      i += 1;
    }
  return (0);
}

int		display_list(t_line *list)
{
  t_line        *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_printf("type = %d, line = %s\n", tmp->type, tmp->line);
      if (tmp->type_line != NULL)
        my_printf("type_line = %s\n", tmp->type_line);
      display_label(tmp->label);
      tmp = tmp->next;
    }
  return (0);
}

int	display_usage(char *bin)
{
  my_printf("USAGE\n\t%s file_name[.s]\n\nDESCRIPTION\n", bin);
  my_putstr("\tfile_name\tfile in assembly language to be converted into");
  my_putstr(" file_name.cor, an\n\t\t\texecutable in the Virtual Machine.\n");
  return (0);
}

int		main(int ac, char** av)
{
  int		fd;
  int		line;
  t_line	*list;

  if (ac != 2)
    return (my_putstr_er("Invalid number of arguments.\n", 84));
  if (my_strcmp(av[1], "-h") == 0)
    return (display_usage(av[0]));
  if ((fd = check_extension(av[1])) <= 0)
    return (my_putstr_er("Invalid file.\n", 84));
  if ((list = init_check(fd, &line)) == NULL)
    return (84);
  if (interpret_list_to_cor(list, av[1]) == 84)
    {
      my_printf("An error occured while writing (file).cor.\n", line);
      free_list(list);
      return (84);
    }
  free_list(list);
  close(fd);
  return (0);
}
