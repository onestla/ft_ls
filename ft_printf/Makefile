# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                                                  #
#                                                     +:+ +:+         +:+      #
#    By: glavigno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:48:50 by glavigno          #+#    #+#              #
#    Updated: 2018/12/10 14:42:45 by apeyret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c \
		pf_base.c \
		pf_ftoa.c \
		pf_len.c \
		pf_options.c \
		pf_parsing.c \
		pf_put.c \
		pf_router.c \
		pf_struct.c \
		pf_utils.c

CC = gcc

CFLAGS = -I libft/ -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@printf "\033[0;32m[Printf] Compilation [o.]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m[Printf] Compilation [.o]\r"

$(NAME): $(OBJ)
	@printf "[Printf] Compilation [OK]\n"
	@make -C libft/
	@ar rc $(NAME) $(OBJ) libft/*.o

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "\033[0;31m[Printf] Deleted *.o\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make nofclean -C libft/
	@printf "\033[0;31D[Printf] Deleted ft_printf.a\n"

re: fclean all

.PHONY: all clean fclean re
