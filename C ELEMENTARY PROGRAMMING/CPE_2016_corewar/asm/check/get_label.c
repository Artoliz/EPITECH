/*
** label.c for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/ASM/asm
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Mar 23 11:47:37 2017 Charles Aubert
** Last update Tue Mar 28 15:45:28 2017 Charles Aubert
*/

#include "../include/asm.h"

char	*check_label_e(char *label, int *type)
{
  int	i;
  int	i2;

  i = 0;
  i2 = 0;
  if (label[my_strlen(label) - 1] != LABEL_CHAR)
    return (NULL);
  while (label[i] != '\0' && i < my_strlen(label) - 1)
    {
      i2 = 0;
      while (LABEL_CHARS[i2] != '\0' && label[i] != LABEL_CHARS[i2])
	i2 += 1;
      if (LABEL_CHARS[i2] == '\0')
	return (NULL);
      i += 1;
    }
  *type = 0;
  return (remove_char(label, ":", 0));
}

char	*check_label_b(char *label, int *type)
{
  if (label[0] != LABEL_CHAR)
    return (NULL);
  if (occurence(label, LABEL_CHARS, 1) == 0)
    {
      *type = 1;
      return (remove_char(label, ":", 0));
    }
  return (NULL);
}

int	count_label(char **array, int *type)
{
  int	i;
  int	count;
  char	*label;

  i = 0;
  count = 0;
  while (array[i] != NULL)
    {
      if ((label = check_label_e(array[i], type)) != NULL ||
	  (label = check_label_b(array[i], type)) != NULL)
	{
	  free(label);
	  count += 1;
	}
      i += 1;
    }
  return (count);
}

t_label		**create_struct(char *line, int *i2, t_label **labels)
{
  t_label	*result;
  char		*temp;
  int		type;

  if ((result = malloc(sizeof(t_label))) == NULL)
    return (NULL);
  if ((temp = check_label_b(line, &type)) != NULL ||
      (temp = check_label_e(line, &type)) != NULL)
    {
      result->label = temp;
      result->type = type;
      labels[*i2] = result;
      *i2 += 1;
    }
  else
    free(result);
  return (labels);
}

t_label		**get_label(char *line, int *sum)
{
  char		**array;
  t_label	**result;
  int		i;
  int		i2;
  int		count;

  if ((array = my_str_to_wordtab(line, " %\t,")) == NULL)
    return (NULL);
  if ((count = count_label(array, &i2)) == 0 ||
      (result = malloc(sizeof(t_label *) * (count + 1))) == NULL)
    {
      free_array_char(array, 0);
      return (NULL);
    }
  *sum += count;
  i = 0;
  i2 = 0;
  while (array[i] != NULL)
    {
      result = create_struct(array[i], &i2, result);
      i += 1;
    }
  result[i2] = NULL;
  free_array_char(array, 0);
  return (result);
}
