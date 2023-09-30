/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:22:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/30 18:54:43 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_position(t_cub3D *cub3d)
{
	int	i;
	int	j;

	j = 0;
	while (cub3d->map[j])
	{
		i = 0;
		while (cub3d->map[j][i])
		{
			if (!isplayer(cub3d->map[j][i]))
			{
				cub3d->xp_c = i * cub3d->tile + cub3d->radius;
				cub3d->yp_c = j * cub3d->tile + cub3d->radius;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	pixels(t_cub3D *cub3d, int color, int j, int i)
{
	int	x;

	cub3d->x = i * cub3d->tile;
	cub3d->y = j * cub3d->tile;
	x = cub3d->x;
	while (cub3d->y < (j + 1) * cub3d->tile)
	{
		cub3d->x = x;
		while (cub3d->x < (i + 1) * cub3d->tile)
		{
			my_mlx_pixel_put(cub3d, cub3d->x, cub3d->y, color);
			cub3d->x++;
		}
		cub3d->y++;
	}
}

void	my_mlx_pixel_put(t_cub3D *cub3d, int x, int y, int color)
{
	char	*dst;

	dst = cub3d->addr + (y * cub3d->line_length + x * (cub3d->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void push_ray(t_cub3D *cub3d)
{
	int i = 0;
	int ox; 
	int oy;
	while (i < cub3d->ray->distance)
	{
		ox = cub3d->xp_c + i * cos(cub3d->rad_a);
		oy = cub3d->yp_c + i * sin(cub3d->rad_a);
		my_mlx_pixel_put(cub3d, ox, oy, 0XFF0000);
		i++;
	}
}	
// int update (t_cub3D *cub3d)
// {
// 	double i = cub3d->angle - (cub3d->fov / 2);
// 	double rad;
	
// 	mlx_destroy_image(cub3d->mlx, cub3d->img);
// 	mlx_clear_window(cub3d->mlx, cub3d->window);
// 	// draw_map(cub3d);
// 	rad = deg_to_rad(cub3d->angle);
// 	cub3d->rad_a = rad;
// 	while (i < (cub3d->angle + (cub3d->fov / 2)))
// 	{
// 		printf("cub ang = %f\n",cub3d->angle);
// 		// check_h_walls(cub3d);
// 		if (cub3d->angle != 180 && cub3d->angle != 0)
// 		{
// 			check_h_walls_down(cub3d);
// 			check_h_walls_up(cub3d);
// 		}
// 		if (cub3d->angle != 270 && cub3d->angle != 90)
// 		{
// 			check_v_walls_up_r(cub3d);
// 			check_v_walls_down_r(cub3d);
// 			check_v_walls_up_l(cub3d);
// 			check_v_walls_down_l(cub3d);
// 		}
// 		get_min_wall_distance(cub3d);
// 		push_ray(cub3d);
// 		cub3d->rad_a += rad / cub3d->w_width;
// 		i += (cub3d->fov/cub3d->w_width);
// 		draw_map_3d(cub3d, cub3d->ray->x_f_wall);
// 	}
// 	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->img, 0, 0);
// 	return(0);
// }
// void draw_line_dda(t_cub3D *cub3d, int x0, int y0, int x1, int y1)
// {
//     int dx = x1 - x0;
//     int dy = y1 - y0;
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

//     float xIncrement = (float)dx / (float)steps;
//     float yIncrement = (float)dy / (float)steps;

//     float x = (float)x0;
//     float y = (float)y0;

//     for (int i = 0; i <= steps; i++)
//     {
//         my_mlx_pixel_put(cub3d, (int)x, (int)y, 0xFF0000); // Set the pixel to red
//         x += xIncrement;
//         y += yIncrement;
//     }
// }

void all_rays(t_cub3D *cub3d)
{
	static int i = 0;
	if (i < cub3d->j)
	{
		cub3d->ray->tab_x[i] = cub3d->ray->x_f_wall;
		cub3d->ray->tab_y[i] = cub3d->ray->y_f_wall;
		cub3d->ray->tab_dist[i] = cub3d->ray->distance;
		i++;
	}
	if (i == cub3d->j)
		i = 0;
}
int update (t_cub3D *cub3d)
{
	// double i = cub3d->angle - (cub3d->fov / 2);
	double rad;
	
	cub3d->j  = ((cub3d->w_width) / (cub3d->fov));
	cub3d->ray->tab_x = malloc (sizeof(int) * cub3d->j);
	if (!cub3d->ray->tab_x)
		exit(1);
	cub3d->ray->tab_y = malloc (sizeof(int) * cub3d->j);
	if (!cub3d->ray->tab_y)
		exit(1);
	cub3d->ray->tab_dist = malloc (sizeof(int) * cub3d->j);
	if (!cub3d->ray->tab_dist)
		exit(1);// exit permited ??
	mlx_destroy_image(cub3d->mlx, cub3d->img);
	mlx_clear_window(cub3d->mlx, cub3d->window);
	draw_map(cub3d);
	rad = deg_to_rad(cub3d->angle);
	cub3d->rad_a = rad;
	printf("angle == %f\n",cub3d->angle);
	// while (i < (cub3d->angle + (cub3d->fov / 2)))
	// {
		// if (cub3d->angle != 180 && cub3d->angle != 0)
		// {
		// 	check_h_walls_up_r(cub3d);
		// 	check_h_walls_up_l(cub3d);
		// 	check_h_walls_down_r(cub3d);
		// 	check_h_walls_down_l(cub3d);
		// }
		// if (cub3d->angle != 270 && cub3d->angle != 90)
		// {
		// 	check_v_walls_up_r(cub3d);
		// 	check_v_walls_down_r(cub3d);
		// 	check_v_walls_up_l(cub3d);
		// 	check_v_walls_down_l(cub3d);
		// }
		// get_min_wall_distance(cub3d);
		// // all_rays(cub3d);
		// draw_map_3d(cub3d, cub3d->ray->x_f_wall);
		check_horizental(cub3d);
		// draw_line_dda(cub3d, cub3d->xp_c, cub3d->yp_c, cub3d->ray->x_f_wall, cub3d->ray->y_f_wall);
	// 	cub3d->rad_a += rad / (cub3d->w_width);
	// 	i += (cub3d->fov/(cub3d->w_width));
	// }
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->img, 0, 0);
	free(cub3d->ray->tab_x);
	free(cub3d->ray->tab_y);
	free(cub3d->ray->tab_dist);//here ???
	return(0);
}
void    max_x_y(t_cub3D *cub3d)
{
    int    i;
    int    size;

    i = 0;
    size = 0;
    cub3d->map_y_max = doublearray_size(cub3d->map);
    while (cub3d->map[i])
    {
        size = ft_strlen(cub3d->map[i]);
        if (size >= cub3d->map_x_max)
            cub3d->map_x_max = size;
        i++;
    }
}

int	longest_line(char **map)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (map[j])
	{
		if ((int)ft_strlen(map[j]) >= len)
			len = ft_strlen(map[j]);
		j++;
	}
	return (len);
}

char	*copy_line(char *src, char *dst, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		dst[j++] = src[i++];
	while (j < len)
	{
		dst[j] = '#';
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

void	fillmap(t_cub3D *cub3d)
{
	char	**new_map;
	int		counter;
	int		i;
	int		j;

	i = 0;
	j = 0;
	counter = 0;
	new_map = malloc(sizeof(char *) * (doublearray_size(cub3d->map) + 1));
	while (cub3d->map[j])
	{
		new_map[j] = malloc(sizeof(char) * ((counter * 4) + (longest_line(cub3d->map) + 1)));
		new_map[j] = copy_line(cub3d->map[j], new_map[j], longest_line(cub3d->map));
		j++;
	}
	new_map[j] = NULL;
	cub3d->map = new_map;
}
// void f()
// {
// 	system("leaks cub3D");
// }

int	main(int ac, char **av)
{
	// atexit(f);
	t_cub3D	cub3d;
	char	*protection;

	protection = malloc(sizeof(char) * 0);
	if (!protection)
		return (1);
	cub3d.x = 0;
	cub3d.y = 0;
	cub3d.fov = 60;
	cub3d.xp_c = 0;
	cub3d.yp_c = 0;
	cub3d.speed = 8;
	cub3d.radius = 6;
	cub3d.w_height = 720;
	cub3d.w_width = 1080;
	cub3d.rotation_speed =5;
	cub3d.x_tile = 0;
	cub3d.y_tile = 0;
	// cub3d.dx_step = 0;
	// cub3d.dy_step = 0;
	cub3d.flag = 0;
	cub3d.wall_h_x = 0;
	cub3d.wall_h_y = 0;
	cub3d.wall_v_x = 0;
	cub3d.wall_v_y = 0;
	cub3d.tile = 16;
	cub3d.map_x_max = 0;
    cub3d.map_y_max = 0;
	cub3d.ray = malloc(sizeof(t_rays));
	cub3d.textures = malloc(sizeof(t_textures));
	cub3d.ray->distance = 0;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");
	parsing(av[1], &cub3d);
	fillmap(&cub3d);
	max_x_y(&cub3d);
	printf("mappx =  %d mapy  = %d\n",cub3d.map_x_max,cub3d.map_y_max);
	player_position(&cub3d);
	ft_find_angle(&cub3d);
	cub3d.mlx = mlx_init();
	cub3d.window = mlx_new_window(cub3d.mlx, cub3d.w_width, cub3d.w_height, "Cub3D");
	cub3d.img = mlx_new_image(cub3d.mlx, cub3d.w_width, cub3d.w_height);
	cub3d.addr = mlx_get_data_addr(cub3d.img, &cub3d.bits_per_pixel, &cub3d.line_length,
								&cub3d.endian);
	mlx_hook(cub3d.window, 2, 1L << 0, &key_player, &cub3d);
	mlx_loop_hook(cub3d.mlx, update, &cub3d);
	mlx_loop(cub3d.mlx);
	free_mem(cub3d.config);
	free_mem(cub3d.map);
}
