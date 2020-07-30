/*
** file.h for file in /home/descou_c/Graphic/wireframe/include
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Dec  5 09:51:23 2016 Charles Descoust
** Last update Sun Dec 11 12:05:10 2016 Charles Descoust
*/

#ifndef FILE_H_
# define FILE_H

#define READ_SIZE	99999

int	**add_to_tab(char*, int**, int);
int	**add_to_line(char*, int**, int, int);
t_tab	check_name_file(char*);
int	count_lines(char*);
int	count_chars_per_line(char*);

#endif /* !FILE_H_ */
