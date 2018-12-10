# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeyret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:35:55 by apeyret           #+#    #+#              #
#    Updated: 2018/12/07 15:39:11 by apeyret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I .
SRC = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memalloc.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strcmp.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strsplit.c \
	ft_strtrim.c \
	ft_strsub.c \
	ft_tolower.c \
	ft_lstnew.c \
	ft_toupper.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_exit.c \
	ft_puttab.c \
	ft_runtab.c \
	ft_strccount.c \
	ft_intlen.c \
	ft_strndup.c \
	ft_strlower.c \
	ft_cisin.c

OBJ = $(SRC:.c=.o) 

all: $(NAME)

%.o: %.c
	@printf "\x1B[0;32m[Libft] Compilation [o.] \r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\x1B[0;32m[Libft] Compilation [.o] \r"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "\x1B[0;32m[Libft] Compilation [OK]\n"

clean:
	@/bin/rm -f $(OBJ)
	@printf "\033[0;31m[Libft] Deleted *.o\n"

nofclean:
	@/bin/rm -f $(NAME)
	@printf "\033[0;31m[Libft] Deleted libft.a\n"

fclean: nofclean clean

re: fclean all
