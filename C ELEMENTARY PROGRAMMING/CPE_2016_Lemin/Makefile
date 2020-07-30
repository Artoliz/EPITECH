##
## Makefile for  in /home/charliebegood/delivery/ELEMENTARY_Prog/CPE_2016_pushswap
##
## Made by Charles AUBERT
## Login   <charliebegood@epitech.net>
##
## Started on  Wed Nov 16 17:27:38 2016 Charles AUBERT
## Last update Fri Apr 21 10:24:41 2017 Bastien LECUSSAN
##

SRC	=	main.c \
		./tools/list.c \
		./tools/free.c \
		./path/short.c \
		./path/short2.c \
		./parsing/file.c \
		./parsing/check.c \
		./parsing/summit.c \
		./parsing/link.c \
		./display/display.c \
		./display/display_start.c \
		./algo/algo_start.c \
		./algo/algo.c \
		mv_ants/mv_ants.c \
		mv_ants/mv_ants_to_next_summits.c \
		mv_ants/put_ant.c \
		mv_ants/my_memcpy.c \
		mv_ants/my_memdup.c \
		mv_ants/link_dup.c \
		mv_ants/free.c		\
		mv_ants/kill_ants.c	\

OBJ	= $(SRC:.c=.o)

CFLAGS 	+= -W -Wall -g -Wextra

NAME	= lem_in

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all
