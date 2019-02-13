# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:20:55 by asansyzb          #+#    #+#              #
#    Updated: 2018/11/14 15:40:00 by asansyzb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = libft/libft.a
CFLAGS = -Wall -Werror -Wextra
SRC += fillit.c reader.c solver.c map.c
OBJECT = *.o
HEADER = fillit.h

all: $(NAME)

$(NAME):
	@Make -C libft
	@gcc $(CFLAGS) $(SRC) -I $(HEADER) -L. $(LIB) -o fillit
clean:
	@/bin/rm -f libft/$(OBJECT)
fclean: clean
	@/bin/rm -f $(LIB)
	@/bin/rm -f $(NAME)
re:	fclean all
