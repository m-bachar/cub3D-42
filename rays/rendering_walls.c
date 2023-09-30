/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:40:36 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/30 23:42:39 by obouya           ###   ########.fr       */
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

    cub3d->ray->distance = cub3d->ray->distance * cos(deg_to_rad(cub3d->angle) - cub3d->rad_a);
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
            color = Dark_B;
        else if (line > end_wall)
            color = GREY;
        my_mlx_pixel_put(cub3d, colomn, line, color);
        line++;
    }
}
