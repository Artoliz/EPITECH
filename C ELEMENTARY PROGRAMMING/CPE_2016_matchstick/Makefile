##
## Makefile for makefile in /home/descou_c/CPE/matchstick
## 
## Made by Charles Descoust
## Login   <descou_c@epitech.net>
## 
## Started on  Sat Feb 11 11:20:45 2017 Charles Descoust
## Last update Wed Feb 22 11:05:36 2017 Charles Descoust
##

CC	= gcc

RM	= rm -f

NAME	= matchstick

SRCS	= main.c \
	  get_next_line.c \
	  my_aff.c \
	  my_getnbr.c \
	  my_str.c \
	  my_str2.c \
	  map.c \
	  game.c \
	  user.c \
	  ia.c \
	  ia2.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
