##
## Makefile for makefile in /home/descou_c/Graphic/RTV1
## 
## Made by Charles Descoust
## Login   <descou_c@epitech.net>
## 
## Started on  Fri Feb  3 14:16:25 2017 Charles Descoust
## Last update Sun Apr  2 21:13:02 2017 Amardeilh Guilhem
##

CC	= gcc

RM	= rm -f

NAME	= scroller

SRCS	= src/main.c		\
	  src/my_put_pixel.c	\
	  src/create.c		\
	  src/get_next_line.c	\
	  src/title.c		\
	  src/fade.c		\
	  src/clock.c		\
	  src/fireball.c	\
	  src/squall.c		\
	  src/sky.c		\
	  src/background.c	\
	  src/sprites_load.c	\
	  src/aff_back.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lc_graph_prog_full -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
