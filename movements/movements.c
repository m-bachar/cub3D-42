/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:05:44 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/13 23:49:00 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	left_arrow(void)
{
	g_cub3d.xp -= 1 * g_cub3d.speed;
	if (g_cub3d.xp < 0)
		return ;
}

void	right_arrow(void)
{
		mlx_image_to_window(g_cub3d.mlx, g_cub3d.img, 0, 0);
	g_cub3d.xp += 1 * g_cub3d.speed;
	if (g_cub3d.xp < 0)
		return ;
}
void	up_arrow(void)
{
	g_cub3d.yp -= 1 * g_cub3d.speed;
	if (g_cub3d.yp < 0)
		return ;
}
void	down_arrow(void)
{
	g_cub3d.yp += 1 * g_cub3d.speed;
	if (g_cub3d.yp < 0)
		return ;
}

void	key(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(0);
	if (keydata.key == MLX_KEY_LEFT)
		left_arrow(); // It segfaults, dnt use it :)
	if (keydata.key == MLX_KEY_RIGHT)	
		right_arrow(); // It segfaults, dnt use it :)
	if (keydata.key == MLX_KEY_UP)
		up_arrow(); // It segfaults, dnt use it :)
	if (keydata.key == MLX_KEY_DOWN)
		down_arrow(); // It segfaults, dnt use it :)
	draw_map();
}
