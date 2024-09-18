# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddiaz-to <ddiaz-to@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 10:42:59 by ddiaz-to          #+#    #+#              #
#    Updated: 2024/09/11 10:42:59 by ddiaz-to         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ! VARIABLES

# NOMBRE DEL PROGRAMA
NAME = pipex

# COMPILADOR
CC = gcc

# FLAGS
CFLAGS = -Wall -Wextra -Werror

# COMANDO PARA ELIMINAR ARCHIVOS
RM = rm -f

# COMANDO PARA CREAR ARCHIVO BIBLIOTECA
LIB = ar rcs

# FUENTE DE LOS ARCHIVOS A USAR (.c)
SRCS = src/free.c \
			src/ft_functions.c \
			src/ft_split_utils.c \
			src/main.c \
			src/pipex_helpers.c \

# LISTADO DE ARCHIVOS OBJETO YA COMPILADOS
OBJS = $(SRCS:.c=.o)

# ! REGLAS

# REGLA PRINCIPAL QUE SE EJECUTA AL USAR "make"
all: $(NAME)

# REGLA QUE CREA EL EJECUTABLE PIPEX CON LOS ARCHIVOS COMPILADOS
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

#REGLA PARA LIMPÌAR ARCHIVOS COMPILADOS
clean:
	$(RM) $(OBJS)

# REGLA PARA LIMPIAR ARC. COMPILADOS Y EL EJECUTABLE
fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS)

# REGLA QUE LIMPIA Y RECOMPILA TODO
re: fclean all

# VARIABLES NO TRATADAS COMO ARCHIVOS 
.PHONY: all clean fclean re