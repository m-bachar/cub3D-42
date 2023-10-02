/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:25:15 by obouya            #+#    #+#             */
/*   Updated: 2023/10/02 05:26:24 by mbachar          ###   ########.fr       */
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

	dst = cub3d->addr + (y * cub3d->line_length + \
		x * (cub3d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_ray_facing(t_cub3D *cub3d)
{
	cub3d->ray->ray_right = 0;
	cub3d->ray->ray_left = 0;
	cub3d->ray->ray_up = 0;
	cub3d->ray->ray_down = 0;
	cub3d->hit_h = 0;
	cub3d->hit_v = 0;
	if (cub3d->rad_a > 0 && cub3d->rad_a < M_PI)
		cub3d->ray->ray_down = 1;
	cub3d->ray->ray_up = !cub3d->ray->ray_down;
	if (cub3d->rad_a < 0.5 * M_PI || cub3d->rad_a > 1.5 * M_PI)
		cub3d->ray->ray_right = 1;
	cub3d->ray->ray_left = !cub3d->ray->ray_right;
}
