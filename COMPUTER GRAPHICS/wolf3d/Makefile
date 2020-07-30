##
## Makefile for makefile in /home/descou_c/Graphic/wolf3d
## 
## Made by Charles Descoust
## Login   <descou_c@epitech.net>
## 
## Started on  Wed Dec 21 14:29:23 2016 Charles Descoust
## Last update Thu Jan 12 11:31:53 2017 Charles Descoust
##

CC	= gcc

RM	= rm -f

NAME	= wolf3d

SRCS	= main.c \
	  my_create.c \
	  my_framebuffer_create.c \
	  window.c \
	  my_aff.c \
	  my_wall.c \
	  file.c \
	  count.c \
	  src/my_put_pixel.c \
	  src/my_draw_line.c \
	  src/move_forward.c \
	  src/raycast.c \
	  src/raycast_part2.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)  -lc_graph_prog -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
