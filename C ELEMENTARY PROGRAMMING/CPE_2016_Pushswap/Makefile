##
## Makefile for makefile in /home/descou_c/CPE/CPE_2016_Pushswap
## 
## Made by Charles Descoust
## Login   <descou_c@epitech.net>
## 
## Started on  Wed Nov 16 13:26:58 2016 Charles Descoust
## Last update Wed Nov 16 13:28:03 2016 Charles Descoust
##

CC	= gcc

RM	= rm -f

NAME	= push_swap

SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
