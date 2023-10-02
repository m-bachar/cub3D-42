/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 06:48:51 by obouya            #+#    #+#             */
/*   Updated: 2023/10/02 06:49:11 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update2(t_cub3D *cub3d)
{
	ft_normalize_angle2(cub3d);
	cub3d->rad_a = deg_to_rad(cub3d->angle2);
	ft_ray_facing(cub3d);
	check_vertical(cub3d);
	check_horizental(cub3d);
	get_min_wall_distance(cub3d);
}

void	init_vars_update(t_cub3D *cub3d)
{
	cub3d->j = 0;
	cub3d->i = 0;
	cub3d->k = 0;
}