##
## Makefile for  in /home/charliebegood/delivery/CPool_Day10
##
## Made by Charles AUBERT
## Login   <charliebegood@epitech.net>
##
## Started on  Fri Oct 14 07:59:46 2016 Charles AUBERT
## Last update Tue Mar 21 17:33:39 2017 Charles Aubert
##

SRC	=	my_show_wordtab.c \
		getnbr.c \
		getfloat.c \
		my_square_root.c \
		my_strlowcase.c	\
		my_strcapitalize.c \
		my_strncat.c \
		my_power_rec.c \
		my_strncpy.c \
		my_putchar.c \
		my_putpercent.c \
		my_putaddress.c \
		my_strdup.c \
		my_str_to_wordtab.c \
		my_sort_tab.c \
		my_putstr.c \
		my_strupcase.c \
		my_swap.c \
		my_showmem.c \
		sum_stdarg.c \
		disp_stdarg.c \
		printf.c \
		get_next_line.c \
		my_putstr_S.c \
		free.c \
		display.c \
		string.c \
		size.c \
		number.c \
		compare.c \
		putnbr.c \
		putnbr2.c \
		putnbr3.c \
		is.c \
		remove.c

OBJ	= $(SRC:.c=.o)

CFLAGS  += -g

NAME	= libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
