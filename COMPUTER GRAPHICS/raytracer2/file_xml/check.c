/*
** check.c for  in /home/miklox/semestre2/infographie/file_xml
**
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
**
** Started on  Tue Apr 11 07:58:45 2017 Bastien LECUSSAN
** Last update Mon May 22 10:42:52 2017 Charles Aubert
*/

#include "../inc/rt2.h"

/*This function checks that the requirements are complete to
start to load an object*/
int     check_for_next_objects(int fd)
{
  char  *buf;
  int   count;

  count = 0;
  if ((buf = get_next_line(fd)) == NULL)
    return (-1);
  while (buf[count] != '\0')
    {
      if (buf[count] != ' ' && buf[count] != '\t')
	return (-1);
      count += 1;
    }
  free(buf);
  return (0);
}

/*This function check if the str start by the str given and
return the pos of the char after this word.*/
int	my_strcmp_start(char *str, char *str2)
{
  int	count;

  count = 0;
  while (str[count] != '\0' && str2[count] != '\0')
    {
      if (str[count] != str2[count])
	return (-1);
      count += 1;
    }
  if (str2[count] != '\0' || str[count] == '\0')
    return (-1);
  return (count);
}

/*This functions check if the nbr is good ( can be float or nbr)*/
int	check_nbr(char *buf)
{
  int	count;
  int	point;

  point = 0;
  count = 0;
  if (buf[count] == '-')
    count = 1;
  while (buf[count] != '\0')
    {
      if ((buf[count] < '0' || buf[count] > '9') && buf[count] != '.')
	return (-1);
      if (buf[count] == '.' && count == 0)
	return (-1);
      if (buf[count] == '.')
	point += 1;
      count += 1;
    }
  if (point > 1)
    return (-1);
  return (0);
}

/*This functions checks that the tab is good.*/
int	check_requirments_tab(char **my_line)
{
  int	count;

  count = 0;
  while (my_line[count] != NULL)
    {
      if (count != 0)
	if (check_nbr(my_line[count]) == -1)
	  return (-1);
      count += 1;
    }
  if (count != 4)
    return (-1);
  return (0);
}

/*This function check that this is the end of the file*/
int	check_end_of_file(int fd)
{
  char	*buf;
  int	count;

  while ((buf = get_next_line(fd)) != NULL)
    {
      count = 0;
      while (buf[count] != '\0')
	{
	  if (buf[count] != ' ' && buf[count] != '\t')
	    return (-1);
	  count += 1;
	}
      free(buf);
    }
  return (0);
}
