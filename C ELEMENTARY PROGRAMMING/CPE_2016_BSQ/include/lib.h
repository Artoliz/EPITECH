/*
** my.h for my.h in /home/descou_c/CPool_Day09/include
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Thu Oct 13 09:02:20 2016 Charles Descoust
** Last update Wed Dec 14 09:36:51 2016 Charles Descoust
*/

#ifndef LIB_H_
# define LIB_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_printf.h"

typedef struct	s_idx
{
  int		i;
  int		j;
  int		k;
  int		l;
  int		m;
  int		n;
}		t_idx;

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_getnbr(char *str);
int	my_put_nbr_base(long nb, char *base);
char	*my_strcat(char *dest, char *src);

#endif /* !LIB_H_ */
