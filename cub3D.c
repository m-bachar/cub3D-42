/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:22:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/01 02:50:39 by mbachar          ###   ########.fr       */
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

// void push_ray(t_cub3D *cub3d)
// {
// 	int i = 0;
// 	int ox; 
// 	int oy;
// 	while (i < cub3d->ray->distance)
// 	{
// 		ox = cub3d->xp_c + i * cos(cub3d->rad_a);
// 		oy = cub3d->yp_c + i * sin(cub3d->rad_a);
// 		my_mlx_pixel_put(cub3d, ox, oy, 0XFF0000);
// 		i++;
// 	}
// }	

// void all_rays(t_cub3D *cub3d)
// {
// 	static int i = 0;
// 	if (i < cub3d->j)
// 	{
// 		cub3d->ray->tab_x[i] = cub3d->ray->x_f_wall;
// 		cub3d->ray->tab_y[i] = cub3d->ray->y_f_wall;
// 		cub3d->ray->tab_dist[i] = cub3d->ray->distance;
// 		i++;
// 	}
// 	if (i == cub3d->j)
// 		i = 0;
// }
void draw_line_dda(t_cub3D *cub3d, int x1, int y1, int x2, int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;

    float x = (float)x1;
    float y = (float)y1;

    for (int i = 0; i < steps; i++)
    {
        my_mlx_pixel_put(cub3d, (int)round(x), (int)round(y), color);
        x += xIncrement;
        y += yIncrement;
    }
}
void    ft_ray_facing(t_cub3D *cub3d)
{
    cub3d->ray->ray_right = 0;
    cub3d->ray->ray_left = 0;
    cub3d->ray->ray_up = 0;
    cub3d->ray->ray_down = 0;
    cub3d->hit_h = 0;
    cub3d->hit_v = 0;
    if (cub3d->rad_a >= 0 && cub3d->rad_a <= M_PI)
        cub3d->ray->ray_down = 1;
    cub3d->ray->ray_up = !cub3d->ray->ray_down;
    if (cub3d->rad_a <= 0.5 * M_PI || cub3d->rad_a >= 1.5 * M_PI)
        cub3d->ray->ray_right = 1;
    cub3d->ray->ray_left = !cub3d->ray->ray_right;
}
void all_rays(t_cub3D *cub3d, int k)
{
    cub3d->ray->tab_x[k] = cub3d->ray->x_f_wall;
    cub3d->ray->tab_y[k] = cub3d->ray->y_f_wall;
    cub3d->ray->tab_dist[k] = cub3d->ray->distance;
    cub3d->ray->tab_angle[k] = cub3d->angle2;
    cub3d->ray->is_ray_down[k] = cub3d->ray->ray_down;
    cub3d->ray->is_ray_up[k] = cub3d->ray->ray_up;
    cub3d->ray->is_ray_right[k] = cub3d->ray->ray_right;
    cub3d->ray->is_ray_left[k] = cub3d->ray->ray_left;
    cub3d->ray->tab_hit_h[k] = cub3d->hit_h;
    cub3d->ray->tab_hit_v[k] = cub3d->hit_v;
}

int update (t_cub3D *cub3d)
{
    double i =  cub3d->angle - 30;
    mlx_destroy_image(cub3d->mlx, cub3d->img);
    mlx_clear_window(cub3d->mlx, cub3d->window);
    cub3d->img = mlx_new_image(cub3d->mlx, cub3d->w_width, cub3d->w_height);
    cub3d->addr = mlx_get_data_addr(cub3d->img, &cub3d->bits_per_pixel, &cub3d->line_length,
                                &cub3d->endian);
    int j = 0;
    int k = 0;
    while (i < cub3d->angle + 30)
    {
        if (j == 0)
        {
            cub3d->angle2 = cub3d->angle - 30;
            j = 1;
        }
        ft_normalize_angle2(cub3d);
        cub3d->rad_a = deg_to_rad(cub3d->angle2);
        ft_ray_facing(cub3d);
        check_vertical(cub3d);
        check_horizental(cub3d);
        get_min_wall_distance(cub3d);
        // draw_line_dda(cub3d, cub3d->xp_c, cub3d->yp_c, cub3d->ray->x_f_wall, cub3d->ray->y_f_wall,0XFF0000);
        all_rays(cub3d, k);
        cub3d->angle2 += cub3d->fov/cub3d->w_width;
        ft_normalize_angle2(cub3d);
        i += cub3d->fov/cub3d->w_width;
        // printf("k = %d\n",k);
        k++;
    }
	draw_map_3d(cub3d);
    mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->img, 0, 0);
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
	cub3d.speed = 10;
	cub3d.radius = 6;
	cub3d.w_height = 720;
	cub3d.w_width = 1080;
	cub3d.rotation_speed = 5;
	// cub3d.x_tile = 0;
	// cub3d.y_tile = 0;
	cub3d.flag = 0;
	cub3d.wall_h_x = 0;
	cub3d.wall_h_y = 0;
	cub3d.wall_v_x = 0;
	cub3d.wall_v_y = 0;
	cub3d.map_x_max = 0;
    cub3d.map_y_max = 0;
	cub3d.ray = malloc(sizeof(t_rays));
	cub3d.ray->tab_x = ft_calloc((cub3d.w_width + 1), sizeof(double));
    cub3d.ray->tab_y = ft_calloc((cub3d.w_width + 1), sizeof(double));
    cub3d.ray->tab_dist = ft_calloc((cub3d.w_width + 1), sizeof(double)); 
    cub3d.ray->tab_angle = ft_calloc((cub3d.w_width + 1), sizeof(double)); 
    cub3d.ray->is_ray_down = ft_calloc((cub3d.w_width + 1), sizeof(int));
    cub3d.ray->is_ray_up = ft_calloc((cub3d.w_width + 1), sizeof(int));
    cub3d.ray->is_ray_right = ft_calloc((cub3d.w_width + 1), sizeof(int));
    cub3d.ray->is_ray_left = ft_calloc((cub3d.w_width + 1), sizeof(int));
    cub3d.ray->tab_hit_h = ft_calloc((cub3d.w_width + 1), sizeof(int));
    cub3d.ray->tab_hit_v = ft_calloc((cub3d.w_width + 1), sizeof(int));
	cub3d.textures = malloc(sizeof(t_textures));
	cub3d.ray->distance = 0;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");
	parsing(av[1], &cub3d);
	cub3d.tile = 24;
	fillmap(&cub3d);
	printf("%d\n",doublearray_size(cub3d.map));
	max_x_y(&cub3d);
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
