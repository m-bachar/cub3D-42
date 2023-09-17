/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 08:14:15 by obouya            #+#    #+#             */
/*   Updated: 2023/09/17 08:19:32 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void up_arrow(t_cub3D *cub3d)
{
    double rad_angle = deg_to_rad(cub3d->angle);
    double dx = cub3d->speed * cos(rad_angle);
    double dy = cub3d->speed * sin(rad_angle);
	int c1 = cub3d->xp_c + dx;
	int c2 = cub3d->yp_c +dy;
	if (cub3d->map[c2/32][c1/32] && cub3d->map[c2/32][c1/32] != '1')
	{
    	cub3d->xp_c += dx;
   		cub3d->yp_c += dy;
	}
}
void right_arrow(t_cub3D *cub3d)
{
	double rad_angle = deg_to_rad(cub3d->angle + 90);
    double dx = cub3d->speed * cos(rad_angle);
    double dy = cub3d->speed * sin(rad_angle);
    int c1 = cub3d->xp_c + dx;
	int c2 = cub3d->yp_c + dy;
	if (cub3d->map[c2/32][c1/32] && cub3d->map[c2/32][c1/32] != '1')
	{
    	cub3d->xp_c += dx;
    	cub3d->yp_c += dy;
	}
}

void left_arrow(t_cub3D *cub3d)
{
    double rad_angle = deg_to_rad(cub3d->angle - 90);
    double dx = cub3d->speed * cos(rad_angle);
    double dy = cub3d->speed * sin(rad_angle);
	int c1 = cub3d->xp_c + dx;
	int c2 = cub3d->yp_c + dy;
	if (cub3d->map[c2/32][c1/32] && cub3d->map[c2/32][c1/32] != '1')
	{
    	cub3d->xp_c += dx;
   		cub3d->yp_c += dy;
	}
}

void down_arrow(t_cub3D *cub3d)
{
    double rad_angle = deg_to_rad(cub3d->angle);
    double dx = cub3d->speed * cos(rad_angle);
    double dy = cub3d->speed * sin(rad_angle);
	int c1 = cub3d->xp_c - dx;
	int c2 = cub3d->yp_c - dy;
	if (cub3d->map[c2/32][c1/32] && cub3d->map[c2/32][c1/32] != '1')
	{
    	cub3d->xp_c -= dx;
    	cub3d->yp_c -= dy;
	}
}

int	key_player(int keycode, t_cub3D *cub3d)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 2)
		right_arrow(cub3d);
	if (keycode == 0)
		left_arrow(cub3d);
	if (keycode == 1)
		down_arrow(cub3d);
	if (keycode == 13)
		up_arrow(cub3d);
	if (keycode == 123)
		left(cub3d);
	if (keycode == 124)
		right(cub3d);
	mlx_destroy_image(cub3d->mlx, cub3d->img);
	mlx_clear_window(cub3d->mlx, cub3d->window);
	draw_map(cub3d);
	return (0);
}

void	left(t_cub3D *cub3d)
{
	cub3d->angle -= cub3d->rotation_speed;
}

void	right(t_cub3D *cub3d)
{
	cub3d->angle += cub3d->rotation_speed;
}
