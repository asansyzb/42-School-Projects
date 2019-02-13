# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:20:55 by asansyzb          #+#    #+#              #
#    Updated: 2018/12/22 16:18:59 by asansyzb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIB = libft/libft.a
CFLAGS = -Wall -Werror -Wextra -O3 -Ofast -march=native -flto=full
SRC += srcs/main.c srcs/type.c srcs/draw.c srcs/helpers.c
SRC += srcs/hooks.c srcs/image.c
OBJECT = *.o
HEADER = fdf.h
MLX = -L ./minilibx -lmlx -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME):
	@Make -C minilibx
	@Make -C libft
	@gcc $(CFLAGS) $(SRC) -I $(HEADER) -L. $(MLX) $(LIB) -o $(NAME)
clean:
	@Make -C libft clean
	@Make -C minilibx clean
fclean: clean
	@Make -C libft fclean
	@/bin/rm -f $(NAME)
re:	fclean all
