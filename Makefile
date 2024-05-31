# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:43:11 by ide-dieg          #+#    #+#              #
#    Updated: 2024/05/31 17:44:42 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = -rcs

SRC =	push_swap.c \
		parsing.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \

all: libft

clean: libft_fclean



libft:
	make -C 42_Libft

libft_fclean:
	make fclean -C 42_Libft

push_swap: $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
