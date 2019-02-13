# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:20:55 by asansyzb          #+#    #+#              #
#    Updated: 2018/11/29 00:02:01 by asansyzb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB = libft/libft.a
CFLAGS = -Wall -Werror -Wextra
SRC += main.c reader.c draw.c color.c helper.c get_color.c
SRC += key_rotate.c key_landschaft.c keyhook.c key_zoom.c key_move.c
OBJECT = *.o
HEADER = fdf.h
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
