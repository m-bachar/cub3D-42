/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_in_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 03:33:15 by obouya            #+#    #+#             */
/*   Updated: 2023/09/23 15:39:55 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// int stop_in_2d_r(t_cub3D *cub3d)
// {
// 	int c1 = 0;
// 	int c2 = 0;
// 	int c3 = 0;
// 	int c4 = 0;
// 	int c5 = 0;
// 	c1 = cub3d->xp / cub3d->tile;
// 	c2 = (cub3d->yp +  cub3d->radius) / cub3d->tile;
// 	c3 = c1 + 1;
// 	c4 = c3 * cub3d->tile;
//     double rad_angle = deg_to_rad(cub3d->angle);
// 	c5 = cub3d->xp +  2 * cub3d->radius + (cub3d->speed * cos(rad_angle));
// 	if (cub3d->map && cub3d->map[c2][c3] && cub3d->map[c2][c3] == '1')
// 	{
// 		if (c5 < c4 && cub3d->map[c2][c5 / cub3d->tile] != '1')
// 			return (1);
// 		else
// 			return (0);
// 	}
// 	return(1);
// }
// int stop_in_2d_l(t_cub3D *cub3d)
// {
//     int c1 = 0;
//     int c2 = 0;
//     int c3 = 0;
//     int c4 = 0;
//     int c5 = 0;
//     c1 = cub3d->xp / cub3d->tile;
//     c2 = (cub3d->yp + cub3d->radius) / cub3d->tile;
//     c3 = c1 - 1;
//     c4 = c3 * cub3d->tile;
//     double rad_angle = deg_to_rad(cub3d->angle);
//     c5 = cub3d->xp - (cub3d->speed * cos(rad_angle)) ;
//     if (cub3d->map && cub3d->map[c2][c3] && cub3d->map[c2][c3] == '1')
//     {
//         if (c5 > c4 && cub3d->map[c2][c5 / cub3d->tile] != '1' )
// 			return (1);
//         else
//             return (0);
//     }
//     return(1);
// }


// int stop_in_2d_u(t_cub3D *cub3d)
// {
//     int c1 = 0;
//     int c2 = 0;
//     int c3 = 0;
//     int c4 = 0;
//     int c5 = 0;
//     c1 = cub3d->yp / cub3d->tile;
//     c2 = (cub3d->xp + cub3d->radius) / cub3d->tile;
//     c3 = c1 - 1;
//     c4 = c3 * cub3d->tile;
//     double rad_angle = deg_to_rad(cub3d->angle);
//     c5 = cub3d->yp - (cub3d->speed * sin(rad_angle));
//    if (cub3d->map && cub3d->map[c3][c2] && cub3d->map[c3][c2] == '1')
//     {
//         if (c5 >= c4 && cub3d->map[c5 / cub3d->tile][c2] != '1')
//             return (1);
//         else
//             return (0);
//     }
//     return(1);
// }
// int stop_in_2d_d(t_cub3D *cub3d)
// {
//     int c1 = 0;
//     int c2 = 0;
//     int c3 = 0;
//     int c4 = 0;
//     int c5 = 0;
//     c1 =cub3d->yp / cub3d->tile;
//     c2 = (cub3d->xp + cub3d->radius) / cub3d->tile;
//     c3 = c1 + 1;
//     c4 = c3 * cub3d->tile;
//     double rad_angle = deg_to_rad(cub3d->angle);
//     c5 = cub3d->yp + (cub3d->speed * sin(rad_angle)) + 2 * cub3d->radius;
//     if (cub3d->map && cub3d->map[c3][c2] && cub3d->map[c3][c2] == '1')
//     {
//         if (c5 <= c4 && cub3d->map[c5 / cub3d->tile][c2] != '1')
//             return (1);
//         else
//             return (0);
//     }
//     return(1);
// }
