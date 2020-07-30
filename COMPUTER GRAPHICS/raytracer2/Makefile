##
## Makefile for  in /home/charliebegood/delivery/GRAPHICAL_Prog/raytracer2
##
## Made by Charles Aubert
## Login   <charliebegood@epitech.net>
##
## Started on  Tue May  2 20:56:04 2017 Charles Aubert
## Last update Sun May 28 22:09:28 2017 Charles Descoust
##

CC	= gcc

RM	= rm -f

NAME	= raytracer2

SRCS	= main.c \
	  ./args/env_args.c \
	  file_xml/file_xml.c \
	  file_xml/check.c \
	  file_xml/functions.c \
	  file_xml/get_list_objects.c \
	  file_xml/free_list_objects.c \
	  ./src/hyperboloid1.c \
	  ./src/hyperboloid2.c \
	  ./src/ellipsoid.c \
	  ./src/paraboloid.c \
	  ./src/plane.c \
	  ./src/utils.c \
	  ./src/light.c \
	  ./src/rotate.c \
	  ./src/sphere.c \
	  ./src/cone.c \
	  ./src/solve_strip.c \
	  ./src/moebius.c \
	  ./src/moebius2.c \
	  ./src/cylinder.c \
	  ./src/translate.c \
	  ./src/calc_dir_vector.c \
	  ./src/my_put_pixel.c \
	  ./conf_gen/start.c \
	  ./conf_gen/get_light.c \
	  ./conf_gen/vectors.c \
	  ./win_gen/win.c \
	  ./display/update_screen.c \
	  ./conf_calc/calc.c \
	  ./conf_calc/color.c \
	  ./conf_calc/raytrace.c \
	  ./conf_calc/average.c \
	  rtobj/get_equation_face.c \
	  rtobj/my_obj.c \
	  rtobj/my_raytracer.c \
	  rtobj/vector3f.c \
	  rtobj/window.c \
	  rtobj/point_in_triangle.c \
	  rtobj/parsing/check_file.c \
	  rtobj/parsing/create_list.c \
	  rtobj/parsing/error.c \
	  rtobj/parsing/double_chain.c \
	  rtobj/parsing/face.c \
	  rtobj/parsing/free.c \
	  rtobj/parsing/get_tab_obj.c \
	  rtobj/parsing/get_txture_norm_pos_mtl.c \
	  rtobj/parsing/obj.c \
	  rtobj/parsing/is_float.c \
	  rtobj/parsing/size.c \
	  rtobj/parsing/tab.c \
	  rtobj/parsing/type.c \
	  rtobj/src/calc_dir_vector.c \
	  rtobj/src/color.c \
	  rtobj/src/intersect_face.c \
	  rtobj/src/light.c \
	  rtobj/src/rotate2.c \
	  rtobj/src/rotate.c \
	  rtobj/src/shadow.c \
	  rtobj/parsing/undefine.c \
	  threads/init_fct.c \
          threads/multi_threads.c \
          threads/new_framebuffer.c \


OBJS	= $(SRCS:.c=.o)

LIBS	=  -lc_graph_prog -lm -lpthread -L./lib/my/ -lmy

CFLAGS	+= -W -Wall -Wextra -I./inc

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my/
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

clean:
	$(RM) $(OBJS)
	make clean -C ./lib/my/

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./lib/my/

re: fclean all
