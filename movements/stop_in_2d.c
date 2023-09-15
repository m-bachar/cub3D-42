/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_in_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 03:33:15 by obouya            #+#    #+#             */
/*   Updated: 2023/09/15 05:56:05 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int stop_in_2d_r(t_cub3D *cube3d)
{
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;
    c1 =cube3d->xp / 32;
    c2 = cube3d->yp / 32;
    c3 = c1 + 1;
    c4 = c3 * 32;
    printf("x = %d   y = %d\n",cube3d->xp,cube3d->yp);
    if (cube3d->map && cube3d->map[c2][c3] && cube3d->map[c2][c3] == '1')
    {
        if (cube3d->xp +cube3d->speed + 16 < c4 )
            return (1);
        else
            return 0;
    }
    return(1);
}
int stop_in_2d_l(t_cub3D *cube3d)
{
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;
    int c5 = 0;
    c1 = cube3d->xp / 32;
    if (c1 == 0)
        return (0);
    c2 = cube3d->yp / 32;
    c3 = c1 - 1;
    c4 = c3 * 32;
    c5 = cube3d->xp - cube3d->speed - 8;
    printf("x = %d    y = %d\n",cube3d->xp,cube3d->yp);
    if (cube3d->map && cube3d->map[c2][c3] && cube3d->map[c2][c3] == '1')
    {
        printf("x===%c\n",cube3d->map[c2][c3]);
        if (c5 > c4+4 && cube3d->map[c2][c5 / 32])
            return (1);
        else
            return 0;
    }
    return(1);
}
int stop_in_2d_u(t_cub3D *cube3d)
{
    int c1 = 0;
    int c2 = 0;
    c1 =(cube3d->yp - cube3d->speed + 0) / 32 - 1;
    c2 = cube3d->xp/32;
    printf("x = %d    y = %d\n",c1,c2);
    if (cube3d->map && cube3d->map[c1][c2] && cube3d->map[c1][c2] == '1')
        return (0);
    return(1);
}
int stop_in_2d_d(t_cub3D *cube3d)
{
    int c1 = 0;
    int c2 = 0;
    c1 =(cube3d->yp + cube3d->speed - 0) / 32 + 1;
    c2 = cube3d->xp/32;
    printf("x = %d    y = %d\n",c1,c2);
    if (cube3d->map && cube3d->map[c1][c2] && cube3d->map[c1][c2] == '1')
        return (0);
    return(1);
}

