# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleger <gleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/26 11:20:41 by gleger            #+#    #+#              #
#    Updated: 2015/05/02 10:41:48 by gleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = arkanoid

HEADERS = -I libft/ -I ./glfw/include/glfw/

LIBFT = libft/libft.a

SOURCES = main.c \

OBJECTS = $(SOURCES:.c=.o)

HFILE = ./glfw/include/glfw/glfw3.h

FLAGS = -g -Wall -Wextra -Werror -O3

GITSUB = glfw/src/libglfw3.a

GLFW = -Lglfw/src -lglfw3 -framework glut -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

CC	=	clang

all: $(GITSUB) $(NAME)

$(GITSUB):
	@git submodule update --init
	@cmake -B./glfw -H./glfw
	@make -C ./glfw

$(NAME): $(OBJECTS) $(HFILE)
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	$(CC) $(FLAGS) $(GLFW) -o $@ $(OBJECTS)
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

%.o:		%.c $(HPP)
	@echo "\033[1;36;m[Compiling $<]\t\033[0m: " | tr -d '\n'
	$(CC) -c $< $(HEADERS)

clean:
	@echo "\033[0;33;m[Cleaning glfw]\033[0m"
	@make -C ./glfw clean
	@echo "\033[0;33;m[Cleaning objects]\033[0m"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "\033[0;31;m[Deleting glfw]\033[0m"
	@rm -rf glfw
	@echo "\033[0;31;m[Deleting $(NAME)]\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re