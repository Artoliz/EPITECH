/*
** linked_list.c for linked_list in /home/descou_c/Graphic/raytracer1
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sun Feb 12 16:38:28 2017 Charles Descoust
** Last update Tue Mar 14 13:13:03 2017 Charles Descoust
*/

#include "inc/my.h"

t_my_object*	add_color(char** c, int *i, t_my_object* new)
{
  int		j;
  t_ptr_color	tab[]=
    {
      {"sfWhite", white_color},
      {"sfBlack", black_color},
      {"sfCyan", cyan_color},
      {"sfMagenta", magenta_color},
      {"sfBlue", blue_color},
      {"sfGreen", green_color},
      {"sfYellow", yellow_color},
      {"sfRed", red_color},
    };

  j = 0;
  if (c[*i][0] != '0')
    {
      while (j < 8)
	{
	  if (my_strcmp(tab[j].color_name, c[*i]) == 0)
	    new->color = tab[j].ft();
	  j = j + 1;
	}
    }
  return (new);
}

t_my_object*	add_coord_rotate(t_my_object* new, char** c, int *i, int flag)
{
  if (my_while_error_file(c, i) == 84)
    return (NULL);
  if (flag == 1)
    {
      new->coord.x = my_getnbr_float(c[*i]);
      *i = *i + 1;
      new->coord.y = my_getnbr_float(c[*i]);
      *i = *i + 1;
      new->coord.z = my_getnbr_float(c[*i]);
      *i = *i + 1;
    }
  else if (flag == 2)
    {
      new->rotate.x = my_getnbr_float(c[*i]);
      *i = *i + 1;
      new->rotate.y = my_getnbr_float(c[*i]);
      *i = *i + 1;
      new->rotate.z = my_getnbr_float(c[*i]);
      *i = *i + 1;
    }
  return (new);
}

t_my_object*	add_maillon2(char** c, t_my_object* new, int *i)
{
  if (my_strisfloat(c[*i]) == 84)
    return (NULL);
  if (*i >= 1 && *i <= 3)
    {
      if ((new = add_coord_rotate(new, c, i, 1)) == NULL)
	return (NULL);
    }
  if (*i >= 4 && *i <= 6)
    {
      if ((new = add_coord_rotate(new, c, i, 2)) == NULL)
  	return (NULL);
    }
  return (new);
}

t_my_object	*add_maillon(char** c, t_my_object* obj, int *i)
{
  t_my_object*  new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  if (*i == 0)
    {
      if ((new->name = malloc(sizeof(char) * 10)) == NULL)
        return (NULL);
      new->name = my_strcpy(new->name, c[*i]);
      *i = *i + 1;
    }
  if ((new = add_maillon2(c, new, i)) == NULL)
    return (NULL);
  if ((new = add_maillon_next(c, new, i)) == NULL)
    return (NULL);
  new->next = obj;
  obj = new;
  return (obj);
}

char	**coord_rotate_radius_in_tab(char* buff, char** c)
{
  int   i;
  int   j;
  int   k;

  i = 0;
  j = 0;
  while (buff[i] != '\0')
    {
      if ((c[j] = malloc(sizeof(char) * my_strlen(buff))) == NULL)
        return (NULL);
      k = 0;
      while (buff[i] != '/' && buff[i] != '\n' &&
             buff[i] != ':' && buff[i] != '\0')
        {
          c[j][k] = buff[i];
          k = k + 1;
          i = i + 1;
        }
      c[j][k] = '\0';
      j = j + 1;
      i = i + 1;
    }
  c[j] = NULL;
  return (c);
}
