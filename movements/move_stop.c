/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 08:14:15 by obouya            #+#    #+#             */
/*   Updated: 2023/10/02 05:17:58 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	up_arrow(t_cub3D *cub3d)
{
	double	rad_angle;
	double	dx;
	double	dy;
	int		c1;
	int		c2;

	rad_angle = deg_to_rad(cub3d->angle);
	dx = cub3d->speed * cos(rad_angle);
	dy = cub3d->speed * sin(rad_angle);
	c1 = cub3d->xp_c + dx;
	c2 = cub3d->yp_c + dy;
	if (cub3d->map[c2 / cub3d->tile][c1 / cub3d->tile]
		&& cub3d->map[c2 / cub3d->tile][c1 / cub3d->tile] != '1')
	{
		cub3d->xp_c += dx;
		cub3d->yp_c += dy;
	}
}

void	right_arrow(t_cub3D *cub3d)
{
	double	rad_angle;
	double	dx;
	double	dy;
	int		c1;
	int		c2;

	rad_angle = deg_to_rad(cub3d->angle + 90);
	dx = cub3d->speed * cos(rad_angle);
	dy = cub3d->speed * sin(rad_angle);
	c1 = cub3d->xp_c + dx;
	c2 = cub3d->yp_c + dy;
	if (cub3d->map[c2 / cub3d->tile][c1 / cub3d->tile]
		&& cub3d->map[c2 / cub3d->tile][c1 / cub3d->tile] != '1')
	{
		cub3d->xp_c += dx;
		cub3d->yp_c += dy;
	}
}

void	left_arrow(t_cub3D *cub3d)
{
	double	rad_angle;
	double	dx;
	double	dy;
	int		c1;
	int		c2;

	rad_angle = deg_to_rad(cub3d->angle - 90);
	dx = cub3d->speed * cos(rad_angle);
	dy = cub3d->speed * sin(rad_angle);
	c1 = cub3d->xp_c + dx;
	c2 = cub3d->yp_c + dy;
	if (cub3d->map[c2 / cub3d->tile][c1 / cub3d->tile]
		&& cub3d->map[c2 / cub3d->tile][c1 / cub3d->tile] != '1')
	{
		cub3d->xp_c += dx;
		cub3d->yp_c += dy;
	}
}

void	down_arrow(t_cub3D *cub3d)
{
	double	rad_angle;
	double	dx;
	double	dy;
	int		c1;
	int		c2;

	rad_angle = deg_to_rad(cub3d->angle);
	dx = cub3d->speed * cos(rad_angle);
	dy = cub3d->speed * sin(rad_angle);
	c1 = cub3d->xp_c - dx;
	c2 = cub3d->yp_c - dy;
	if (cub3d->map[c2 / cub3d->tile][c1 / cub3d->tile]
		&& cub3d->map[c2 / cub3d->tile][c1 / cub3d->tile] != '1')
	{
		cub3d->xp_c -= dx;
		cub3d->yp_c -= dy;
	}
}

int	key_player(t_cub3D *cub3d)
{
	if (cub3d->right_key == 1)
		right_arrow(cub3d);
	if (cub3d->left_key == 1)
		left_arrow(cub3d);
	if (cub3d->down_key == 1)
		down_arrow(cub3d);
	if (cub3d->up_key == 1)
		up_arrow(cub3d);
	if (cub3d->left_angle_key == 1)
		left(cub3d);
	if (cub3d->right_angle_key == 1)
		right(cub3d);
	return (0);
}
