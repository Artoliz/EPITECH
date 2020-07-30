/*
** file.h for file in /home/descou_c/Graphic/wolf3d/inc
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Wed Dec 21 15:15:27 2016 Charles Descoust
** Last update Mon Jan 23 13:39:23 2017 Charles Descoust
*/

#ifndef FILE_H_
# define FILE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define READ_SIZE (100000)

typedef struct	s_map
{
  int	**map;
  int	lines;
  int	chars;
} t_map;

t_map	create_map(char*);
int	**my_map(char*, int, int);
int	count_lines(char*);
int	count_chars(char*);
t_map	add_info(int**, int, int);

#endif /* !FILE_H_ */
