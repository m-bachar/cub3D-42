/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:40:36 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/01 21:45:08 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int ft_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_map_3d(t_cub3D *cub3d, int colomn)
{
	int	wall_height;
	int	start_wall;
	int	end_wall;
	int	line;
	int	color;

	cub3d->ray->distance = cub3d->ray->distance * cos(deg_to_rad(cub3d->angle) - cub3d->rad_a);
	color = 0;
	wall_height = (cub3d->w_width * 32) / ((cub3d->ray->distance));
	start_wall = (cub3d->w_height / 2) - (wall_height / 2);
	end_wall = (cub3d->w_height / 2) + (wall_height / 2);
	if (start_wall <= 0)
		start_wall = 0;
	if (end_wall >= cub3d->w_height)
		end_wall = cub3d->w_height;
	line = 0;
	while (line < cub3d->w_height - 1)
	{
		if (line < start_wall)
			color = ft_rgb(237, 179, 19);
		else if ((line >= start_wall) && (line <= end_wall))
		{
			if (cub3d->hit_v && cub3d->ray->ray_right && !cub3d->hit_h)
				color = 0x915df0;
			if (cub3d->hit_v && cub3d->ray->ray_left && !cub3d->hit_h)
				color = 0xcf363d;
			if (cub3d->hit_h && cub3d->ray->ray_down && !cub3d->hit_v)
				color = 0xf6c6ff;
			if (cub3d->hit_h &&  cub3d->ray->ray_up && !cub3d->hit_v)
				color = 0x9cc489;
		}
		else if (line > end_wall)
			color = ft_rgb(130, 129, 125);
		my_mlx_pixel_put(cub3d, colomn, line, color);
		line++;
	}
}
