/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:27 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/17 04:04:44 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
#include <math.h>
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
	int w_height;
	int w_width;
	int angle;
	int speed;
	int radius;
	int flag_angle;
	char player_direcion;
	int turn_directions; // -1 = left , +1 of right (index indiction if we will decrease or increase the angle)
	int walk_directions; // -1 = baack , +1 of front,  0 stop
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

//----------------------------->movements/draw.c
void 	draw_player(t_cub3D *cub3d, int color, int i, int j);
void	draw_map(t_cub3D *cub3d);
void	my_mlx_pixel_put(t_cub3D *cub3d, int x, int y, int color);
void	draw_line(t_cub3D *cub3d, int color);
//------------------------------>movements/stop_in_2d.c
int		stop_in_2d_r(t_cub3D *cube3d);
int		stop_in_2d_u(t_cub3D *cube3d);
int		stop_in_2d_d(t_cub3D *cube3d);
int		stop_in_2d_l(t_cub3D *cube3d);
//------------------------------>movements/movements.c
int		key_player(int keycode, t_cub3D *cub3d);
void	left_arrow(t_cub3D *cub3d);
void	right_arrow(t_cub3D *cub3d);
void	down_arrow(t_cub3D *cub3d);
void	up_arrow(t_cub3D *cub3d);
//------------------------------>movements/rad_deg_conv.c
void	ft_find_angle(t_cub3D *cub3d);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
//------------------------------>cub3D.c
void	pixels(t_cub3D *cub3d, int color, int j, int i);
void	left(t_cub3D *cub3d);
int	key_view(int keycode, t_cub3D *cub3d);
void	check_direction(char c, t_cub3D *cub3d);
void	right(t_cub3D *cub3d);
#endif
