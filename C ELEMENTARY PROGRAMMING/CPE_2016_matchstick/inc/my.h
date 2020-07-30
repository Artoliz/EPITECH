/*
** my.h for my in /home/descou_c/CPE/matchstick/inc
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Sat Feb 11 11:22:40 2017 Charles Descoust
** Last update Wed Feb 22 14:49:38 2017 Charles Descoust
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include "get_next_line.h"

int	mult_mod(char, int);
int	str_len(char*);
int	transfo_ft(char*, int, int, int);
int	neg_ft(int, char*);
int	my_getnbr(char*);
void	my_putchar(char);
int	my_strisnum(char*);
void	my_putstr(char*);
int	my_strlen(char*);
int	my_put_nbr(int);
int	my_strcmp(char*, char*);
int	my_putstr_err(char*);
char	*add_line(char*, int);
char	**create_map(int);
void	aff_stars(int);
void	aff_map(char**, int);
int	aff_play(char*, int, int);
int	game(char**, int, int);
char	*my_loose(char**);
char	**update_map(char**, int, int);
int	if_exist(char**, int, int);
char	**user_turn(char**, int, int);
char	**ia_turn(char**, int, int);
int	ia_turn2(char**, int, int*, int);
int	ia_turn3(char**, int, int*, int);
int	ia_turn4(char**, int, int*, int);
int	*count_matches(char**, int*, int);
int	total_matches(int*, int);
int	find_line(char**, int);
int	check(char**, int);
int	find_match(char**, int, int);

#endif /* !MY_H_ */
