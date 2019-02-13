# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 18:27:06 by vmuradia          #+#    #+#              #
#    Updated: 2019/01/03 21:09:15 by vmuradia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3 -Ofast -march=native -flto=full
SRC += srcs/main.c srcs/move.c srcs/init.c srcs/image.c srcs/control.c
SRC += srcs/drawing.c srcs/game.c srcs/minimap.c srcs/sprite.c srcs/helper.c
HEADERS = wolf3d.h
LIBFT = libft/libft.a
MINILIBX = ./minilibx -lmlx -framework OpenGL -framework AppKit
OBJ=*.o
GREEN = \033[1;32m

all : $(NAME)

$(NAME) :
		Make -C libft
		Make -C minilibx
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L. $(LIBFT) -L $(MINILIBX)

		@echo "$(GREEN)Project successfully compiled"

clean :
		make clean -C libft
		make clean -C minilibx
		-rm -f $(OBJ)
		@echo "$(GREEN)All object files are deleted"

fclean : clean
		make fclean -C libft
		-rm -f $(NAME)
		@echo "$(GREEN)Cleaned everything"

re : fclean all

.PHONY : clean fclean re