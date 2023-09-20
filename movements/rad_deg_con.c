/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_deg_con.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:36:43 by obouya            #+#    #+#             */
/*   Updated: 2023/09/20 18:10:26 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

double	rad_to_deg(double rad)
{
	return (rad * (180 / M_PI));
}

void	ft_find_angle(t_cub3D *cub3d)
{
	int i;
	int j;

	i = cub3d->xp_c / 32;
	j = cub3d->yp_c / 32;
	if (cub3d->map[j][i] == 'N')
		cub3d->angle = 280;
	if (cub3d->map[j][i] == 'S')
		cub3d->angle = 90;
	if (cub3d->map[j][i] == 'W')
		cub3d->angle = 180;
	if (cub3d->map[j][i] == 'E')
		cub3d->angle = 0;
}
