/*
** my_printf.h for my_printf.h in /home/descou_c/PSU/PSU_2016_my_printf/include
** 
** Made by Charles Descoust
** Login   <descou_c@epitech.net>
** 
** Started on  Tue Nov  8 15:07:48 2016 Charles Descoust
** Last update Fri Dec  9 18:25:38 2016 Charles Descoust
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>

#define ERROR	"error"

typedef	struct	s_ptr_ft
{
	char	a;
	int	(*ft)(va_list);
}		t_ptr_ft;

int	b_ft(va_list);
int	p_ft(va_list);
int	o_ft(va_list);
int	u_ft(va_list);
int	d_ft(va_list);
int	i_ft(va_list);
int	x_ft(va_list);
int	X_ft(va_list);
int	s_ft(va_list);
int	S_ft(va_list);
int	c_ft(va_list);
int	conv_indic_ft(char*, va_list, t_ptr_ft*);
int	my_printf(char*, ...);
int	my_putstr_err(char*);
int	put_str_and_octal(unsigned char*);
int	while_ptr_ft(char*, int, va_list, t_ptr_ft*);

#endif /* !MY_PRINTF_H_ */
