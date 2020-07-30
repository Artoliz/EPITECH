/*
** asm.h for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CoreWar/CPE_2016_corewar/asm/include
**
** Made by Charles Aubert
** Login   <charliebegood@epitech.net>
**
** Started on  Fri Mar 10 09:27:27 2017 Charles Aubert
** Last update Sat Apr  1 17:12:10 2017 Charles Descoust
*/

#ifndef ASM_H_
# define ASM_H_
# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC (4085508608)
# define MAX_ARGS_NUMBER 4
# define MEM_SIZE (6*1024)
# define IDX_MOD 512
# define T_REG (1)
# define T_DIR (4)
# define T_IND (2)
# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR ','
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NUMBERS "0123456789"
# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"
# define MY_LIVE 1
# define MY_LD 2
# define MY_ST 3
# define MY_ADD 4
# define MY_SUB 5
# define MY_AND 6
# define MY_OR 7
# define MY_XOR 8
# define MY_ZJMP 9
# define MY_LDI 10
# define MY_STI 11
# define MY_FORK 12
# define MY_LLD 13
# define MY_LLDI 14
# define MY_LFORK 15
# define MY_AFF 16
# define MY_COMMENT 17
# define MY_NAME 18
# define MY_LABEL 19
# define MY_IGNORE -2
# define MY_INVALID -1

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

typedef struct  s_label
{
  char          *label;
  int           type;
  int           pos;
}               t_label;
typedef struct  s_line
{
  char          *line;
  char          **my_tab;
  char          *type_line;
  int           type;
  t_label       **label;
  struct s_line *prev;
  struct s_line *next;
}               t_line;
typedef struct  s_ptr
{
  int           flag;
  char          *(*fct)(t_line *);
}               t_ptr;
typedef int (*check)(char *);
int     check_line_live(char *line);
int     check_line_ld(char *line);
int     check_line_st(char *line);
int     check_line_add(char *line);
int     check_line_sub(char *line);
int     check_line_and(char *line);
int     check_line_or(char *line);
int     check_line_xor(char *line);
int     check_line_zjmp(char *line);
int     check_line_ldi(char *line);
int     check_line_sti(char *line);
int     check_line_fork(char *line);
int     check_line_lld(char *line);
int     check_line_lldi(char *line);
int     check_line_lfork(char *line);
int     check_line_aff(char *line);
int     check_line_ignore(char *line);
int     check_line_comment(char *line);
int     check_label_creation(char *line);
int     check_args(int dir, int ind, int reg, char *arg);
int     check_extension(char *pathname);
int     check_line(char *line, check *tab);
int     check_end(char **array, int i);
t_line  *check_begin(t_line *list, int fd, int *sum, int *row);
t_line  *loop(int fd, int *line, int *sum);
int     count_args(char *line);
t_line  *add_object(t_line *list, char *line, int type, int *label);
int     display_list(t_line *list);
t_label **get_label(char *line, int *sum);
int     free_list(t_line *list);
int     free_label(t_label **label);
t_line  *init_check(int fd, int *line);
int     check_labels(t_line *list, int count);
int     my_strcmp_in(char *, char *);
char    *check_type_LIVE(t_line *);
char    *check_type_LD(t_line *);
char    *check_type_ST(t_line *);
char    *check_type_ADD(t_line *);
char    *check_type_SUBB(t_line *);
char    *check_type_AND(t_line *);
char    *check_type_OR(t_line *);
char    *check_type_XOR(t_line *);
char    *check_type_ZJMP(t_line *);
char    *check_type_LDI(t_line *);
char    *check_type_STI(t_line *);
char    *check_type_FORK(t_line *);
char    *check_type_LLD(t_line *);
char    *check_type_LLDI(t_line *);
char    *check_type_LFORK(t_line *);
char    *check_type_AFF(t_line *);
check   *create_tab();
t_line  *return_NULL_free_str(char *);
int     interpret_list_to_cor(t_line *, char *);
int     create_list_prev(t_line *);
t_line  *start_from_the_end(t_line *);
int     write_in_cor(t_line *, int);
t_line  *write_header(t_line *, int);
t_line  *write_header_name(t_line *, int, int, char *);
t_line  *write_header_comment(t_line *, int);
int     write_end_header_comment(char **, int, int);
int     write_instructions(t_line *, int);
int     write_type_param(char **, int, t_line *);
int     write_line(t_line *, int, int *);
int     write_type_in_str(char *, int, char *);
char    *complete_str_param(char *, int);
int     set_pos(t_line *, int, int);
int     check_typeparam(t_line *);
int     check_there_is_typeparam(char *);
char    *get_type_line(t_line *, int *, t_ptr *);
char    *set_type_line_by_default(t_line *);
t_ptr   *get_tabptr_cor();
t_ptr   *get_tabptr_end(t_ptr *);
char    get_type_of_arg(char *);
int     interpret_position(t_line *, int *);
int     set_pos_label(t_line *, int, int *);
int     get_big_endian(int, int);
int     write_progsize(int, t_ptr *, int);
int     my_power(int, int);
int     binar_to_decimal(char *);
void    decimal_to_binar(char *, char *, int);
int     write_register(t_line *, int, int);
int     write_indirect(t_line *, int, int);
int     write_direct(t_line *, int, int, int);
int     get_diff_btw_labels(t_line *, char *, int, int);
int     is_there_a_label(t_line *, int);
int     write_index(t_line *, int, int, int);
int	get_nb_diff_labels(t_line *, int, int);
int	diff_btw_labels(t_line *, int, int, char *);
int	loop_line(t_line *, int, int, int);

#endif /* !ASM_H_ */
