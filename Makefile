# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeyret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 18:24:48 by apeyret           #+#    #+#              #
#    Updated: 2018/12/10 19:58:30 by apeyret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls 

SRC = main.c \
	  ls_struct.c

CC = gcc

CFLAGS = -I . -I libft/ -Wall -Werror -Wextra 

DEBUG= #-g3 -fsanitize=address

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@printf "\033[0;32m[ft_ls] Compilation [o.]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m[ft_ls] Compilation [.o]\r"

check:
	-@cat $(SRC) | grep ft_strnew		| grep -v "if (\!(" 
	-@cat $(SRC) | grep ft_strdup 	| grep -v "if (\!(" 
	-@cat $(SRC) | grep ft_strndup	| grep -v "if (\!(" 
	-@cat $(SRC) | grep malloc    	| grep -v "if (\!(" 
	-@cat $(SRC) | grep printf		| grep -v ft_printf	| grep -v t_printf
	@norminette $(SRC)

$(NAME): $(OBJ)
	@printf "[ft_ls] Compilation [OK]\n"
	@make -C libft/
	@gcc $(CFLAGS) $(DEBUG) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "\033[0;31m[ft_ls] Deleted *.o\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make nofclean -C libft/
	@printf "\033[0;31D[ft_ls] Deleted ft_printf.a\n"

re: fclean all

.PHONY: all clean fclean re
