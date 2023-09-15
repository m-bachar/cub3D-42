/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:48:10 by obouya            #+#    #+#             */
/*   Updated: 2023/09/15 05:12:37 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw_player(t_cub3D *cub3d, int color, int i, int j, int radius)
{
	int center_x = i + radius;
	int center_y = j + radius;

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
				my_mlx_pixel_put(cub3d, x, y, color);
			}
			y++;
		}
		x++;
	}
}
