/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:05:44 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/13 05:46:53 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	left_arrow(void)
{
	int	x;
	int	new_x;

	player_position();
	x = g_cub3d.xp;
	new_x = x - 1;
	printf("X = %d\tNew_X = %d\n", x, new_x);
	if (new_x < 0)
		return ;
	// pixels(0x808080FF, g_cub3d.y, x);
	pixels(0xFF0000FF, g_cub3d.y, new_x);
}

void	key(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(0);
	if (keydata.key == MLX_KEY_LEFT)
	{
		// left_arrow(); It segfaults, dnt use it :)
		printf("Left arrow key has been pressed !\n");
	}
	if (keydata.key == MLX_KEY_RIGHT)
		printf("Right arrow key has been pressed !\n");
	if (keydata.key == MLX_KEY_UP)
		printf("Up arrow key has been pressed !\n");
	if (keydata.key == MLX_KEY_DOWN)
		printf("Down arrow key has been pressed !\n");
}
