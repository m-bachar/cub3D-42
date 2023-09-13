/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:05:44 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/13 22:46:36 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	left_arrow(void)
{
	g_cub3d.xp -= 1 * 5;
	//printf("x = %d\n",g_cub3d.xp);
	if (g_cub3d.xp < 0)
		return ;
	draw_map();
}

void	right_arrow(void)
{
	g_cub3d.xp += 1 * 5;
	if (g_cub3d.xp < 0)
		return ;
	draw_map();
}
void	up_arrow(void)
{
	g_cub3d.yp -= 1 * 5;
	if (g_cub3d.yp < 0)
		return ;
	draw_map();
}
void	down_arrow(void)
{
	g_cub3d.yp += 1 * 5;
	if (g_cub3d.yp < 0)
		return ;
	draw_map();
}

void	key(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(0);
	if (keydata.key == MLX_KEY_LEFT)
	{
		left_arrow(); // It segfaults, dnt use it :)
		// printf("Left arrow key has been pressed !\n");
	}
	if (keydata.key == MLX_KEY_RIGHT)	
	{
		right_arrow(); // It segfaults, dnt use it :)
		// printf("Right arrow key has been pressed !\n");
	}
	if (keydata.key == MLX_KEY_UP)
	{
		up_arrow(); // It segfaults, dnt use it :)
		// printf("Up arrow key has been pressed !\n");
	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		down_arrow(); // It segfaults, dnt use it :)
		// printf("Down arrow key has been pressed !\n");
	}
}
