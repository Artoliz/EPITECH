/*
** type.c for  in /home/miklox/semestre2/infographie/rt1test/parsing
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Wed May 24 13:22:13 2017 Bastien LECUSSAN
** Last update Sun May 28 10:15:47 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

int	get_line_type_end(char *str, int count)
{
  if ((str[count] == 'g' || str[count] == 'o')
      && (str[count + 1] == ' ' || str[count + 1] == '\t'
	  || str[count + 1] == '\0'))
    return (MY_GROUP_VTX);
  else if (str[count] == 's'
	   && (str[count + 1] == ' ' || str[count + 1] == '\t'
	       || str[count + 1] == '\0'))
    return (MY_OBJ_VTX);
  else if (str[count] == 'u' && str[count + 1] == 's' && str[count + 2] == 'e'
	   && str[count + 3] == 'm' && str[count + 4] == 't'
	   && str[count + 5] == 'l'
	   && (str[count + 6] == ' ' || str[count + 6] == '\t'))
    return (MY_USEMTL);
  else if (str[count] == 'm' && str[count + 1] == 't' && str[count + 2] == 'l'
	   && str[count + 3] == 'l' && str[count + 4] == 'i'
	   && str[count + 5] == 'b')
    return (MY_MTLLIB);
  return (OTHER_TYPE);
}

int     get_line_type(char *str)
{
  int   count;

  count = 0;
  while (str[count] != '\0' && (str[count] == ' ' || str[count] == '\t'))
    count += 1;
  if (str[count] == '\0')
    return (MY_VOID_LINE);
  else if (str[count] == '#')
    return (MY_COMMENT_VTX);
  else if (str[count] == 'v' && (str[count + 1] == ' '
				 || str[count + 1] == '\t'))
    return (MY_VERTICE_VTX);
  else if (str[count] == 'v' && str[count + 1] == 't'
	   && (str[count + 2] == ' ' || str[count + 2] == '\t'))
    return (MY_TEXTURE_VTX);
  else if (str[count] == 'v' && str[count + 1] == 'n'
	   && (str[count + 2] == ' ' || str[count + 2] == '\t'))
    return (MY_NORMAL_VTX);
  else if (str[count] == 'f' && (str[count + 1] == ' '
				 || str[count + 1] == '\t'))
    return (MY_FACE_VTX);
  else
    return (get_line_type_end(str, count));
}
