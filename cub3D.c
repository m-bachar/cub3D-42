/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/15 00:31:21 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_position(t_cub3D *cub3d)
{
	int	i;
	int	j;

	j = 0;
	while (cub3d->map[j])
	{
		i = 0;
		while (cub3d->map[j][i])
		{
			if (!isplayer(cub3d->map[j][i]))
			{
				cub3d->xp = i*32+16;
				cub3d->yp = j*32+16;
				return ;
			}
			i++;
		}
		j++;
	}
}
void	pixels(t_cub3D *cub3d, int color, int j, int i)
{
	int	x;

	cub3d->x = i * 32;
	cub3d->y = j * 32;
	x = cub3d->x;
	while (cub3d->y < (j + 1) * 32)
	{
		cub3d->x = x;
		while (cub3d->x < (i + 1) * 32)
		{
			mlx_pixel_put(cub3d->mlx, cub3d->window, cub3d->x, cub3d->y, color);
			cub3d->x++;
		}
		cub3d->y++;
	}
}
void	draw_map(t_cub3D *cub3d)
{
	int	i;
	int	j;

	j = 0;
	while (cub3d->map[j])
	{
		i = 0;
		while (cub3d->map[j][i])
		{
			if (cub3d->map[j][i] == 'N' || cub3d->map[j][i] == 'S'
				|| cub3d->map[j][i] == 'W' || cub3d->map[j][i] == 'E')
			{
				pixels(cub3d,0x000000, j, i);
				draw_player(cub3d,0xFFD000, cub3d->xp, cub3d->yp, 8);
			}
			else if (cub3d->map[j][i] == ' ' || cub3d->map[j][i] == '1')
			{
				pixels(cub3d,0x6342F5, j, i);
				draw_player(cub3d,0xFFD000, cub3d->xp, cub3d->yp, 8);
			}
			else
			{	
				pixels(cub3d,0x000000, j, i);
				draw_player(cub3d,0xFFD000, cub3d->xp, cub3d->yp, 8);
			}
			i++;
		}
		j++;
	}
}
int	main(int ac, char **av)
{
	t_cub3D	cub3d;

	cub3d.x = 0;
	cub3d.y = 0;
	cub3d.xp = 0;
	cub3d.yp = 0;
	cub3d.speed = 1;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");
	parsing(av[1], &cub3d);
	cub3d.mlx = mlx_init();
	cub3d.window = mlx_new_window(cub3d.mlx, 1920, 1080, "Cub3D");
	player_position(&cub3d);
	draw_map(&cub3d);
	mlx_key_hook(cub3d.window, &key, &cub3d);
	mlx_loop(cub3d.mlx);
	free_mem(cub3d.config);
	free_mem(cub3d.map);
}
