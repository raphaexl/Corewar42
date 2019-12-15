# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchahid <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 00:58:49 by kchahid           #+#    #+#              #
#    Updated: 2019/07/11 00:58:51 by kchahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	case_double.c display_float.c case_long_double.c display_char.c\
		display_decimal.c display_hex_integer.c display_octal_integer.c \
		display_pointer_hex.c display_string.c display_u_decimal.c ft_printf.c \
		ieee.c init_all.c init_string_float.c new_libc_function.c op_string.c \
		other_display.c parse.c tools_float.c tools.c type_stdarg.c \
		increase_float.c display_f.c \
		libft/ft_atoi.c libft/ft_bzero.c \
		libft/ft_find_len.c libft/ft_isalnum.c libft/ft_isalpha.c \
		libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
		libft/ft_issplit.c libft/ft_itoa.c libft/ft_itoa_base.c \
		libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c \
		libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_memalloc.c libft/ft_memccpy.c \
		libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c \
		libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c \
		libft/ft_putendl_fd.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putstr.c \
		libft/ft_putstr_fd.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c \
		libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c \
		libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c \
		libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c \
		libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strnequ.c \
		libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strsplit.c \
		libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c libft/ft_tolower.c libft/ft_toupper.c

OBJ = case_double.o case_long_double.o display_char.o display_decimal.o display_f.o display_float.o \
display_hex_integer.o display_octal_integer.o display_pointer_hex.o display_string.o display_u_decimal.o \
ft_atoi.o ft_bzero.o ft_find_len.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_issplit.o \
ft_itoa.o ft_itoa_base.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_memalloc.o \
ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_printf.o \
ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o \
ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o \
ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o \
ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o \
ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o ieee.o increase_float.o init_all.o \
init_string_float.o new_libc_function.o op_string.o other_display.o parse.o tools.o tools_float.o type_stdarg.o

all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	

.PHONY :clean fclean

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
