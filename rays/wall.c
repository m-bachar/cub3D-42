/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:24:26 by obouya            #+#    #+#             */
/*   Updated: 2023/10/01 20:26:46 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void get_min_wall_distance(t_cub3D *cub3d)
{
	double	distance_h;
	double	distance_v;
	double	d_v1;
	double	d_v2;
	double	d_h1;
	double	d_h2;

	if(cub3d->hit_h == 0 && cub3d->hit_v == 1)
		distance_h = INT_MAX;
	else
	{
		d_h1 = pow((cub3d->xp_c - cub3d->wall_h_x),2); 
		d_h2 = pow((cub3d->yp_c - cub3d->wall_h_y),2); 
		distance_h = sqrt(d_h1 + d_h2);
	}
	if(cub3d->hit_h == 1 && cub3d->hit_v == 0)
		distance_v = INT_MAX;
	else
	{
		d_v1 = pow((cub3d->xp_c - cub3d->wall_v_x),2); 
		d_v2 = pow((cub3d->yp_c - cub3d->wall_v_y),2); 
		distance_v = sqrt(d_v1 + d_v2);
	}
	if (distance_h <= distance_v)
	{
		cub3d->ray->x_f_wall = cub3d->wall_h_x;
		cub3d->ray->y_f_wall = cub3d->wall_h_y;
		cub3d->ray->distance = distance_h;
		cub3d->hit_h = 1;
		cub3d->hit_v = 0;
	}
	else
	{
		cub3d->ray->x_f_wall = cub3d->wall_v_x;
		cub3d->ray->y_f_wall = cub3d->wall_v_y;
		cub3d->ray->distance = distance_v;
		cub3d->hit_v = 1;
		cub3d->hit_h = 0;
	}
}
