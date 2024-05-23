# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:43:11 by ide-dieg          #+#    #+#              #
#    Updated: 2024/05/23 23:16:53 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		parsing.c \
		/42_libft/ft_atoi.c \
		/42_libft/ft_isdigit.c \
		/42_libft/ft_split.c \
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re