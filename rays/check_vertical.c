/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:03:30 by obouya            #+#    #+#             */
/*   Updated: 2023/09/30 19:09:30 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    check_vertical(t_cub3D *cub3d)
{
    double x_intercept;
    double y_intercept;
    double v_touch_x;
    double v_touch_y;
    int m_x;
    int m_y;
    double dx_step;
    double dy_step;

    x_intercept = 0;
    y_intercept = 0;
    v_touch_y = 0;
    v_touch_x = 0;
    m_x = 0;
    m_y = 0;
    x_intercept = floor(cub3d->xp_c / cub3d->tile) * cub3d->tile;
    if (cub3d->ray->ray_right == 1)
        x_intercept += cub3d->tile;
    y_intercept = cub3d->yp_c + (x_intercept - cub3d->xp_c) * tan(cub3d->rad_a);
    dx_step = cub3d->tile;
    if (cub3d->ray->ray_left == 1)
        dx_step *= -1;
    dy_step = cub3d->tile * tan(cub3d->rad_a);
    if (cub3d->ray->ray_up == 1 && dy_step > 0)
        dy_step *= -1;
    if (cub3d->ray->ray_down == 1&& dy_step < 0)
        dy_step *= -1;
    v_touch_x = x_intercept;
    v_touch_y = y_intercept;
    if (cub3d->ray->ray_left == 1)
        v_touch_x -= 0.01;
    while (v_touch_x >=0 && v_touch_x <= (cub3d->map_x_max * cub3d->tile)
        && v_touch_y >= 0 && v_touch_y <= (cub3d->map_y_max * cub3d->tile))
    {
        m_x = v_touch_x / cub3d->tile;
        m_y = v_touch_y / cub3d->tile;
        if (cub3d->map[m_y][m_x] && cub3d->map[m_y][m_x] == '1')
        {
            cub3d->wall_v_x = v_touch_x;
            cub3d->wall_v_y = v_touch_y;
            cub3d->hit_v = 1;
            break;
        }
        // my_mlx_pixel_put(cub3d,v_touch_x, v_touch_y, 0XFF0000);
        v_touch_x += dx_step;
        v_touch_y += dy_step;
    }
}


// void    check_vertical(t_cub3D *cub3d)
// {
//     double x_intercept;
//     double y_intercept;
//     double dx_step;
//     double dy_step;

//     x_intercept = floor(cub3d->xp_c / cub3d->tile) * cub3d->tile;
//     if (cub3d->ray->ray_right)
//         x_intercept += cub3d->tile;
//     y_intercept = cub3d->yp_c + (x_intercept - cub3d->xp_c) * tan(cub3d->rad_a);
//     dx_step = cub3d->tile;
//     if (cub3d->ray->ray_left)
//         dx_step *= -1;
//     dy_step = dx_step * tan(cub3d->rad_a);
//     char    c;
//     int        w;
//     int        h;

//     w = (cub3d->map_x_max) * cub3d->tile;
//     h = (cub3d->map_y_max) * cub3d->tile;
//     while (x_intercept > 0 && x_intercept < w && y_intercept > 0 && y_intercept < h)
//     {
//         if (cub3d->ray->ray_left)
//             x_intercept -= 0.1;
//         c = cub3d->map[(int)y_intercept / cub3d->tile]
//         [(int)x_intercept / cub3d->tile];
//         if (c && c == '1')
//         {
//             cub3d->wall_v_x = x_intercept;
//             cub3d->wall_v_y = y_intercept;
//             // maps->hit.content_h = c;
//             cub3d->hit_v = 1;
//             break ;
//         }
//         // my_mlx_pixel_put(cub3d,x_intercept, y_intercept, 0XFF0000);
//         x_intercept += dx_step;
//         y_intercept += dy_step;
//     }
//      printf("v x == %f v y == %f\n",cub3d->wall_h_x, cub3d->wall_h_y);
//     // my_mlx_pixel_put(cub3d,cub3d->wall_v_x, cub3d->wall_v_y, 0XFF0000);
// }

