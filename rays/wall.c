/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:24:26 by obouya            #+#    #+#             */
/*   Updated: 2023/10/03 00:22:06 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_vars_wall_dis(t_wall_d *dis)
{
	dis->distance_h = 0;
	dis->distance_v = 0;
	dis->d_v1 = 0;
	dis->d_v2 = 0;
	dis->d_h1 = 0;
	dis->d_h2 = 0;
}

void	get_min_wall_distance_nr1(t_cub3D *cub3d, t_wall_d *dis)
{
	if (cub3d->hit_h == 0 && cub3d->hit_v == 1)
		dis->distance_h = INT_MAX;
	else
	{
		dis->d_h1 = pow((cub3d->xp_c - cub3d->wall_h_x), 2); 
		dis->d_h2 = pow((cub3d->yp_c - cub3d->wall_h_y), 2); 
		dis->distance_h = sqrt(dis->d_h1 + dis->d_h2);
	}
}

void	get_min_wall_distance_nr2(t_cub3D *cub3d, t_wall_d *dis)
{
	if (cub3d->hit_h == 1 && cub3d->hit_v == 0)
		dis->distance_v = INT_MAX;
	else
	{
		dis->d_v1 = pow((cub3d->xp_c - cub3d->wall_v_x), 2); 
		dis->d_v2 = pow((cub3d->yp_c - cub3d->wall_v_y), 2); 
		dis->distance_v = sqrt(dis->d_v1 + dis->d_v2);
	}
}

void	get_min_wall_distance(t_cub3D *cub3d)
{
	t_wall_d	*dis;

	dis = malloc(sizeof(t_wall_d));
	init_vars_wall_dis(dis);
	get_min_wall_distance_nr1(cub3d, dis);
	get_min_wall_distance_nr2(cub3d, dis);
	if (dis->distance_h <= dis->distance_v)
	{
		cub3d->ray->x_f_wall = cub3d->wall_h_x;
		cub3d->ray->y_f_wall = cub3d->wall_h_y;
		cub3d->ray->distance = dis->distance_h;
		cub3d->hit_h = 1;
		cub3d->hit_v = 0;
	}
	else
	{
		cub3d->ray->x_f_wall = cub3d->wall_v_x;
		cub3d->ray->y_f_wall = cub3d->wall_v_y;
		cub3d->ray->distance = dis->distance_v;
		cub3d->hit_v = 1;
		cub3d->hit_h = 0;
	}
	free(dis);
}
