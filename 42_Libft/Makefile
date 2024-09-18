# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 16:43:30 by ide-dieg          #+#    #+#              #
#    Updated: 2024/09/18 05:03:45 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del archivo de salida
NAME = libft.a

# Compilador
CC = cc

# Archivador
AR = ar

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror
# -g3 -fsanitize=address

# Opciones de archivado
ARFLAGS = -rcs

# Archivos fuente
SRC =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_strncmp.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

# Archivos fuente para la parte bonus
SRC_BONUS =	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \

SRC_GNL =	get_next_line.c \
			get_next_line_utils.c \

# Objetos generados a partir de los archivos fuente
OBJ = $(SRC:.c=.o)

# Objetos generados a partir de los archivos fuente de la parte bonus
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Objetos generados a partir de los archivos fuente de get_next_line
OBJ_GNL = $(SRC_GNL:.c=.o)

# Regla para construir el archivo de salida
all: build gnl

build: $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)

# Regla para compilar los archivos fuente
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Regla para construir la parte bonus
bonus: $(OBJ_BONUS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ_BONUS)
	@ranlib $(NAME)

# Regla para construir get_next_line
gnl: $(OBJ_GNL)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ_GNL)
	@ranlib $(NAME)

# Regla para limpiar los archivos objeto
clean:


# Regla para limpiar los archivos objeto y el archivo de salida
fclean:
	@rm -f $(OBJ) $(OBJ_BONUS) $(NAME) $(NAME_BONUS)

# Regla para reconstruir el proyecto desde cero
re: fclean all
