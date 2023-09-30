/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:40:36 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/30 20:06:44 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    draw_map_3d(t_cub3D *cub3d)
{
    int    wall_height;
    int    start_wall;
    int    end_wall;
    int    line;
    int    color;

    printf("x=|%f|\n",cub3d->ray->x_f_wall);
    // cub3d->len_ray = cub3d->len_ray * cos(cub3d->fov - cub3d->face_rad);
    // cub3d->img = mlx_new_image(cub3d->mlx, cub3d->w_width, cub3d->w_height);
	// cub3d->addr = mlx_get_data_addr(cub3d->img, &cub3d->bits_per_pixel, &cub3d->line_length,
	// 							&cub3d->endian);
    color = 0;
    wall_height = (cub3d->w_width * cub3d->tile) / ((cub3d->ray->distance));
    start_wall = (cub3d->w_height / 2) - (wall_height / 2);
    end_wall = (cub3d->w_height / 2) + (wall_height / 2);
    if (start_wall <= 0)
        start_wall = 0;
    if (end_wall >= cub3d->w_height)
        end_wall = cub3d->w_height;
    //----
    int    y;

    y = -1;
    while (++y < start_wall)
        my_mlx_pixel_put(cub3d, cub3d->ray->x_f_wall, y, ORANGE);
    y = end_wall - 1;
    while (++y < cub3d->w_height)
        my_mlx_pixel_put(cub3d, cub3d->ray->x_f_wall, y, BROWN);
    //----
    line = start_wall;
    while (line < end_wall)
    {
        // if (line < start_wall)
        //     color = BLUE;
        // else if ((line >= start_wall) && (line <= end_wall))
        //     color = ORANGE;
        // else if (line > end_wall)
        //     color = BROWN;
        my_mlx_pixel_put(cub3d, cub3d->ray->x_f_wall, line, BLUE);
        line++;
    }
}
