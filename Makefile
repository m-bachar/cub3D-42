# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouya <obouya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 23:29:55 by mbachar           #+#    #+#              #
#    Updated: 2023/09/30 19:07:25 by obouya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CUB3D		= 	cub3D
LIBFT		=	./libft/libft.a
SRC			= 	./movements/draw.c \
				./movements/move_stop.c \
				./movements/rad_deg_con.c \
				./parsing/config.c \
				./parsing/map.c \
				./parsing/parsing.c \
				./parsing/scene.c \
				./parsing/tools.c \
				./parsing/tweaked_funcs.c \
				./parsing/utils.c \
				./parsing/xpm_files.c \
				./rays/check_horizental.c \
				./rays/check_vertical.c \
				./rays/rendering_walls.c \
				./rays/wall.c \
				cub3D.c

INCLUDE		= 	cub3D.h
CC			= 	cc -Ofast
OBJ			= 	$(SRC:.c=.o)
CFLAGS		= 	-Wall -Wextra -Werror -g -fsanitize=address

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