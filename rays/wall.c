/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:24:26 by obouya            #+#    #+#             */
/*   Updated: 2023/09/24 05:28:40 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void get_min_wall_distance(t_cub3D *cub3d)
{
	int i = 0;
	int	distance_h;
	int	distance_v;
	int	d_v1;
	int	d_v2;
	int	d_h1;
	int	d_h2;

	d_h1 = pow((cub3d->xp_c - cub3d->wall_h_x),2); 
	d_h2 = pow((cub3d->yp_c - cub3d->wall_h_y),2); 
	distance_h = sqrt(d_h1 + d_h2);
	d_v1 = pow((cub3d->xp_c - cub3d->wall_v_x),2); 
	d_v2 = pow((cub3d->yp_c - cub3d->wall_v_y),2); 
	distance_v = sqrt(d_v1 + d_v2);
	if (distance_h <= distance_v)
	{
		cub3d->ray->x_f_wall = cub3d->wall_h_x;
		cub3d->ray->y_f_wall = cub3d->wall_h_y;
		cub3d->ray->distance = distance_h;
	}
	else
	{
		cub3d->ray->x_f_wall = cub3d->wall_v_x;
		cub3d->ray->y_f_wall = cub3d->wall_v_y;
		cub3d->ray->distance = distance_v;
	}
	i++;
}
