# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 18:08:12 by ebatchas          #+#    #+#              #
#    Updated: 2019/11/25 19:56:42 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

PWD=\"$(shell pwd)\"

SRCDIR = src
OBJDIR = obj
BINDIR = .
HEADDIR = inc

LIBFTDIR=libft
LIBFT_HEADDIR=header
LIBFT = $(LIBFTDIR)/libft.a

DONE_COLOR=\x1b[34;03m
EOC=\033[0m

SRCS_NO_PREFIX = main.c players.c parse_args.c parse_utils.c print.c read.c\
				 read_utils.c core.c arena.c vm.c memory.c carriage.c op.c

INCS_NO_PREFIX  = corewar.h op.h

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))
OBJS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))
INCS = $(addprefix $(HEADDIR)/, $(INCS_NO_PREFIX))

INC = -I $(HEADDIR) -I $(LIBFTDIR)/$(LIBFT_HEADDIR)

CFLAGS=-DPATH=$(PWD) -Wall -Wextra -Werror $(INC)
LDFLAGS= -L $(LIBFTDIR) -lft

NAME=corewar

all:
	make -C $(LIBFTDIR) all
	make $(BINDIR)/$(NAME)

$(LIBFT):
	make -C $(LIBFTDIR) all

$(BINDIR)/$(NAME) : $(OBJS) $(LIBFT)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	@echo "$(DONE_COLOR) $(BINDIR)/$(NAME) compiled successfully !$(EOC)"

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCS)
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@make clean -C $(LIBFTDIR)
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)
	@echo "$(DONE_COLOR) $(BINDIR)/$(NAME) objs successfully removed !$(EOC)"

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -rf $(BINDIR)/$(NAME)
	@echo "$(DONE_COLOR) $(BINDIR)/$(NAME) files successfully removed !$(EOC)"

re: fclean all

norme:
	make norme -C $(LIBFTDIR)
	norminette $(HEADDIR)/*.h
	norminette $(SRCDIR)/*.c

.PHONY: all clean fclean re norme
