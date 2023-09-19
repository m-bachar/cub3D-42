/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/19 15:49:06 by obouya           ###   ########.fr       */
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
				cub3d->xp_c = i * 32 + cub3d->radius;
				cub3d->yp_c = j * 32 + cub3d->radius;
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

	cub3d->x = i * 32;
	cub3d->y = j * 32;
	x = cub3d->x;
	while (cub3d->y < (j + 1) * 32)
	{
		cub3d->x = x;
		while (cub3d->x < (i + 1) * 32)
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

void	check_h_walls_up_r(t_cub3D *cub3d)
{
	if (cub3d->angle >= 270)
	{
		//cub3d->flag =1;
		printf("ang = %f\n", cub3d->angle);
		double rad_angle = deg_to_rad(cub3d->angle);
		printf("ang = %f\n", rad_angle);
		cub3d->y_tile = (cub3d->yp_c / 32) * 32;
		cub3d->x_tile = cub3d->xp_c + ((cub3d->y_tile - cub3d->yp_c) / tan(rad_angle));
		// printf("x_h_wall = %d  y_h_wall = %d\n",cub3d->x_tile / 32, cub3d->y_tile / 32);
		cub3d->dy_step = 32;
		cub3d->dx_step = -(32.0 / tan(rad_angle));
		// printf("xstep = %f  ystep = %f\n",cub3d->dx_step,cub3d->dy_step);
		int new_h_x = cub3d->x_tile ;
		int new_h_y =cub3d->y_tile --;
		while (new_h_x >= 0 &&new_h_x <= cub3d->w_width && new_h_y >= 0 &&new_h_y <= cub3d->w_height) 
		{
			if (cub3d->map[new_h_y / 32][new_h_x/32] && cub3d->map[new_h_y / 32][new_h_x/32] == '1')
			{
				cub3d->wall_x = new_h_x;
				cub3d->wall_y = new_h_y;
				printf("tx_wall = %f  ty_wall = %f\n",cub3d->wall_x/32,cub3d->wall_y/32);
				printf("px = %f  py = %f\n",cub3d->xp_c/32,cub3d->yp_c/32);
				break;
			}
			else
			{
				new_h_x += cub3d->dx_step;
				new_h_y -= cub3d->dy_step;
			}
		}
	}
}
int	main(int ac, char **av)
{
	t_cub3D	cub3d;

	cub3d.x = 0;
	cub3d.y = 0;
	cub3d.xp_c = 0;
	cub3d.yp_c = 0;
	cub3d.speed = 8;
	cub3d.radius = 6;
	cub3d.w_height = 1080;
	cub3d.w_width = 1920;
	cub3d.rotation_speed = 10;
	cub3d.x_tile = 0;
	cub3d.y_tile = 0;
	cub3d.dx_step = 0;
	cub3d.dy_step = 0;
	cub3d.flag = 0;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");
	parsing(av[1], &cub3d);
	player_position(&cub3d);
	ft_find_angle(&cub3d);
	cub3d.mlx = mlx_init();
	cub3d.window = mlx_new_window(cub3d.mlx, cub3d.w_width, cub3d.w_height, "Cub3D");
	check_h_walls_up_r(&cub3d);
	draw_map(&cub3d);
	draw_grid(&cub3d,0xFFFFFF, 25, 28);
	printf("angle = %f\n",cub3d.angle);
	mlx_hook(cub3d.window, 2, 1L << 0, &key_player, &cub3d);
	mlx_loop(cub3d.mlx);
	free_mem(cub3d.config);
	free_mem(cub3d.map);
}
