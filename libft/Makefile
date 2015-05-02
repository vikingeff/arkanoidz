#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleger <gleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:34:47 by gleger            #+#    #+#              #
#    Updated: 2015/03/03 00:30:02 by gleger           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	libft.a

SRC = 	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		ft_memdel.c ft_memmove.c ft_memset.c ft_bzero.c\
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstlen.c\
		ft_lstnew.c ft_lstrev.c\
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_itoa.c ft_abs.c ft_atoi.c ft_sqrt.c ft_tolower.c ft_toupper.c\
		ft_printf.c ft_putchar.c ft_putchar_fd.c\
		ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
		ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c\
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c\
		ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c\
		ft_strsub.c ft_strtrim.c ft_strdel2.c ft_pow.c ft_swap.c ft_sqrt.c\
		ft_isdigit_char.c ft_isdigit_str.c ft_atoi_double.c ft_check_if_int.c\
		ft_swap_double.c get_next_line.c ft_strjoin_free.c ft_str_multi_join.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	@echo "\033[1;36;m[Compiling Libft]\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -c -Wall -Wextra -Werror $(SRC) -g -I.

clean:
	@echo "\033[0;33;m[Cleaning libft objects]\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[0;31;m[Deleting $(NAME)]\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
