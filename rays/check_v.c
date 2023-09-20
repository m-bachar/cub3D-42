/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:19:28 by obouya            #+#    #+#             */
/*   Updated: 2023/09/20 23:59:19 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_v_walls_up_r(t_cub3D *cub3d)
{
	double rad_angle;
	int new_h_x;
	int new_h_y;

	if (cub3d->angle >= 270 && cub3d->angle <= 360)
	{
		rad_angle = deg_to_rad(cub3d->angle);
        // printf("r_v_ang = %f\n", tan(rad_angle));
		cub3d->x_tile =((cub3d->xp_c / 32)+1) * 32;
		cub3d->y_tile = cub3d->yp_c + ((cub3d->x_tile - cub3d->xp_c) * tan(rad_angle));
		cub3d->dx_step = 32;
		cub3d->dy_step = -(32.0 * tan(rad_angle));
		new_h_x = cub3d->x_tile + 1;
		new_h_y =cub3d->y_tile;
        // printf("xtilee = %d  y_tilee = %d\n",new_h_x,new_h_y);
		//mlx_pixel_put(cub3d->mlx,cub3d->window,new_h_x,new_h_y,0XFF0000);
		while (new_h_x >= 0 && new_h_x <= 800 && new_h_y >= 0 && new_h_y <= 864)
		{
			mlx_pixel_put(cub3d->mlx,cub3d->window,new_h_x,new_h_y,0XFF0000);
			if (cub3d->map[new_h_y / 32][new_h_x / 32] == '1')
			{
				cub3d->wall_x = new_h_x;
				cub3d->wall_y = new_h_y;
				break;
			}
				new_h_x += cub3d->dx_step;
				new_h_y -= cub3d->dy_step;
		}
	}
}
void	check_v_walls_up_l(t_cub3D *cub3d)
{
	double rad_angle;
	int new_h_x;
	int new_h_y;

	if (cub3d->angle < 270 && cub3d->angle > 180)
	{
		rad_angle = deg_to_rad(cub3d->angle);
        printf("r_v_ang = %f\n", tan(rad_angle));
		cub3d->x_tile =((cub3d->xp_c / 32)) * 32;
		cub3d->y_tile = cub3d->yp_c - ((cub3d->x_tile - cub3d->xp_c) * tan(rad_angle));
		cub3d->dx_step = 32;
		cub3d->dy_step = (32.0 * tan(rad_angle));
		new_h_x = cub3d->x_tile - 1;
		new_h_y =cub3d->y_tile;
        printf("xtilee = %d  y_tilee = %d\n",new_h_x,new_h_y);
	//	mlx_pixel_put(cub3d->mlx,cub3d->window,new_h_x,new_h_y,0XFF0000);
		while (new_h_x >= 0 && new_h_x <= 800 && new_h_y >= 0 && new_h_y <= 864)
		{
			mlx_pixel_put(cub3d->mlx,cub3d->window,new_h_x,new_h_y,0XFF0000);
			if (cub3d->map[new_h_y / 32][new_h_x / 32] == '1')
			{
				cub3d->wall_x = new_h_x;
				cub3d->wall_y = new_h_y;
				break;
			}
				new_h_x -= cub3d->dx_step;
				new_h_y -= cub3d->dy_step;
		}
	}
}