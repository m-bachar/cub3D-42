/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:cub3d->tile:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/23 15:38:42 by obouya           ###   ########.fr       */
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
		// my_mlx_pixel_put(cub3d, ox, oy, 0XFF0000);
		i++;
	}
}	
int update (t_cub3D *cub3d)
{
	// double i = cub3d->angle - (cub3d->fov / 2);
	double rad;
	
	mlx_destroy_image(cub3d->mlx, cub3d->img);
	mlx_clear_window(cub3d->mlx, cub3d->window);

	draw_map(cub3d);
	rad = deg_to_rad(cub3d->angle);
	cub3d->rad_a = rad;
	// while (i < (cub3d->angle + (cub3d->fov / 2)))
	// {
		printf("cub ang = %f\n",cub3d->angle);
		check_h_walls_down(cub3d);
		check_h_walls_up(cub3d);
		check_v_walls_up_r(cub3d);
		check_v_walls_down_r(cub3d);
		check_v_walls_up_l(cub3d);
		check_v_walls_down_l(cub3d);
		get_min_wall_distance(cub3d);
	//	printf("xwall = |%f|  ywall = |%f|\n", cub3d->ray->x_f_wall, cub3d->ray->y_f_wall);
		// cub3d->rad_a += rad / cub3d->w_width;
	// 	i += ((double)cub3d->fov/(double)cub3d->w_width);
	// }
	my_mlx_pixel_put(cub3d, cub3d->ray->x_f_wall, cub3d->ray->y_f_wall, 0XFF0000);
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
int	main(int ac, char **av)
{
	t_cub3D	cub3d;

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
	cub3d.dx_step = 0;
	cub3d.dy_step = 0;
	cub3d.flag = 0;
	cub3d.wall_h_x = 0;
	cub3d.wall_h_y = 0;
	cub3d.wall_v_x = 0;
	cub3d.wall_v_y = 0;
	cub3d.tile = 16;
	 cub3d.map_x_max = 0;
     cub3d.map_y_max = 0;
	cub3d.ray = malloc(sizeof(t_rays));
	cub3d.ray->distance = 0;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");
	parsing(av[1], &cub3d);
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
