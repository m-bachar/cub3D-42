/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizental.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:39:56 by obouya            #+#    #+#             */
/*   Updated: 2023/09/28 19:57:06 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    check_horizental(t_cub3D *cub3d)
{
    double x_intercept;
    double y_intercept;
    double h_touch_x;
    double h_touch_y;
    int m_x;
    int m_y;
    double dx_step;
    double dy_step;

    x_intercept = 0;
    y_intercept = 0;
    h_touch_y = 0;
    h_touch_x = 0;
    m_x = 0;
    m_y = 0;
    y_intercept = floor(cub3d->yp_c/cub3d->tile) * cub3d->tile;
    if (cub3d->angle > 0 && cub3d->angle < 180)
        y_intercept += cub3d->tile;
    x_intercept = cub3d->xp_c + (y_intercept - cub3d->yp_c) / tan(cub3d->rad_a);
    dy_step = cub3d->tile;
    if (cub3d->angle > 180 && cub3d->angle < 360)
        dy_step *= -1;
    dx_step = cub3d->tile / tan(cub3d->rad_a);
    if ((cub3d->angle > 90 && cub3d->angle < 270) && dx_step > 0)
        dx_step *= -1;
    if (((cub3d->angle >= 0 && cub3d->angle <= 90) || (cub3d->angle >= 270 && cub3d->angle <= 360)) && dx_step < 0)
        dx_step *= -1;
    h_touch_x = x_intercept;
    h_touch_y = y_intercept;
    if (cub3d->angle >= 180 && cub3d->angle < 360)
        h_touch_y -= 0.01;//
    while (h_touch_x >=0 && h_touch_x <= (cub3d->map_x_max * cub3d->tile)
        && h_touch_y >= 0 && h_touch_y <= (cub3d->map_y_max * cub3d->tile))
    {
        m_x = h_touch_x / cub3d->tile;
        m_y = h_touch_y / cub3d->tile;
        if (cub3d->map[m_y][m_x] && cub3d->map[m_y][m_x] == '1')
        {
            cub3d->wall_h_x = h_touch_x;
            cub3d->wall_h_y = h_touch_y;
            break;
        }
    my_mlx_pixel_put(cub3d,h_touch_x, h_touch_y, 0X000000);
        h_touch_x += dx_step;
        h_touch_y += dy_step;
    }
    my_mlx_pixel_put(cub3d,h_touch_x, h_touch_y, 0X000000);
    draw_line_dda(cub3d, cub3d->xp_c, cub3d->yp_c, h_touch_x,  h_touch_y);
}
