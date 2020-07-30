/*
** chech_file.c for  in /home/miklox/semestre2/infographie/rt1test/parsing
** 
** Made by Bastien LECUSSAN
** Login   <miklox@epitech.net>
** 
** Started on  Tue May  9 10:27:07 2017 Bastien LECUSSAN
** Last update Wed May 24 14:03:16 2017 Bastien LECUSSAN
*/

#include "raytracer2.h"

int	check_extension(char *file)
{
  int	count;

  count = 0;
  while (file[count] != '\0')
    count += 1;
  while (count > 0 && file[count] != '.')
    count -= 1;
  if (file[count] != '.' || file[count + 1] != 'o'
      || file[count + 2] != 'b' || file[count + 3] != 'j'
      || file[count + 4] != '\0')
    return (-1);
  if (my_strlen(file) < 5)
    return (-1);
  return (0);
}
