/*
** n4s.h for n4s in /home/descou_c/CPE/CPE_2016_n4s
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon May  1 14:36:53 2017 Charles Descoust
** Last update Fri Jun  2 17:35:54 2017 Bryan Medica
*/

#ifndef N4S_H_
# define N4S_H_

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "./get_next_line.h"

# define RAY1	3
# define RAY32	34

# define START		"start_simulation\n"
# define STOP		"stop_simulation\n"
# define FORW		"car_forward:"
# define BACK		"car_backwards:"
# define WHEELS		"wheels_dir:"
# define RAY		"get_info_lidar\n"
# define WAIT		"cycle_wait:"
# define INT_MAX	2147483647
# define INFO		"get_info_simtime\n"

# define END		"Track Cleared"

int	put_err(char*);
int	my_strlen(char*);
int	my_strcmp(char*, char*);
int	size_array(char **);
void	my_putnbr(int, int);
void	my_putchar(char, int);

char	**my_split(char*, char*);

int	add_number(char, int);
int	check_res(int, int);
float	my_getfloat(char*);
char	*float_to_string(float);

int	end_of_track(char**);

int	speed(char**);

int	write_command(char*);

int	move_wheels(char**);
int	move_left_and_right(float, char*);

int	*init_mid_vals();

#endif /* N4S_H_ */
