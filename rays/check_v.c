/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:19:28 by obouya            #+#    #+#             */
/*   Updated: 2023/09/26 00:28:04 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_v_walls_up_r(t_cub3D *cub3d)
{
	int new_h_x = 0;
	int new_h_y = 0;

	if (cub3d->angle > 270 && cub3d->angle < 360)
	{
		cub3d->x_tile =((cub3d->xp_c / cub3d->tile) + 1) * cub3d->tile;
		cub3d->y_tile = cub3d->yp_c - ((cub3d->x_tile - cub3d->xp_c) * fabs(tan(cub3d->rad_a)));
		cub3d->dx_step = cub3d->tile;
		cub3d->dy_step = (cub3d->tile * fabs(tan(cub3d->rad_a)));
		new_h_x = cub3d->x_tile + 1;
		new_h_y =cub3d->y_tile;
		while (new_h_x >= 0 && (new_h_x < cub3d->tile * cub3d->map_x_max) && new_h_y >= 0 && new_h_y < (cub3d->tile * cub3d->map_y_max))
		{
			if (cub3d->map[new_h_y / cub3d->tile][new_h_x / cub3d->tile] 
				&& cub3d->map[new_h_y / cub3d->tile][new_h_x / cub3d->tile] == '1')
			{
				cub3d->wall_v_x = new_h_x;
				cub3d->wall_v_y = new_h_y;
				break;
			}
				new_h_x += cub3d->dx_step;
				new_h_y -= cub3d->dy_step;
		}
			// my_mlx_pixel_put(cub3d,new_h_x,new_h_y,0XFF0000);
	}
}

void	check_v_walls_down_r(t_cub3D *cub3d)
{
	int new_h_x;
	int new_h_y;

	if (cub3d->angle < 90 && cub3d->angle >= 0)
	{
		if (cub3d->angle == 0)
		{
			cub3d->y_tile = (((cub3d->yp_c / cub3d->tile)) * cub3d->tile) + cub3d->radius;
			cub3d->x_tile = ((cub3d->xp_c / cub3d->tile) + 1) * cub3d->tile;
			cub3d->dx_step = cub3d->tile;
			cub3d->dy_step = 0;
		}
		else
		{
			cub3d->x_tile =((cub3d->xp_c / cub3d->tile) + 1) * cub3d->tile;
			cub3d->y_tile = cub3d->yp_c + ((cub3d->x_tile - cub3d->xp_c) * tan(cub3d->rad_a));
			// printf("xvtile = %d    yvtile= %d\n",( cub3d->x_tile)/ cub3d->tile,( cub3d->y_tile));
			cub3d->dx_step = cub3d->tile;
			cub3d->dy_step = (cub3d->tile * tan(cub3d->rad_a));
		}
		new_h_x = cub3d->x_tile + 1;
		new_h_y = cub3d->y_tile;
		// printf("ada = %f\n", cub3d->angle);
		// printf("tdan = %f\n", tan(cub3d->rad_a));
		while (new_h_x >= 0 && (new_h_x < cub3d->tile * cub3d->map_x_max) && new_h_y >= 0 && new_h_y < (cub3d->tile * cub3d->map_y_max))
		{
			if (cub3d->map[(new_h_y) / cub3d->tile][(new_h_x) / cub3d->tile] == '1')
			{
				cub3d->wall_v_x = new_h_x;
				cub3d->wall_v_y = new_h_y;
				break;
			}
				new_h_x += cub3d->dx_step;
				new_h_y += cub3d->dy_step;
		}
			// my_mlx_pixel_put(cub3d,new_h_x,new_h_y,0XFF0000);
	}
}

void	check_v_walls_down_l(t_cub3D *cub3d)
{
	int new_h_x=0;
	int new_h_y=0;

	if (cub3d->angle > 90 && cub3d->angle <= 180)
	{
		if (cub3d->angle == 180)
		{
			cub3d->y_tile = (((cub3d->yp_c / cub3d->tile)) * cub3d->tile)+cub3d->radius;
			cub3d->x_tile = ((cub3d->xp_c / cub3d->tile)) * cub3d->tile;
			cub3d->dx_step = cub3d->tile;
			cub3d->dy_step = 0;
		}
		else
		{
			cub3d->x_tile =((cub3d->xp_c / cub3d->tile)) * cub3d->tile;
			cub3d->y_tile = cub3d->yp_c + ((cub3d->xp_c - cub3d->x_tile) * fabs(tan(cub3d->rad_a)));
			cub3d->dx_step = cub3d->tile;
			cub3d->dy_step = (cub3d->tile * fabs(tan(cub3d->rad_a)));
		}
		new_h_x = 	cub3d->x_tile - 1;
		new_h_y =	cub3d->y_tile;
		// printf ("newhx= %d = , newhy = %d\n",new_h_x,new_h_y);
	while (new_h_x >= 0 && (new_h_x < cub3d->tile * cub3d->map_x_max) && new_h_y >= 0 && new_h_y < (cub3d->tile * cub3d->map_y_max))
		{
			if (cub3d->map[new_h_y / cub3d->tile][new_h_x / cub3d->tile]
				&& cub3d->map[new_h_y / cub3d->tile][new_h_x / cub3d->tile] == '1')
			{
				cub3d->wall_v_x = new_h_x;
				cub3d->wall_v_y = new_h_y;
				break;
			}
				new_h_x -= cub3d->dx_step;
				new_h_y += cub3d->dy_step;
		}
			// my_mlx_pixel_put(cub3d,new_h_x,new_h_y,0XFF0000);
	}
}
void	check_v_walls_up_l(t_cub3D *cub3d)
{
	int new_h_x=0;
	int new_h_y=0;

	if (cub3d->angle < 270 && cub3d->angle > 180)
	{
		cub3d->x_tile =((cub3d->xp_c / cub3d->tile)) * cub3d->tile;
		cub3d->y_tile = cub3d->yp_c - ((cub3d->xp_c - cub3d->x_tile) * fabs(tan(cub3d->rad_a)));
		cub3d->dx_step = cub3d->tile;
		cub3d->dy_step = (cub3d->tile * fabs(tan(cub3d->rad_a)));
		new_h_x = cub3d->x_tile - 1;
		new_h_y = cub3d->y_tile;
		// printf("angle f = %f\n",cub3d->angle);
	while (new_h_x >= 0 && (new_h_x < cub3d->tile * cub3d->map_x_max) && new_h_y >= 0 && new_h_y < (cub3d->tile * cub3d->map_y_max))
		{
			if (cub3d->map[new_h_y / cub3d->tile][new_h_x / cub3d->tile] == '1')
			{
				cub3d->wall_v_x = new_h_x;
				cub3d->wall_v_y = new_h_y;
				break;
			}
				new_h_x -= cub3d->dx_step;
				new_h_y -= cub3d->dy_step;
		}
	}
			// my_mlx_pixel_put(cub3d,new_h_x,new_h_y,0XFF0000);
}
