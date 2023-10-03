# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouya <obouya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 23:29:55 by mbachar           #+#    #+#              #
#    Updated: 2023/10/03 22:28:25 by obouya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CUB3D		= 	cub3D
LIBFT		=	./libft/libft.a
SRC			= 	./movements/draw.c \
				./movements/move_stop.c \
				./movements/move_stop_norm.c \
				./movements/rad_deg_con.c \
				./parsing/config.c \
				./parsing/map.c \
				./parsing/norm.c \
				./parsing/parsing.c \
				./parsing/scene.c \
				./parsing/tools.c \
				./parsing/tweaked_funcs.c \
				./parsing/utils.c \
				./rays/check_horizental.c \
				./rays/check_vertical.c \
				./rays/rendering_walls.c \
				./rays/rendering_walls2.c \
				./rays/wall.c \
				cub3D.c \
				cub3d_utils1.c \
				cub3d_utils2.c \
				cub3d_utils3.c

INCLUDE		= 	cub3D.h
CC			= 	cc
OBJ			= 	$(SRC:.c=.o)
CFLAGS		= 	-Wall -Wextra -Werror #-g -fsanitize=address

all : $(CUB3D)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(CUB3D): $(OBJ)
	cd ./libft && make
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(CUB3D) $(LIBFT)

clean :
	cd ./libft && make clean
	rm -fr $(OBJ)

fclean :
	cd ./libft && make fclean
	rm -fr $(CUB3D)
	rm -fr $(OBJ)

re : fclean all

.PHONY : re fclean clean