# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 17:42:44 by ebatchas          #+#    #+#              #
#    Updated: 2019/12/13 13:06:20 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME = asm
COREWAR_NAME = corewar

CC = gcc
FLAGS =  -Wall -Werror -Wextra -O3

# Libraries and Includes

ASM_LIBRARIES = -lftprintf -L$(FT_PRINTF_DIRECTORY)
ASM_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

COREWAR_LIBRARIES = -lncurses -lftprintf -L$(FT_PRINTF_DIRECTORY)
COREWAR_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./ft_printf/libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

FT_PRINTF = $(FT_PRINTF_DIRECTORY)libftprintf.a
FT_PRINTF_DIRECTORY = ./ft_printf/
FT_PRINTF_HEADERS = $(FT_PRINTF_DIRECTORY)includes/

# Headers

HEADERS_DIRECTORY = ./incs/

# asm

ASM_HEADERS_LIST = asm_op.h assembler.h
ASM_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(ASM_HEADERS_LIST))

# corewar

COREWAR_HEADERS_LIST = vm_op.h vm.h

COREWAR_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(COREWAR_HEADERS_LIST))

# Sources

# asm

ASM_SOURCES_DIRECTORY = ./srcs/asm/

ASM_SOURCES_LIST = asmain.c fragmentation.c lable.c name_comment.c op.c pars_dir.c pars_indir.c\
				   pars_reg.c parser.c prnt_errors.c store_inst_params.c take_token.c tools0.c\
				   tools1.c typecode.c write_execode.c write_header.c 

ASM_SOURCES = $(addprefix $(ASM_SOURCES_DIRECTORY), $(ASM_SOURCES_LIST))

# corewar

COREWAR_SOURCES_DIRECTORY = ./srcs/corewar/
COREWAR_SOURCES_LIST =	 main.c vm.c parse.c parse_player.c parse_read.c parse_tools.c parse_cmp.c print.c log.c\
						 swap_player.c clash.c exec_op.c ft_itoa_base_u.c skip_byte.c tool_arg.c value_arg.c \
						 op_ldi_lldi.c  op_live.c op_st.c check_and_kill.c op_add_sub.c op_sti.c op_aff.c\
						 op_zjmp.c tools.c copy_fork_lfork.c op_and_or_xor.c op_fork_lfork.c op_ld_lld.c\
						 errors.c free.c

COREWAR_SOURCES = $(addprefix $(COREWAR_SOURCES_DIRECTORY), $(COREWAR_SOURCES_LIST))


COREWAR_VS_SOURCES_DIRECTORY = $(COREWAR_SOURCES_DIRECTORY)visu/
COREWAR_VS_SOURCES_LIST = vs.c vs2.c vs3.c vs4.c vs5.c vs6.c vs7.c

COREWAR_VS_SOURCES = $(addprefix $(COREWAR_VS_SOURCES_DIRECTORY), $(COREWAR_VS_SOURCES_LIST))

# Objects

OBJECTS_DIRECTORY = ./objs/

# asm

ASM_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)asm/
ASM_OBJECTS_LIST = $(patsubst %.c, %.o, $(ASM_SOURCES_LIST))
ASM_OBJECTS	= $(addprefix $(ASM_OBJECTS_DIRECTORY), $(ASM_OBJECTS_LIST))

# corewar

COREWAR_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)corewar/
COREWAR_OBJECTS_LIST = $(patsubst %.c, %.o, $(COREWAR_SOURCES_LIST))
COREWAR_OBJECTS	= $(addprefix $(COREWAR_OBJECTS_DIRECTORY), $(COREWAR_OBJECTS_LIST))

COREWAR_VS_OBJECTS_DIRECTORY = $(COREWAR_OBJECTS_DIRECTORY)visu/
COREWAR_VS_OBJECTS_LIST = $(patsubst %.c, %.o, $(COREWAR_VS_SOURCES_LIST))
COREWAR_VS_OBJECTS	= $(addprefix $(COREWAR_VS_OBJECTS_DIRECTORY), $(COREWAR_VS_OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(COREWAR_NAME) $(ASM_NAME)

$(COREWAR_NAME): $(FT_PRINTF) $(COREWAR_OBJECTS_DIRECTORY) $(COREWAR_OP_OBJECTS_DIRECTORY) $(COREWAR_VS_OBJECTS_DIRECTORY) $(COREWAR_OBJECTS) $(COREWAR_OP_OBJECTS) $(COREWAR_VS_OBJECTS)
	@$(CC) $(FLAGS) $(COREWAR_LIBRARIES) $(COREWAR_INCLUDES) $(COREWAR_OBJECTS) $(COREWAR_OP_OBJECTS) $(COREWAR_VS_OBJECTS) -o $(COREWAR_NAME)
	@echo "\n$(COREWAR_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(COREWAR_NAME): $(GREEN)$(COREWAR_NAME) was created$(RESET)"

$(ASM_NAME): $(FT_PRINTF) $(ASM_OBJECTS_DIRECTORY) $(ASM_OBJECTS)
	@$(CC) $(FLAGS) $(ASM_LIBRARIES) $(ASM_INCLUDES) $(ASM_OBJECTS) -o $(ASM_NAME)
	@echo "\n$(COREWAR_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(COREWAR_NAME): $(GREEN)$(ASM_NAME) was created$(RESET)"

$(COREWAR_OBJECTS_DIRECTORY):
	@mkdir -p $(COREWAR_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(COREWAR_OBJECTS_DIRECTORY) was created$(RESET)"

$(COREWAR_VS_OBJECTS_DIRECTORY):
	@mkdir -p $(COREWAR_VS_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(COREWAR_VS_OBJECTS_DIRECTORY) was created$(RESET)"

$(ASM_OBJECTS_DIRECTORY):
	@mkdir -p $(ASM_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(ASM_OBJECTS_DIRECTORY) was created$(RESET)"

$(COREWAR_OBJECTS_DIRECTORY)%.o : $(COREWAR_SOURCES_DIRECTORY)%.c $(COREWAR_HEADERS)
	@$(CC) $(FLAGS) -c $(COREWAR_INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(ASM_OBJECTS_DIRECTORY)%.o : $(ASM_SOURCES_DIRECTORY)%.c $(ASM_HEADERS)
	@$(CC) $(FLAGS) -c $(ASM_INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(FT_PRINTF):
	@echo "$(COREWAR_NAME): $(GREEN)Creating $(FT_PRINTF)...$(RESET)"
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY)

clean:
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(COREWAR_NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) fclean
	@echo "$(COREWAR_NAME): $(RED)$(FT_PRINTF) was deleted$(RESET)"
	@rm -f $(ASM_NAME)
	@echo "$(COREWAR_NAME): $(RED)$(ASM_NAME) was deleted$(RESET)"
	@rm -f $(COREWAR_NAME)
	@echo "$(COREWAR_NAME): $(RED)$(COREWAR_NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

norme:
	norminette $(ASM_SOURCES_DIRECTORY)/*.c
	norminette $(COREWAR_SOURCES_DIRECTORY)/*.c
	norminette $(COREWAR_VS_SOURCES_DIRECTORY)/*.c
	norminette $(HEADERS_DIRECTORY)/*.h
