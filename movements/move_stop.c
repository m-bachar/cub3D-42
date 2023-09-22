/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 08:14:15 by obouya            #+#    #+#             */
/*   Updated: 2023/09/23 00:38:03 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void up_arrow(t_cub3D *cub3d)
{
    double dx = cub3d->speed * cos(cub3d->rad_a);
    double dy = cub3d->speed * sin(cub3d->rad_a);
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
    double dx = cub3d->speed * cos(cub3d->rad_a + (M_PI/2));
    double dy = cub3d->speed * sin(cub3d->rad_a + (M_PI/2));
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
    double dx = cub3d->speed * cos(cub3d->rad_a - (M_PI/2));
    double dy = cub3d->speed * sin(cub3d->rad_a - (M_PI/2));
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
    double dx = cub3d->speed * cos(cub3d->rad_a);
    double dy = cub3d->speed * sin(cub3d->rad_a);
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
	return (0);
}
void	ft_normalize_angle(t_cub3D *cub3d)
{
	while (cub3d->angle >= 360.0)
        cub3d->angle -= 360.0;
    while (cub3d->angle < 0.0)
        cub3d->angle += 360.0;
}

void	left(t_cub3D *cub3d)
{
	cub3d->angle -= cub3d->rotation_speed;
	ft_normalize_angle(cub3d);
	// printf("angle_r = %f \n",cub3d->angle);
}

void	right(t_cub3D *cub3d)
{
	cub3d->angle += cub3d->rotation_speed;
	ft_normalize_angle(cub3d);
	// printf("angle_r = %f \n",cub3d->angle);
}
