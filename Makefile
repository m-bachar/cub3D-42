# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benito <benito@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 23:29:55 by mbachar           #+#    #+#              #
#    Updated: 2023/09/04 22:54:36 by benito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CUB3D		= 	cub3D
LIBFT		=	./libft/libft.a
SRC			= 	cub3D.c \
				./parsing/config.c \
				./parsing/map.c \
				./parsing/parsing.c \
				./parsing/scene.c \
				./parsing/tools.c \
				./parsing/tweaked_funcs.c \
				./parsing/utils.c

INCLUDE		= 	cub3D.h
CC			= 	cc
OBJ			= 	$(SRC:.c=.o)
CFLAGS		= 	-Wall -Wextra -Werror #-g -fsanitize=address

all : $(CUB3D)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(CUB3D): $(OBJ)
	cd ./libft && make
	$(CC) $(CFLAGS) $(OBJ) -o $(CUB3D) $(LIBFT)

clean :
	cd ./libft && make clean
	rm -fr $(OBJ)

fclean :
	cd ./libft && make fclean
	rm -fr $(CUB3D)
	rm -fr $(OBJ)

re : fclean all

.PHONY : re fclean clean