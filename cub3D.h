/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:27 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/13 19:49:24 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./headers/include/MLX42/MLX42.h"
# include <math.h>
# include "./libft/libft.h"

# define BUFFER_SIZE 1

typedef struct cub3D
{
	char		**map;
	char		**config;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x;
	int			y;
	int			xp;
	int			yp;
	//ouss
	int 		size_player;
	int 		turn_directions; // -1 = left , +1 of right (index indiction if we will decrease or increase the angle)
	int 		walk_directions; // -1 = baack , +1 of front,  0 stop
	int 		rotation_angle; //pi/2 initilizing where player looks for 1st time
	int 		speed;//3
	int 		rotation_speed;//3*(pi/180) 3 degress per frame 
}	t_cub3D;

t_cub3D g_cub3d;

		/*	Config.c		*/
void	check_rgb_values(char **cf);
void	count_elements(char **config);
void	parse_c_f(char *cf);
void	check_duplicated(char **config);
void	parse_position(char *position);

		/*	Map.c			*/
void	empty_line(char *map);
void	first_last_lines(char **map);
void	sides(char **map);
void	find_player(char **map);
void	check_surrounding(char **map);
void	check_map_content(char **map);

		/*	Parsing.c		*/
char	*extract_config(char *fullmap);
char	*extract_map(char *fullmap);
void	parse_config(char *config);
void	parse_map(char *map);
void	parsing(char *av);

		/*	Scene.c			*/
void	map_extension(char *av);
char	*map_path(char *map);
char	*read_map(int fd);

		/*	Tools.c			*/
char	**ft_split2(char *s, char *c);

		/*	Tweaked_funcs.c	*/
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr2(char *s, int c);
int		ft_strcmp(char *s1, char *s2);

		/*	Utils.c			*/
void	free_mem(char **str);
int		doublearray_size(char **array);
void	error(char *str);
int		isplayer(char c);
int		sizeof_map(char *map);

		/*	Should be put in a seperate file	*/
void	key(mlx_key_data_t keydata, void *param);
void	player_position(void);
void	pixels(int color, int j, int i);
void	draw_map(void);

#endif
