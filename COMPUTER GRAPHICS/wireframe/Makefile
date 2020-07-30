##
## Makefile for makefile in /home/descou_c/Graphic/wireframe
## 
## Made by Charles Descoust
## Login   <descou_c@epitech.net>
## 
## Started on  Sun Dec 11 15:30:36 2016 Charles Descoust
## Last update Sun Dec 11 17:19:35 2016 Charles Descoust
##

AR		= ar rc

NAME_LIB        = libmy.a

SRCS_LIB        = my/my_putchar.c \
                  my/my_isneg.c \
                  my/my_put_nbr.c \
                  my/my_swap.c \
                  my/my_putstr.c \
                  my/my_strlen.c \
                  my/my_strcpy.c \
                  my/my_revstr.c \
                  my/my_strstr.c \
                  my/my_strcmp.c \
                  my/my_str_isnum.c \
                  my/my_strcat.c \
                  my/my_getnbr.c \
                  my/my_put_nbr_base.c \
                  my/my_printf.c \
                  my/error_printf.c \
                  my/my_printf_ptr_ft.c \
                  my/my_printf_ptr_ft2.c \
                  my/my_printf_ptr_ft3.c \

OBJS_LIB        = $(SRCS_LIB:.c=.o)

CC		= gcc

RM		= rm -f

CFLAGS		+= -W -Werror -Wextra -Wall

NAME		= wireframe

SRCS		= main.c \
		  bellepou.c \
		  file.c \
		  window.c \
		  my_create.c \
		  my_framebuffer_create.c \
		  src/my_draw_line.c \
		  src/my_put_pixel.c \
		  src/my_parallel_projection.c \
		  src/my_isometric_projection.c \
		  my_aff.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIB)
	$(AR) my/$(NAME_LIB) $(OBJS_LIB)
	$(CC) -o $(NAME) $(OBJS) -Lmy/ -lmy -lc_graph_prog -lm

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_LIB)

fclean: clean
	$(RM) $(NAME)
	$(RM) my/$(NAME_LIB)

re: fclean all
