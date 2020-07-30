/*
** bsq.h for bsq in /home/descou_c/CPE/CPE_2016_BSQ/include
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Dec  6 09:03:47 2016 Charles Descoust
** Last update Sun Dec 18 22:19:10 2016 Charles Descoust
*/

#ifndef BSQ_H_
# define BSQ_H_

#include "lib.h"

typedef struct		s_square
{
  int			x;
  int			y;
  int			len;
  struct s_square	*next;
}			t_square;

typedef struct	s_map
{
  char		**map;
  int		lines;
  int		chars;
}		t_map;

void		aff_tab(char**, int, int, t_square*);
char		**open_read_file(char*);
int		count_chars(char*);
int		count_lines(char*);
int		len_first_line(char*);
char		**str_to_tab(char*, int, int);
t_square	*create_struct();
t_square	*add_new(t_square*, int, int, int);
t_square	*search_square(t_square*, t_map, struct s_idx);
t_map		add_map_info(char*, char**);
t_square	*adjacent_points(t_square*, t_map, struct s_idx, int);
int		while_square(t_map, t_idx);

#endif /* !BSQ_H_ */
