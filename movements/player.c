/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:39:54 by obouya            #+#    #+#             */
/*   Updated: 2023/09/13 23:48:33 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_player(int color, int i, int j, int radius)
{
	int center_x = i;
	int center_y = j;

	int x = center_x - radius;
	int y = center_y - radius;

	while (x <= center_x + radius)
	{
		y = center_y - radius;
		while (y <= center_y + radius)
		{
			int dx = x - center_x;
			int dy = y - center_y;
			if (dx * dx + dy * dy <= radius * radius)
			{
				mlx_put_pixel(g_cub3d.img, x, y, color);
			}
			y++;
		}
		x++;
	}
}

