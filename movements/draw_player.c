/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:48:10 by obouya            #+#    #+#             */
/*   Updated: 2023/09/16 02:27:07 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw_player(t_cub3D *cub3d, int color, int i, int j)
{
	int center_x = i + cub3d->radius;
	int center_y = j + cub3d->radius;

	int x = center_x - cub3d->radius;
	int y = center_y - cub3d->radius;

	while (x <= center_x + cub3d->radius)
	{
		y = center_y - cub3d->radius;
		while (y <= center_y + cub3d->radius)
		{
			int dx = x - center_x;
			int dy = y - center_y;
			if (dx * dx + dy * dy <= cub3d->radius * cub3d->radius)
			{
				my_mlx_pixel_put(cub3d, x, y, color);
			}
			y++;
		}
		x++;
	}
}
