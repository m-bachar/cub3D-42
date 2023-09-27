/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:40:36 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/26 00:10:49 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    draw_map_3d(t_cub3D *cub3d, int colomn)
{
    int    wall_height;
    int    start_wall;
    int    end_wall;
    int    line;
    int    color;

    // cub3d->len_ray = cub3d->len_ray * cos(cub3d->fov - cub3d->face_rad);
    cub3d->img = mlx_new_image(cub3d->mlx, cub3d->w_width, cub3d->w_height);
	cub3d->addr = mlx_get_data_addr(cub3d->img, &cub3d->bits_per_pixel, &cub3d->line_length,
								&cub3d->endian);
    color = 0;
    wall_height = (cub3d->w_width * 32) / ((cub3d->ray->distance));
    start_wall = (cub3d->w_height / 2) - (wall_height / 2);
    end_wall = (cub3d->w_height / 2) + (wall_height / 2);
    if (start_wall <= 0)
        start_wall = 0;
    if (end_wall >= cub3d->w_height)
        end_wall = cub3d->w_height;
    line = 0;
    while (line < cub3d->w_height - 1)
    {
        if (line < start_wall)
            color = BLUE;
        else if ((line >= start_wall) && (line <= end_wall))
            color = ORANGE;
        else if (line > end_wall)
            color = BROWN;
        my_mlx_pixel_put(cub3d, colomn, line, color);
        line++;
    }
}
