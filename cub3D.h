/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:27 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/15 04:46:59 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "./libft/libft.h"

# define BUFFER_SIZE 1
typedef struct global_variable
{
	char *map_str;
	char **map1;
}	t_global;

t_global	g_global;
typedef struct cub3D
{
	char	**map;
	char	**config;
	void	*mlx;
	void	*window;
	int		x;
	int		yp;
	int		xp;
	int		y;
	//ouss
	int size_player;
	int turn_directions; // -1 = left , +1 of right (index indiction if we will decrease or increase the angle)
	int walk_directions; // -1 = baack , +1 of front,  0 stop
	int rotation_angle; //pi/2 initilizing where player looks for 1st time
	int speed;//3
	int rotation_speed;//3*(pi/180) 3 degress per frame 
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_cub3D;

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
void	parse_config(char *config, t_cub3D *cub3d);
void	parse_map(char *map, t_cub3D *cub3d);
void	parsing(char *av, t_cub3D *cub3d);

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


void draw_player(t_cub3D *cub3d, int color, int i, int j, int radius);
int	key(int keycode, t_cub3D *cub3d);
void	draw_map(t_cub3D *cub3d);
void	my_mlx_pixel_put(t_cub3D *cub3d, int x, int y, int color);
int stop_in_2d_r(t_cub3D *cube3d);
int stop_in_2d_u(t_cub3D *cube3d);
int stop_in_2d_d(t_cub3D *cube3d);
int stop_in_2d_l(t_cub3D *cube3d);
#endif
