/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:03 by obouya            #+#    #+#             */
/*   Updated: 2023/09/19 16:28:26 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_h_walls_up_r(t_cub3D *cub3d)
{
	if (cub3d->angle >= 270 && cub3d->angle > 0)
	{
		printf("ang = %f\n", cub3d->angle);
		double rad_angle = deg_to_rad(cub3d->angle);
		printf("ang = %f\n", rad_angle);
		cub3d->y_tile = (cub3d->yp_c / 32) * 32;
		cub3d->x_tile = cub3d->xp_c + ((cub3d->y_tile - cub3d->yp_c) / tan(rad_angle));
		cub3d->dy_step = 32;
		cub3d->dx_step = -(32.0 / tan(rad_angle));
		int new_h_x = cub3d->x_tile ;
		int new_h_y =cub3d->y_tile--;
		while (new_h_x >= 0 && new_h_x <= 800 && new_h_y >= 0 && new_h_y <= 864) //height and width map
		{
		printf("nx = %d  ny = %d\n",new_h_x/32,new_h_y/32);
			if (cub3d->map[new_h_y / 32][new_h_x/32] && cub3d->map[new_h_y / 32][new_h_x/32] == '1')
			{
				cub3d->wall_x = new_h_x;
				cub3d->wall_y = new_h_y;
				printf("tx_wall = %f  ty_wall = %f\n",cub3d->wall_x/32,cub3d->wall_y/32);
				printf("px = %f  py = %f\n",cub3d->xp_c/32,cub3d->yp_c/32);
				break;
			}
			else
			{
				new_h_x += cub3d->dx_step;
				new_h_y -= cub3d->dy_step;
			}
		}
	}
}

void	check_h_walls_down_r(t_cub3D *cub3d)
{
	if (cub3d->angle > 0 && cub3d->angle < 90)
	{
		printf("ang = %f\n", cub3d->angle);
		double rad_angle = deg_to_rad(cub3d->angle);
		printf("ang = %f\n", rad_angle);
		cub3d->y_tile = (cub3d->yp_c / 32) * 32;
		cub3d->x_tile = cub3d->xp_c + ((cub3d->y_tile - cub3d->yp_c) / tan(rad_angle));
		cub3d->dy_step = 32;
		cub3d->dx_step = (32.0 / tan(rad_angle));
		int new_h_x = cub3d->x_tile ;
		int new_h_y =cub3d->y_tile--;
		while (new_h_x >= 0 && new_h_x <= 800 && new_h_y >= 0 && new_h_y <= 864)
		{
			if (cub3d->map[new_h_y / 32][new_h_x/32] && cub3d->map[new_h_y / 32][new_h_x/32] == '1')
			{
				cub3d->wall_x = new_h_x;
				cub3d->wall_y = new_h_y;
				printf("tx_wall = %f  ty_wall = %f\n",cub3d->wall_x/32,cub3d->wall_y/32);
				printf("px = %f  py = %f\n",cub3d->xp_c/32,cub3d->yp_c/32);
				break;
			}
			else
			{
				new_h_x += cub3d->dx_step;
				new_h_y += cub3d->dy_step;
			}
		}
	}
}

void	check_h_walls_up_l(t_cub3D *cub3d)
{
	if (cub3d->angle > 180 && cub3d->angle < 270)
	{
		printf("ang = %f\n", cub3d->angle);
		double rad_angle = deg_to_rad(cub3d->angle);
		printf("ang = %f\n", rad_angle);
		cub3d->y_tile = (cub3d->yp_c / 32) * 32;
		cub3d->x_tile = cub3d->xp_c + ((cub3d->y_tile - cub3d->yp_c) / tan(rad_angle));
		cub3d->dy_step = 32;
		cub3d->dx_step = (32.0 / tan(rad_angle));
		int new_h_x = cub3d->x_tile ;
		int new_h_y =cub3d->y_tile --;
		while (new_h_x >= 0 && new_h_x <= 800 && new_h_y >= 0 && new_h_y <= 864)
		{
			if (cub3d->map[new_h_y / 32][new_h_x/32] && cub3d->map[new_h_y / 32][new_h_x/32] == '1')
			{
				cub3d->wall_x = new_h_x;
				cub3d->wall_y = new_h_y;
				printf("tx_wall = %f  ty_wall = %f\n",cub3d->wall_x/32,cub3d->wall_y/32);
				printf("px = %f  py = %f\n",cub3d->xp_c/32,cub3d->yp_c/32);
				break;
			}
			else
			{
				new_h_x -= cub3d->dx_step;
				new_h_y -= cub3d->dy_step;
			}
		}
	}
}

void	check_h_walls_down_l(t_cub3D *cub3d)
{
	if (cub3d->angle > 90 && cub3d->angle < 180)
	{
		printf("ang = %f\n", cub3d->angle);
		double rad_angle = deg_to_rad(cub3d->angle);
		printf("ang = %f\n", rad_angle);
		cub3d->y_tile = (cub3d->yp_c / 32) * 32;
		cub3d->x_tile = cub3d->xp_c + ((cub3d->y_tile - cub3d->yp_c) / tan(rad_angle));
		cub3d->dy_step = 32;
		cub3d->dx_step = (32.0 / tan(rad_angle));
		int new_h_x = cub3d->x_tile ;
		int new_h_y =cub3d->y_tile --;
		while (new_h_x >= 0 && new_h_x <= 800 && new_h_y >= 0 && new_h_y <= 864)
		{
			if (cub3d->map[new_h_y / 32][new_h_x/32] && cub3d->map[new_h_y / 32][new_h_x/32] == '1')
			{
				cub3d->wall_x = new_h_x;
				cub3d->wall_y = new_h_y;
				printf("tx_wall = %f  ty_wall = %f\n",cub3d->wall_x/32,cub3d->wall_y/32);
				printf("px = %f  py = %f\n",cub3d->xp_c/32,cub3d->yp_c/32);
				break;
			}
			else
			{
				new_h_x += cub3d->dx_step;
				new_h_y += cub3d->dy_step;
			}
		}
	}
}
