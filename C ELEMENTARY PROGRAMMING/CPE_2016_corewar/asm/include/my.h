/*
** my.h for  in /home/charliebegood/delivery/CPool_Day09/lib/my
**
** Made by Charles AUBERT
** Login   <charliebegood@epitech.net>
**
** Started on  Thu Oct 13 08:19:29 2016 Charles AUBERT
** Last update Sat Mar 25 17:22:36 2017 Charles Aubert
*/

#include <stdarg.h>

#ifndef READ_SIZE
# define READ_SIZE 1
#endif /* !READ_SIZE */
#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
int	my_putchar(char c);
int	my_putchar_list(va_list ap);
int	my_putchar_er(char c, int error);
int	my_putstr(char *str);
int	my_putstr_list(va_list ap);
int	my_putstr_S(va_list ap);
int	my_putstr_er(char *str, int error);
int	my_putnbr(int nbr);
int	my_putnbr_list(va_list ap);
int     my_putnbr_un_list(va_list ap);
int	my_putnbr_b(va_list ap);
int	my_putnbr_long(va_list ap);
int	my_putpercent(va_list ap);
int	my_putaddress(va_list ap);
int	my_putnbr_h_h(va_list ap);
int	my_putnbr_h_l(va_list ap);
int	my_putnbr_o(va_list ap);
int	my_swap(int *a, int *b);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int     get_num(char *str, int i);
float   my_getfloat(char *line);
int     check_res(int result, int is_neg);
int     add_number(char, int);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
char	*my_strcpy(char *dest, char *src, int i2);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_contain(char *s1, char *s2);
int     my_ascii_sort(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
char	*my_strdup(char *src);
int	my_show_wordtab(char **tab);
char    **my_str_to_wordtab(char *str, char *sep);
int	sum_stdarg(int i, int nb, ...);
int	disp_stdarg(char *s, ...);
int	my_printf(char *str, ...);
char	*get_next_line(int fd);
char    *my_strconcat(char *buff, char *str, int fd, int count);
char    *my_concatenate(char *buff, char *save, char *str, int count);
char    *my_full_line(char *str, char *buff, int count, int bytes);
int     my_putstr_in(char *str, int error);
int	free_array_int(int **array, int error);
int	free_array_char(char **array, int error);
int	free_str(char *str, int error);
void	display_array_char(char **array);
void	display_array_int(int **array, int size);
int     size_array_int(int **array);
int     size_array_char(char **array);
char    **sort_array_char(char **array);
char    *join_str_char(char *from, char add);
char    *join_str_str(char *from, char *add);
int     occurence(char *s1, char *s2, int i);
char    *remove_char(char *s, char *r, int flag);
typedef int   (*func)(va_list);

#endif /* !MY_H_ */
