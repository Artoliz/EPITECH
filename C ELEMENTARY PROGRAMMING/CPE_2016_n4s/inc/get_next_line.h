/*
** get_next_line.h for get_next_line in /home/Medica31/CPE/CPE_2016_getnextline
** 
** Made by Bryan Medica
** Login   <Medica31@epitech.net>
** 
** Started on  Mon Jan  2 15:55:33 2017 Bryan Medica
** Last update Sun Jun  4 14:39:46 2017 Bryan Medica
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif /* !READ_SIZE */

#define FAIL_READ (-1)
#define NO_LINE (-2)

char *get_next_line(const int fd);
char *my_strdiv(char **src);
char *my_strcat2(char *str2, char *str, int i);
int is_line(char *str);

#endif /* !GET_NEXT_LINE_H_ */
