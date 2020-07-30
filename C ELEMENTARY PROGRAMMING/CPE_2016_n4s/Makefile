##
## Makefile for makefile in /home/descou_c/CPE/CPE_2016_n4s
## 
## Made by Charles Descoust
## Login   <descou_c@epitech.net>
## 
## Started on  Mon May  1 14:35:15 2017 Charles Descoust
## Last update Sun Jun  4 15:57:17 2017 Charles Descoust
##

CC	= gcc

RM	= rm -f

NAME	= ai

SRCS	= main.c \
	  aff.c \
	  get_next_line.c \
	  string.c \
	  my_split.c \
	  getnbr.c \
	  getfloat.c \
	  float_to_str.c \
	  speed.c \
	  write_command.c \
	  move_wheels.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
