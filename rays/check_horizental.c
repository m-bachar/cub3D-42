/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizental.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:39:56 by obouya            #+#    #+#             */
/*   Updated: 2023/09/30 19:30:02 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// void	push_rays(t_cub3D *cub3d)
// {
// 	int	i;
// 	int	ox;
// 	int	oy;
//     int len;

// 	i = 0;
//     len = sqrt(pow(cub3d->xp_c - cub3d->wall_h_x,2) + pow(cub3d->yp_c - cub3d->wall_h_y,2));
// 	while (i <= len )
// 	{
// 		ox = cub3d->xp_c + (i * cos(cub3d->rad_a));
// 		oy = cub3d->yp_c + (i * sin(cub3d->rad_a));
// 		my_mlx_pixel_put(cub3d, ox, oy, 0x00FF0000);
// 		i++;
// 	}
// }

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
    if (cub3d->ray->ray_down == 1)
        y_intercept += cub3d->tile;
    x_intercept = cub3d->xp_c + (y_intercept - cub3d->yp_c) / tan(cub3d->rad_a);
    dy_step = cub3d->tile;
    if (cub3d->ray->ray_up == 1)
        dy_step *= -1;
    dx_step = cub3d->tile / tan(cub3d->rad_a);
    if (cub3d->ray->ray_left == 1 && dx_step > 0)
        dx_step *= -1;
    if (cub3d->ray->ray_right == 1 && dx_step < 0)
        dx_step *= -1;
    h_touch_x = x_intercept;
    h_touch_y = y_intercept;
    if (cub3d->ray->ray_up == 1)
        h_touch_y -= 0.01;//
    while (h_touch_x >=0 && h_touch_x <= (cub3d->map_x_max * cub3d->tile)
        && h_touch_y >= 0 && h_touch_y <= (cub3d->map_y_max * cub3d->tile))
    {
        m_x = h_touch_x / cub3d->tile;
        m_y = h_touch_y / cub3d->tile;
        if ((cub3d->map[m_y][m_x] && (cub3d->map[m_y][m_x] == '1' || cub3d->map[m_y][m_x] == ' ' || cub3d->map[m_y][m_x] == '\t' || cub3d->map[m_y][m_x] == '#')) || (!cub3d->map[m_y][m_x]))
        {
            cub3d->wall_h_x = h_touch_x;
            cub3d->wall_h_y = h_touch_y;
            cub3d->hit_h = 1;
            break;
        }
        // my_mlx_pixel_put(cub3d,h_touch_x, h_touch_y, 0X000000);
        h_touch_x += dx_step;
        h_touch_y += dy_step;
    }
    // if (h_touch_x < 0)
    //         h_touch_x = 0;
    // my_mlx_pixel_put(cub3d,cub3d->wall_h_x,cub3d->wall_h_y, 0X000000);
    // printf("h x == %f h y == %f\n",h_touch_x,h_touch_y);
    // return;
}

// void    check_horizental(t_cub3D *cub3d)
// {
//     double x_intercept;
//     double y_intercept;
//     double dx_step;
//     double dy_step;
//     char        c;
//     int        w;
//     int        h;

//     y_intercept = floor(cub3d->yp_c / cub3d->tile) * cub3d->tile;
//     if (cub3d->ray->ray_down)
//         y_intercept += cub3d->tile;
//     x_intercept = cub3d->xp_c + (y_intercept - cub3d->yp_c) / tan(cub3d->rad_a);
//     dy_step = cub3d->tile;
//     if (cub3d->ray->ray_up)
//         dy_step *= -1;
//     dx_step = dy_step / tan(cub3d->rad_a);

//     w = (cub3d->map_x_max) * cub3d->tile;
//     h = (cub3d->map_y_max) * cub3d->tile;
//     while (x_intercept > 0 && x_intercept < w && y_intercept > 0 && y_intercept < h)
//     {
//         if (cub3d->ray->ray_up)
//             y_intercept -= 0.1;
//         c = cub3d->map[(int)y_intercept / cub3d->tile]
//         [(int)x_intercept / cub3d->tile];
//         if (c && c == '1')
//         {
//             cub3d->wall_h_x = x_intercept;
//             cub3d->wall_h_y = y_intercept;
//             // maps->hit.content_h = c;
//             cub3d->hit_h = 1;
//             break ;
//         }
//         // my_mlx_pixel_put(cub3d,x_intercept, y_intercept, 0X000000);
//         x_intercept += dx_step;
//         y_intercept += dy_step;
//     }
//      printf("h x == %f h y == %f\n",cub3d->wall_h_x, cub3d->wall_h_y);
//     // my_mlx_pixel_put(cub3d,cub3d->wall_h_x, cub3d->wall_h_y, 0X000000);
// }