# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:01:53 by asansyzb          #+#    #+#              #
#    Updated: 2018/11/08 22:02:04 by asansyzb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SRC += ft_lstadd.c ft_lstdel.c ft_lstiter.c ft_lstdelone.c
SRC += ft_lstmap.c ft_lstnew.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c
SRC += ft_putchar_fd.c ft_putnbr.c ft_putendl.c ft_putchar.c ft_itoa.c
SRC += ft_strsplit.c ft_strtrim.c ft_strjoin.c ft_strsub.c ft_strnequ.c
SRC += ft_strequ.c ft_strmapi.c ft_strmap.c ft_striteri.c ft_striter.c
SRC += ft_strclr.c ft_strdel.c ft_memdel.c ft_strnew.c ft_memalloc.c ft_atoi.c
SRC += ft_isprint.c ft_memset.c ft_strdup.c ft_strnstr.c ft_bzero.c
SRC += ft_memccpy.c ft_putstr.c ft_strlcat.c ft_strrchr.c ft_isalnum.c
SRC += ft_memchr.c ft_strcat.c ft_strlen.c ft_strstr.c ft_isalpha.c ft_memcmp.c
SRC += ft_strchr.c ft_strncat.c ft_tolower.c ft_isascii.c ft_memcpy.c
SRC += ft_strcmp.c ft_strncmp.c ft_toupper.c ft_isdigit.c ft_memmove.c
SRC += ft_strcpy.c ft_strncpy.c ft_strupd.c ft_strndup.c ft_min.c ft_max.c
SRC += ft_lstaddtail.c get_next_line.c

OBJECT = *.o
HEADER = /includes/libft.h
all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
clean:
	@/bin/rm -f $(OBJECT)
fclean: clean
	@/bin/rm -f $(NAME)
re:	fclean all
