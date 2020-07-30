##
## Makefile for makefile in /home/descou_c/CPE/CPE_2016_corewar
## 
## Made by Charles Descoust
## Login   <descou_c@epitech.net>
## 
## Started on  Mon Feb 27 09:29:16 2017 Charles Descoust
## Last update Sun Apr  2 15:47:06 2017 Charles Descoust
##

CC	= gcc

RM	= rm -f

NAME1	= asm/asm

NAME2	= corewar/corewar

SRCS1   = 	asm/tab.c \
                asm/check/aff.c \
                asm/check/args.c \
                asm/main.c \
                asm/free.c \
                asm/list.c \
                asm/file.c \
                asm/check/get_label.c \
                asm/check/check_aff.c \
                asm/header_end.c \
                asm/check/check_label.c \
                asm/set_pos_label.c \
                asm/write/write_file_cor.c \
                asm/write/write_typeparam.c \
                asm/write/write_file_line.c \
		asm/write/write_direct_index.c \
                asm/binar_to_decimal.c \
                asm/usefull_functions.c \
                asm/check/and_or_xor_zjmp_ldi.c \
                asm/check/live_ld_st_add_subb.c \
                asm/check/check_ld_st_and_or_add.c \
                asm/check/sti_fork_lld_lldi_lfork.c \
                asm/check/check_com_ext_ign_jmp_line.c \
                asm/dispens_write_header_content.c \
                asm/check/check_label_xor_ldi_lld_lldi.c \
                asm/check/check_end_live_fork_lfork_sti.c \
                asm/double_chain_and_distribute_work.c \

SRCS2	= corewar/main.c \
	  corewar/args.c \
	  corewar/files.c \
	  corewar/parameters.c \
	  corewar/champions.c \
	  corewar/prog_number.c \
	  corewar/str.c \
	  corewar/utils_args.c \
	  corewar/utils_corewar.c \
	  corewar/initialize.c \
	  corewar/corewar.c \
	  corewar/champ_in_map.c \
	  corewar/instructions.c \
	  corewar/instructions_2.c \
	  corewar/instructions_3.c \
	  corewar/instructions_4.c \
	  corewar/destroy.c \
	  corewar/aff_dump.c

OBJS1	= $(SRCS1:.c=.o)

OBJS2	= $(SRCS2:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS1) $(OBJS2)
	make -C ./lib/my/
	$(CC) -o $(NAME1) $(OBJS1) -L./lib/my/ -lmy
	$(CC) -o $(NAME2) $(OBJS2) -L./lib/my/ -lmy

clean:
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)
	make clean -C ./lib/my/

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)
	make fclean -C ./lib/my/

re: fclean all
