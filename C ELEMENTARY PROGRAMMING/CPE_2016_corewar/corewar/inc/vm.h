/*
** my.h for my in /home/descou_c/CPE/corewar_vm/inc
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Mon Mar 13 13:56:28 2017 Charles Descoust
** Last update Sun Apr  2 15:54:30 2017 Bastien LECUSSAN
*/

#ifndef VM_H_
# define VM_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../lib/my/my.h"

#define IDX_MOD		512
#define MEM_SIZE	(6 * 1024)

#define REG_NUMBER	16

#define CYCLE		((2 * CYCLE_TO_DIE) + 500)

#define CYCLE_TO_DIE	1536
#define CYCLE_DELTA	5
#define NBR_LIVE	40

#define NULL_SIZE	0
#define REG_SIZE	1
#define IND_SIZE	2
#define DIR_SIZE	4

#define NCMP	my_strncmp
#define CMP	my_strcmp
#define LEN	my_strlen

#define PROG_NAME_LENGTH	128
#define	COMMENT_LENGTH		2048

typedef	struct	s_header
{
  int		magic;
  int		pn;
  int		l_a;
  char		prog_name[PROG_NAME_LENGTH + 1];
  int		prog_size;
  char		comment[COMMENT_LENGTH + 1];
  unsigned char	*instru;
}		t_header;

typedef struct  s_var
{
  int   dump;
  int   pn;
  int   la;
  int	cor;
  int	i;
  int	j;
  int	nb_live;
  int	idx_live;
}               t_var;

typedef struct	s_process
{
  int		cycle;
  int		carry;
  int*		reg;
  int		PC;
  t_header*	warrior;
}		t_process;

typedef struct	s_options
{
  char		*name;
  int		(*ft)(char**, int*, t_var*);
  int		(*cp)(t_var*, t_header**, char**);
}		t_options;

typedef struct	s_instructions
{
  unsigned char	code;
  void		(*nst)(int*, t_process, int*, t_var*);
}		t_instru;

typedef struct	s_trash
{
  int		i;
  int		j;
  int		k;
  int		l;
}		t_trash;

void		live_ft(int*, t_process, int*, t_var*);
void		ld_ft(int*, t_process, int*, t_var*);
void	        st_ft(int*, t_process, int*, t_var*);
void		add_ft(int*, t_process, int*, t_var*);
void		sub_ft(int*, t_process, int*, t_var*);
void		and_ft(int*, t_process, int*, t_var*);
void		or_ft(int*, t_process, int*, t_var*);
void		xor_ft(int*, t_process, int*, t_var*);
void		zjmp_ft(int*, t_process, int*, t_var*);
void		ldi_ft(int*, t_process, int*, t_var*);
void		lldi_ft(int*, t_process, int*, t_var*);
void		lfork_ft(int*, t_process, int*, t_var*);
void		sti_ft(int*, t_process, int*, t_var*);
void		lld_ft(int*, t_process, int*, t_var*);
void		fork_ft(int*, t_process, int*, t_var*);
void		aff_ft(int*, t_process, int*, t_var*);
void		exit_error(char*);
int		aff_info(char*);
int		aff_usage(char*);
t_var		init_var();
int		check_help(int, char**);
int		check_dump(char**, int*, t_var*);
int		check_prog_number(char**, int*, t_var*);
int		check_load_address(char**, int*, t_var*);
int		init_dump(t_var*, t_header**, char**);
int		init_address(t_var*, t_header**, char**);
int		init_nb(t_var*, t_header**, char**);
int		init_champion(t_var*, t_header**, char**);
int		check_header_size(t_var*, t_header**, char**);
t_header	*init_champ(t_var);
t_options	*init_tab();
int		what_options(char**, t_options*, int*, t_var*);
int		check_args(int, char**, t_var*);
int		check_files(char*, t_var**);
int		check_param(char**, t_var*, t_header**, t_options*);
int		check_exec_magic(int);
int		add_prog_name(t_header**, int, t_var*);
int		add_comment(t_header**, int, t_var*);
int		add_instructions(t_header**, int, t_var*);
int		add_size(t_header**, int, t_var*);
int		my_copy(t_header**, t_var*, char*, int);
int		get_value(unsigned char*, int);
int		convert(int*, t_process, int);
int		get_size(unsigned char*);
int		calc_puis(unsigned char, unsigned char);
int		add_prog_number(t_header**, t_var*);
int		corewar(t_header*, t_var);
int		*init_registers(int*, int);
t_process	*init_procs(t_header*, t_var);
void		destroy_process_map_tab(t_process*, t_var, int*, t_instru*);
int		*init_map();
t_instru	*init_tab_instru();
int		destroy_champ(t_header*, t_var);
char		*decimal_to_binar(unsigned char);
char		*complete_with_zero(char*);
int		*convert_chain_binar(char*);
int		*add_champ_in_map(t_process*, t_var, int*);
int		check_overlap(t_process*, t_var);
t_process	*sort_champ_by_pn(t_process*, t_var);
void		aff_dump(int*);
int		remove_cycle_delta(t_var*, int*);

#endif /* !VM_H_ */
