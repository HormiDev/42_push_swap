# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:43:11 by ide-dieg          #+#    #+#              #
#    Updated: 2024/06/04 13:32:17 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB_NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = -rcs

SRC =	main.c \
		ft_push_swap_fb.c \
		ft_push_swap_v1.c \
		ft_push_swap_v2.c \
		fts_t_instructions.c \
		fts_t_instructions2.c \
		fts_t_push_swap.c \
		fts_t_stack.c \
		fts_t_stack2.c \
		input.c \
		parsing.c \
		push_swap_utils.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \

all: libft push_swap

clean: libft_fclean

fclean: clean
	rm -f $(NAME)

libft:
	make -C 42_Libft

libft_fclean:
	make fclean -C 42_Libft

push_swap:
	$(CC) $(CFLAGS) $(SRC) 42_Libft/libft.a -o $(NAME)

re: fclean all
