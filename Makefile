# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkremen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 18:15:35 by vkremen           #+#    #+#              #
#    Updated: 2019/01/12 18:57:17 by vkremen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vkremen.filler

FLAGS = -Wall -Werror -Wextra

SRC = 	./sources/main.c\
		./sources/checking.c\
		./sources/parcing_map.c\
		./sources/algorithm.c\
		./sources/fill_cp_map.c\
		./sources/change_type.c\
		./sources/help_func.c\

OB = $(SRC:%.c=%.o) 

all: $(NAME)

%.o:%.c
	@gcc -c $(FLAGS) $< -o $@

$(NAME): $(OB)
	@make -C libft
	@gcc $(OB) libft/libft.a -o $(NAME)

clean: 
	@make clean -C libft
	@rm -f $(OB)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
