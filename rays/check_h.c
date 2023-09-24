/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:02:03 by obouya            #+#    #+#             */
/*   Updated: 2023/09/24 04:44:39 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


void	check_h_walls_up(t_cub3D *cub3d)
{
	int new_h_x;
	int new_h_y;

	if (cub3d->angle >= 180 && cub3d->angle <= 360)
	{
		if (cub3d->angle == 270)
		{
			cub3d->y_tile = ((cub3d->yp_c / cub3d->tile)) * cub3d->tile;
			// printf("the ytile = %d\n",cub3d->y_tile);
			cub3d->x_tile = (((cub3d->xp_c / cub3d->tile)) * cub3d->tile)+cub3d->radius;
			cub3d->dy_step = cub3d->tile;
			cub3d->dx_step = 0;
		}
		else
		{
			cub3d->y_tile = ((cub3d->yp_c / cub3d->tile)) * cub3d->tile;
			cub3d->x_tile = cub3d->xp_c + ((cub3d->y_tile - cub3d->yp_c) / tan(cub3d->rad_a));
			cub3d->dy_step = cub3d->tile;
			cub3d->dx_step = -(cub3d->tile / tan(cub3d->rad_a));
		}
		new_h_x = cub3d->x_tile;
		new_h_y =cub3d->y_tile -1;
		// printf(" newhx = %d  newhy = %d\n",new_h_x,new_h_y);
		while (new_h_x >= 0 && new_h_x < 400 && new_h_y >= 0 && new_h_y < 432)
		{
			if (cub3d->map[new_h_y / cub3d->tile][new_h_x/cub3d->tile] == '1')
			{
				cub3d->wall_h_x = new_h_x;
				cub3d->wall_h_y = new_h_y;
				break;
			}
				new_h_x += cub3d->dx_step;
				new_h_y -= cub3d->dy_step;
		}
			// my_mlx_pixel_put(cub3d,new_h_x,new_h_y,0XFF0000);
	}
}

void	check_h_walls_down(t_cub3D *cub3d)
{
	int new_h_x=0;
	int new_h_y=0;
	if (cub3d->angle > 0 && cub3d->angle < 180)
	{
		if (cub3d->angle == 90)
		{
			cub3d->y_tile = ((cub3d->yp_c / cub3d->tile) + 1) * cub3d->tile;
			cub3d->x_tile =( ((cub3d->xp_c / cub3d->tile)) * cub3d->tile)+cub3d->radius;
			cub3d->dy_step = cub3d->tile;
			cub3d->dx_step = 0;
		}
		else
		{
			cub3d->y_tile = ((cub3d->yp_c / cub3d->tile) + 1) * cub3d->tile;
			cub3d->x_tile = cub3d->xp_c + ((cub3d->y_tile - cub3d->yp_c) / tan(cub3d->rad_a));
			cub3d->dy_step = cub3d->tile;
			cub3d->dx_step = (cub3d->tile / tan(cub3d->rad_a));
		}
		 new_h_x = cub3d->x_tile;
		 new_h_y =cub3d->y_tile + 1;
		while (new_h_x >= 0 && new_h_x < 400 && new_h_y >= 0 && new_h_y < 432)
		{
			if (cub3d->map[new_h_y / cub3d->tile][new_h_x/cub3d->tile] && cub3d->map[new_h_y / cub3d->tile][new_h_x/cub3d->tile] == '1')
			{
				cub3d->wall_h_x = new_h_x;
				cub3d->wall_h_y = new_h_y;
				break;
			}
				new_h_x += cub3d->dx_step;
				new_h_y += cub3d->dy_step;
		}
			// my_mlx_pixel_put(cub3d,new_h_x,new_h_y,0XFF0000);
	}
}

// void	check_h_walls_up_r(t_cub3D *cub3d)
// {
// 	if (cub3d->angle >= 270 && cub3d->angle > 0)
// 	{
// 		printf("ang d = %f\n", cub3d->angle);
// 		double cub3d->rad_a = deg_to_rad(cub3d->angle);
// 		printf("ang r = %f\n", cub3d->rad_a);
// 		cub3d->y_tile = ((cub3d->yp_c / cub3d->tile)) * cub3d->tile;
// 		cub3d->x_tile = cub3d->xp_c + ((+cub3d->y_tile - cub3d->yp_c) / tan(cub3d->rad_a));
// 		cub3d->dy_step = cub3d->tile;
// 		cub3d->dx_step = (cub3d->tile.0 / tan(cub3d->rad_a));
// 		int new_h_x = cub3d->x_tile ;
// 		int new_h_y =cub3d->y_tile;
// 		while (new_h_x >= 0 && new_h_x <= cub3d->w_width && new_h_y >= 0 && new_h_y <= cub3d->w_height) //height and width map
// 		{
// 			printf("nx = %d  ny = %d\n",new_h_x/cub3d->tile,new_h_y/cub3d->tile);
// 			draw_line1(cub3d,0XFF0000);
// 			if (cub3d->map[new_h_y / cub3d->tile][new_h_x/cub3d->tile] == '1')
// 			{
// 				cub3d->wall_h_x = new_h_x;
// 				cub3d->wall_h_y = new_h_y;
// 				printf("tx_wall = %d  ty_wall = %d\n",cub3d->wall_h_x/cub3d->tile,cub3d->wall_y/cub3d->tile);
// 				printf("px = %d  py = %d\n",cub3d->xp_c / cub3d->tile,cub3_hd->yp_c / cub3d->tile);
// 				break;
// 			}
// 			else
// 			{
// 				new_h_x += cub3d->dx_step;
// 				new_h_y -= cub3d->dy_step;
// 			}
// 		}
// 	}
// }

// void	check_h_walls_up_l(t_cub3D *cub3d)
// {
// 	if (cub3d->angle > 180 && cub3d->angle < 270)
// 	{
// 		double cub3d->rad_a = deg_to_rad(cub3d->angle);
// 		cub3d->y_tile = ((((cub3d->yp_c) / cub3d->tile)  - 1) * cub3d->tile);
// 		cub3d->x_tile = cub3d->xp_c - ((cub3d->yp_c - cub3d->y_tile) / tan(cub3d->rad_a));
// 		cub3d->wall_h_x = cub3d->x_tile;
// 		cub3d->wall_h_y = cub3d->y_tile;
// 		cub3d->dy_step = cub3d->tile;
// 		cub3d->dx_step = (cub3d->tile.0 / tan(cub3d->rad_a));
// 		int new_h_x = cub3d->x_tile ;
// 		int new_h_y = cub3d->y_tile - 1;
// 		printf ("xstep = %f  ystep = %f\n",cub3d->dx_step , cub3d->dy_step);
// 		printf ("xp = %d  yp = %d\n",cub3d->xp_c/cub3d->tile , cub3d->yp_c/cub3d->tile);
// 		printf ("xtile = %d  ytile = %d\n",cub3d->x_tile/cub3d->tile , cub3d->y_tile/cub3d->tile);
// 		while (new_h_x >= 0 && new_h_x < 400 && new_h_y >= 0 && new_h_y < 96)
// 		{
// 			draw_line1(cub3d,0XFF0000);
// 			if (cub3d->map[new_h_y / cub3d->tile][new_h_x/cub3d->tile] == '1')
// 			{
// 				cub3d->wall_h_x = new_h_x;
// 				cub3d->wall_h_y = new_h_y;
// 				break;
// 			}
// 			new_h_x += cub3d->dx_step;
// 			new_h_y += cub3d->dy_step;
// 		}
// 	}
// }

// void	check_h_walls_down_l(t_cub3D *cub3d)
// {
// 	if (cub3d->angle > 90 && cub3d->angle < 180)
// 	{
// 		printf("ang = %f\n", cub3d->angle);
// 		double cub3d->rad_a = deg_to_rad(cub3d->angle);
// 		printf("ang = %f\n", cub3d->rad_a);
// 		cub3d->y_tile = (cub3d->yp_c / cub3d->tile) * cub3d->tile;
// 		cub3d->x_tile = cub3d->xp_c + ((cub3d->y_tile - cub3d->yp_c) / tan(cub3d->rad_a));
// 		cub3d->dy_step = cub3d->tile;
// 		cub3d->dx_step = (cub3d->tile.0 / tan(cub3d->rad_a));
// 		int new_h_x = cub3d->x_tile ;
// 		int new_h_y =cub3d->y_tile;
// 		while (new_h_x >= 0 && new_h_x < 400 && new_h_y >= 0 && new_h_y < 96)
// 		{
// 			if (cub3d->map[new_h_y / cub3d->tile][new_h_x/cub3d->tile] == '1')
// 			{
// 				cub3d->wall_h_x = new_h_x;
// 				cub3d->wall_h_y = new_h_y;
// 				// printf("tx_wall = %f  ty_wall = %f\n",cub3d->wall_h_x/cub3d->tile,cub3d->wall_y/cub3d->tile);
// 				// printf("px = %f  py = %f\n",cub3d->xp_c/cub3d->tile,cub3d-_h>yp_c/cub3d->tile);
// 				break;
// 			}
// 			else
// 			{
// 				new_h_x += cub3d->dx_step;
// 				new_h_y += cub3d->dy_step;
// 			}
// 		}
// 	}
// }
