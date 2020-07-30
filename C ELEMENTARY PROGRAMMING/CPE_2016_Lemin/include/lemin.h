/*
** mini.h for  in /home/charliebegood/delivery/UNIX_System/Minishell1/PSU_2016_minishell1/include
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Mon Jan  9 10:51:53 2017 Charles AUBERT
** Last update Sat Apr 29 20:47:37 2017 Bastien LECUSSAN
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/wait.h>
#include "my.h"

# define MY_NORMAL 0
# define MY_START 1
# define MY_END 2

typedef struct		s_summit
{
  char			*name;
  int			type;
  int			data;
  int			x;
  int			y;
  struct s_link		*links;
}			t_summit;

typedef struct		s_link
{
  struct s_summit	*summit;
  struct s_link		*next;
  struct s_link		*prev;
}			t_link;

typedef struct		s_graph
{
  int			ants;
  int			paths;
  int			size;
  struct s_summit	**summits;
  struct s_summit	*start;
  struct s_summit	*end;
}			t_graph;

typedef struct	s_path
{
  t_link	*path;
  int		size;
  struct s_path *next;
}		t_path;

typedef struct	s_search
{
  t_summit	*start;
  t_link	*path;
  int		i;
  int		max;
  int		min;
  char		*origin;
  char		*name;
  char		*send;
}		t_search;

t_graph         *get_graph();
int             check_link(char *line);
int             check_def(char *line);
int             check_comment(char *line);
int             check_end_start(char *line);
t_summit        **get_summits(t_link *);
int             display_struct(t_summit **file);
int             free_tab_summits(t_summit **res);
int             free_graph(t_graph *graph);
int             free_links(t_link *links);
int             check_summit(t_summit **res);
t_summit        *create_summit(char *line, int *type, t_link *sums);
int             valid_link(char *line, t_summit **res);
int             valid_summit(t_link *sums, char *name, int x, int y);
t_summit        **link_summit(char *line, t_summit **res);
t_summit        *get_link(t_summit **res, char *name);
t_link          *create_link(t_link *links, t_summit *add);
int             display_links(t_link *links);
int             display_graph(t_graph *graph);
t_summit        *get_summit_type(t_summit **res, int type);
int             check_file(char **tab);
t_search        init_search(t_summit *start, t_summit *end, int max);
t_search        scan_links(t_search search, int flag);
int             display_start(t_graph *graph);
t_link		*free_links_last(t_link *links);
t_link          *double_chain(t_link *list);
int             display_double_link(t_link *list);
void		free_path(t_path *path);
t_path		*reverse_path(t_path *path);
t_summit	**get_copy_summits(t_summit **summits);
t_link		*delete_summits_end(t_link **tmp, t_link *list,
				    t_link *to_delete, int *count);
int		my_algo(t_graph *graph);
t_search        find_smallest2(t_link *save, t_search search);
t_search        update_struct(t_search search, t_summit *start, char *name);

void		mv_ants_to_next_summits(t_graph *info,
					t_link **ants,
					int nb_paths);
int		put_ants(t_link **ants, t_summit *f_summit);
int		mv_ants(t_graph *infos, t_path *paths);
void		*my_memncpy(void *dest, void *src, size_t n);
void		*my_memndup(void *src, size_t n);
t_link		*link_dup(t_link *src);

void		kill_ants(t_link **ants);
int		do_free(void **p);
#endif /* !LEMIN_H_ */
