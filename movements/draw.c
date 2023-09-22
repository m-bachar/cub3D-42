/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:48:10 by obouya            #+#    #+#             */
/*   Updated: 2023/09/23 00:31:03 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw_player(t_cub3D *cub3d, int color, int i, int j)
{
	int center_x = i;
	int center_y = j;
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

void	draw_map(t_cub3D *cub3d)
{
	int	i;
	int	j;

	j = 0;
	// cub3d->img = mlx_new_image(cub3d->mlx, 1920, 1080);
	// cub3d->addr = mlx_get_data_addr(cub3d->img, &cub3d->bits_per_pixel, &cub3d->line_length,
	// 							&cub3d->endian);
	while (cub3d->map[j])
	{
		i = 0;
		while (cub3d->map[j][i])
		{
			if (cub3d->map[j][i] == 'N' || cub3d->map[j][i] == 'S'
				|| cub3d->map[j][i] == 'W' || cub3d->map[j][i] == 'E')
			{
				pixels(cub3d,0x000000, j, i);
				draw_player(cub3d,0xFFD000, cub3d->xp_c, cub3d->yp_c);
				// draw_line(cub3d, 0xFFD000);
			}
			if (cub3d->map[j][i] == ' ' || cub3d->map[j][i] == '1')
				pixels(cub3d,0x6342F5, j, i);
			else
				pixels(cub3d,0xFFFFFF, j, i);
			draw_player(cub3d,0xFFD000, cub3d->xp_c, cub3d->yp_c);
			// draw_line(cub3d, 0xFFD000);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->img, 0, 0);
}

// void	draw_line(t_cub3D *cub3d, int color)
// {
// 	int center_x = cub3d->xp_c;
// 	int center_y = cub3d->yp_c;
// 	double angle_rad = deg_to_rad(cub3d->angle);//back to ang
//     // int line_length = 20;
//     int end_x =  center_x + cub3d->ray->distance * cos(angle_rad);
//     int end_y = center_y + cub3d->ray->distance * sin(angle_rad);
//     // int end_x = cub3d->wall_x;
//     // int end_y = cub3d->wall_y;

//     int x1 = center_x;
//     int y1 = center_y;
//     int x2 = end_x;
//     int y2 = end_y;

//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (x1 != x2 || y1 != y2)
//     {
//         my_mlx_pixel_put(cub3d, x1, y1, color);

//         int err2 = 2 * err;
//         if (err2 > -dy)
//         {
//             err -= dy;
//             x1 += sx;
//         }
//         if (err2 < dx)
//         {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }
void draw_line(t_cub3D *cub3d, int color) {
    int center_x = cub3d->xp_c;
    int center_y = cub3d->yp_c;
    double angle_rad = deg_to_rad(cub3d->angle);//back to ang
    int line_length = 20;
    int end_x = center_x + line_length * cos(angle_rad);
    int end_y = center_y + line_length * sin(angle_rad);
    // int end_x = cub3d->wall_x;
    // int end_y = cub3d->wall_y;

    int x1 = center_x;
    int y1 = center_y;
    int x2 = end_x;
    int y2 = end_y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        // printf("Drawing pixel at (%d, %d)\n", x1, y1);
        my_mlx_pixel_put(cub3d, x1, y1, color);

        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void	draw_line1(t_cub3D *cub3d, int color)
{
	int center_x = cub3d->xp_c;
	int center_y = cub3d->yp_c;
	// double angle_rad = deg_to_rad(cub3d->angle);//back to ang
    // int line_length = 20;
    // int end_x = center_x + line_length * cos(angle_rad);
    // int end_y = center_y + line_length * sin(angle_rad);
    int end_x = cub3d->x_tile;
    int end_y = cub3d->y_tile - 1;
    printf("xtile = %d ytile =  %d\n",cub3d->x_tile,cub3d->y_tile - 1);

    int x1 = center_x;
    int y1 = center_y;
    int x2 = end_x;
    int y2 = end_y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2)
    {
        mlx_pixel_put(cub3d->mlx,cub3d->window, x1, y1, color);

        int err2 = 2 * err;
        if (err2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}
void	draw_line_ray(t_cub3D *cub3d, int color)
{
	int center_x = cub3d->xp_c;
	int center_y = cub3d->yp_c;
	double angle_rad = deg_to_rad(cub3d->angle);//back to ang
    // int line_length = 20;
    int end_x = center_x + cub3d->ray->x_f_wall * cos(angle_rad);
    int end_y = center_y + cub3d->ray->y_f_wall * sin(angle_rad);
    // int end_x = cub3d->wall_x;
    // int end_y = cub3d->wall_y;

    int x1 = center_x;
    int y1 = center_y;
    int x2 = end_x;
    int y2 = end_y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2)
    {
        my_mlx_pixel_put(cub3d, x1, y1, color);

        int err2 = 2 * err;
        if (err2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}
