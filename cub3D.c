/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/13 02:44:21 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_position()
{
	int	i;
	int	j;

	j = 0;
	while (g_cub3d.map[j])
	{
		i = 0;
		while (g_cub3d.map[j][i])
		{
			if (!isplayer(g_cub3d.map[j][i]))
			{
				g_cub3d.xp = i;
				g_cub3d.yp = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	pixels(int color, int j, int i)
{
	int	x;

	g_cub3d.x = i * 32;
	g_cub3d.y = j * 32;
	x = g_cub3d.x;
	while (g_cub3d.y < (j + 1) * 32)
	{
		g_cub3d.x = x;
		while (g_cub3d.x < (i + 1) * 32)
		{
			mlx_put_pixel(g_cub3d.img, g_cub3d.x, g_cub3d.y, color);
			g_cub3d.x++;
		}
		g_cub3d.y++;
	}
}

void draw_player(int color, int i, int j, int radius)
{
	int center_x = i * 32 + 16;
	int center_y = j * 32 + 16;

	int x = center_x - radius;
	int y = center_y - radius;

	while (x <= center_x + radius)
	{
		y = center_y - radius;
		while (y <= center_y + radius)
		{
			int dx = x - center_x;
			int dy = y - center_y;
			if (dx * dx + dy * dy <= radius * radius)
			{
				mlx_put_pixel(g_cub3d.img, g_cub3d.x, g_cub3d.y, color);
			}
			y++;
		}
		x++;
	}
}
int	main(int ac, char **av)
{
	int		i;
	int		j;

	j = 0;
	g_cub3d.x = 0;
	g_cub3d.y = 0;
	g_cub3d.xp = 0;
	g_cub3d.yp = 0;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");
	parsing(av[1]);
	g_cub3d.mlx = mlx_init(1920, 1080, "Cub3D", 1);
	g_cub3d.img = mlx_new_image(g_cub3d.mlx, 1920, 1080);
	mlx_image_to_window(g_cub3d.mlx, g_cub3d.img, 0, 0);
	while (g_cub3d.map[j])
	{
		i = 0;
		while (g_cub3d.map[j][i])
		{
			if (g_cub3d.map[j][i] == 'N' || g_cub3d.map[j][i] == 'S'
				|| g_cub3d.map[j][i] == 'W' || g_cub3d.map[j][i] == 'E')
			{
				pixels(0xFF0000FF, j, i);
				// draw_player(, 0xFF0000FF, i, j, 5);
			}
			else if (g_cub3d.map[j][i] == ' ' || g_cub3d.map[j][i] == '1')
				pixels(0x808080FF, j, i);
			else
				pixels(0xFFFFFFFF, j, i);
			i++;
		}
		j++;
	}
	mlx_key_hook(g_cub3d.mlx, &key, NULL);
	mlx_loop(g_cub3d.mlx);
	mlx_terminate(g_cub3d.mlx);
	free_mem(g_cub3d.config);
	free_mem(g_cub3d.map);
}
