/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:27 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/02 04:48:03 by mbachar          ###   ########.fr       */
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
# include <limits.h>
# include "./libft/libft.h"

# define BUFFER_SIZE 1
# define BLUE 0x80CCCC
# define GREY 0X808080
# define BLACK 0xFFFFFF
# define Dark_B	0X053047
# define MAX_SIZE	1000000

typedef struct cub3D
{
	char			**map;
	int				map_x_max;
	int				map_y_max;
	char			**config;
	void			*mlx;
	void			*window;
	double			fov;
	int				x;
	int				flag;
	double			yp_c;
	double			xp_c;
	int				y;
	int				w_height;
	int				w_width;
	double			angle;
	double			angle2;
	double			speed;
	double			radius;
	char			player_direcion;
	double			rotation_speed;
	double			wall_h_x;
	double			wall_h_y;
	double			wall_v_x;
	double			wall_v_y;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				tile;
	double			rad_a;
	int 			hit_h;
	int 			hit_v;
	struct s_rays	*ray;
	struct s_textures	*textures;
}	t_cub3D;

typedef struct s_rays
{
	double	x_f_wall;
	double	y_f_wall;
	double	distance;
	int		ray_right;
	int		ray_left;
	int		ray_down;
	int		ray_up;
}	t_rays;

typedef struct s_textures
{
	int				*c;
	int				*f;
	unsigned int	*no;
	unsigned int	*so;
	unsigned int	*we;
	unsigned int	*ea;
}	t_textures;

typedef struct s_imgs
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_imgs;

		/*	Config.c		*/
void	check_rgb_values(char **cf, t_cub3D *cub3d, int flag);
void	count_elements(char **config);
void	count_commas(char *cf);
void	parse_c_f(char *cf, t_cub3D *cub3d);
void	check_duplicated(char **config);

		/*	Map.c			*/
void	empty_line(char *map);
void	first_last_lines(char **map);
void	sides(char **map);
void	find_player(char **map);
void	check_surrounding(char **map);

		/*	Norm.c			*/
int		iswhitespaces(char c);
void	read_and_store(char **config, t_cub3D *cub3d);
void	parse_position(char *position, t_cub3D *cub3d);
void	check_map_content(char **map);
void	check_player_surrounding(char **map);

		/*	Parsing.c		*/
char	*extract_config(char *fullmap);
char	*extract_map(char *fullmap);
void	parse_config(char *config, t_cub3D *cub3d);
void	parse_map(char *map, t_cub3D *cub3d);
void	parsing(char *av, t_cub3D *cub3d);

		/*	Scene.c			*/
void	map_extension(char *av);
char	*map_path(char *map);
char	*read_file(int fd);

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

//------------------------------>cub3D.c
void	left(t_cub3D *cub3d);
int		key_view(int keycode, t_cub3D *cub3d);
void	check_direction(char c, t_cub3D *cub3d);
void	right(t_cub3D *cub3d);
void	draw_line_ray(t_cub3D *cub3d, int color);
void	draw_line1(t_cub3D *cub3d, int color);
void 	get_min_wall_distance(t_cub3D *cub3d);
void    max_x_y(t_cub3D *cub3d);
void    draw_map_3d(t_cub3D *cub3d,int coloumn);
void	all_rays(t_cub3D *cub3d, int k);
void    check_horizental(t_cub3D *cub3d);
void    check_vertical(t_cub3D *cub3d);
void	ft_init_vars(t_cub3D *cub3d);
void	parsing_total(int ac, char **av, t_cub3D *cub3d);
//------------------------------>cub3D_utils1.c
void    ft_ray_facing(t_cub3D *cub3d);
void	player_position(t_cub3D *cub3d);
void	pixels(t_cub3D *cub3d, int color, int j, int i);
void	my_mlx_pixel_put(t_cub3D *cub3d, int x, int y, int color);
void 	draw_line_dda(t_cub3D *cub3d, int x1, int y1, int x2, int y2, int color);
//------------------------------>movements/rad_deg_conv.c
void	ft_find_angle(t_cub3D *cub3d);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
void	ft_normalize_angle(t_cub3D *cub3d);
void	ft_normalize_angle2(t_cub3D *cub3d);
//----------------------------->movements/draw.c
void 	draw_player(t_cub3D *cub3d, int color, int i, int j);
void	draw_map(t_cub3D *cub3d);
void	draw_line(t_cub3D *cub3d, int color);
void	left(t_cub3D *cub3d);
void	right(t_cub3D *cub3d);
//------------------------------>movements/move.c
int		key_player(int keycode, t_cub3D *cub3d);
void	left_arrow(t_cub3D *cub3d);
void	right_arrow(t_cub3D *cub3d);
void	down_arrow(t_cub3D *cub3d);
void	up_arrow(t_cub3D *cub3d);
void    tex(t_cub3D *cub3d, char *path, unsigned int **tex);

#endif
