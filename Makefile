# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:43:11 by ide-dieg          #+#    #+#              #
#    Updated: 2024/05/24 22:33:50 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
		parsing.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		42_Libft/ft_atoi.c \
		42_Libft/ft_split.c \

all: $(NAME)

$(NAME)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
