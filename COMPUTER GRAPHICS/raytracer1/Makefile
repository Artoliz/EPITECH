##
## Makefile for makefile in /home/descou_c/Graphic/RTV1
## 
## Made by Charles Descoust
## Login   <descou_c@epitech.net>
## 
## Started on  Fri Feb  3 14:16:25 2017 Charles Descoust
## Last update Tue Apr  4 15:54:13 2017 Charles Descoust
##

CC	= gcc

RM	= rm -f

NAME	= raytracer1

SRCS	= main.c \
	  create.c \
	  basic_objs.c \
	  parse_my_file.c \
	  get_next_line.c \
	  linked_list.c \
	  linked_list2.c \
	  basic_pos.c \
	  my_str.c \
	  my_put.c \
	  my_getnbr_float.c \
	  my_put_pixel.c \
	  walk.c \
	  color_ft.c \
	  color2_ft.c \
	  color.c \
	  src/light.c \
	  src/sphere.c \
	  src/plane.c \
	  src/cylinder.c \
	  src/cone.c \
	  src/translate.c \
	  src/rotate.c \
	  src/calc_dir_vector.c \
	  src/utils.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lc_graph_prog -lm -lpthread

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
