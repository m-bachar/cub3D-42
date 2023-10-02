/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 08:14:15 by obouya            #+#    #+#             */
/*   Updated: 2023/10/02 05:05:08 by obouya           ###   ########.fr       */
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
	if (cub3d->map[c2/cub3d->tile][c1/cub3d->tile] && cub3d->map[c2/cub3d->tile][c1/cub3d->tile] != '1')
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
	if (cub3d->map[c2/cub3d->tile][c1/cub3d->tile] && cub3d->map[c2/cub3d->tile][c1/cub3d->tile] != '1')
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
	if (cub3d->map[c2/cub3d->tile][c1/cub3d->tile] && cub3d->map[c2/cub3d->tile][c1/cub3d->tile] != '1')
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
	if (cub3d->map[c2/cub3d->tile][c1/cub3d->tile] && cub3d->map[c2/cub3d->tile][c1/cub3d->tile] != '1')
	{
    	cub3d->xp_c -= dx;
    	cub3d->yp_c -= dy;
	}
}

int	key_player(t_cub3D *cub3d)
{
	// if (keycode == 53)
	// 	exit(0);
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
int	key_player_press(int keycode, t_cub3D *cub3d)
{
	if (keycode == 53)
		exit(0);//destroy and clear
	if (keycode == 2)
		cub3d->right_key = 1;
	if (keycode == 0)
		cub3d->left_key = 1;
	if (keycode == 1)
		cub3d->down_key = 1;
	if (keycode == 13)
		cub3d->up_key = 1;
	if (keycode == 123)
		cub3d->left_angle_key = 1;
	if (keycode == 124)
		cub3d->right_angle_key = 1;
	return (0);
}
int	key_player_release(int keycode, t_cub3D *cub3d)
{
	if (keycode == 2)
		cub3d->right_key = 0;
	if (keycode == 0)
		cub3d->left_key = 0;
	if (keycode == 1)
		cub3d->down_key = 0;
	if (keycode == 13)
		cub3d->up_key = 0;
	if (keycode == 123)
		cub3d->left_angle_key = 0;
	if (keycode == 124)
		cub3d->right_angle_key = 0;
	return (0);
}
