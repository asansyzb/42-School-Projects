# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:20:55 by asansyzb          #+#    #+#              #
#    Updated: 2019/02/13 02:07:38 by asansyzb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB = libft/libft.a
CFLAGS = -Wall -Werror -Wextra
SRC += srcs/main.c srcs/reader.c srcs/draw.c srcs/color.c
SRC += srcs/helper.c srcs/get_color.c srcs/key_rotate.c
SRC += srcs/key_landschaft.c srcs/keyhook.c srcs/key_zoom.c srcs/key_move.c
OBJECT = *.o
HEADER = includes/fdf.h
MLX = -L ./minilibx -lmlx -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME):
	@Make -C minilibx
	@Make -C libft
	@gcc -fsanitize=address $(CFLAGS) $(SRC) -I $(HEADER) -L. $(MLX) $(LIB) -o $(NAME)
clean:
	@Make -C libft clean
	@Make -C minilibx clean
fclean: clean
	@Make -C libft fclean
	@/bin/rm -f $(NAME)
re:	fclean all
