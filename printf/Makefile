# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:01:53 by asansyzb          #+#    #+#              #
#    Updated: 2018/12/02 22:13:30 by asansyzb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# directories
OBJ_DIR = obj/
SRC_DIR = srcs/
INC_DIR = includes/
LIBFT_DIR = libft/

# complier
CFLAGS = -Wall -Wextra -Werror

# src & obj files
SRC_FILES += flags.c fmt_put.c ft_printf.c handle_floats.c handle_nbr.c
SRC_FILES += helpers.c itoa_base.c print.c handlers.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# libraries
LIBFT = ft

INCLUDES = -I $(LIBFT_DIR)includes/ -I includes/ 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\`ft_printf\` [INFO] Library created"

$(OBJ): $(SRC)
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) $(INCLUDES) -c $^
	@mv -f *.o $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)
	@echo "\`ft_printf\` [INFO] Object folder removed"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)
	@echo "\`ft_printf\` [INFO] Executable removed"

re: fclean all

.PHONY: all clean fclean re $(NAME)