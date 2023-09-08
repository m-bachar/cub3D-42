/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/08 00:22:24 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pixels(t_cub3D *cub3d, int color, int j, int i)
{
	int	x;

	cub3d->x = i * 9;
	cub3d->y = j * 9;
	x = cub3d->x;
	while (cub3d->y < (j + 1) * 9)
	{
		cub3d->x = x;
		while (cub3d->x < (i + 1) * 9)
		{
			mlx_pixel_put(cub3d->mlx, cub3d->window, cub3d->x, cub3d->y, color);
			cub3d->x++;
		}
		cub3d->y++;
	}
}

int	main(int ac, char **av)
{
	t_cub3D	cub3d;
	int		i;
	int		j;

	j = 0;
	cub3d.x = 0;
	cub3d.y = 0;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");
	parsing(av[1], &cub3d);
	cub3d.mlx = mlx_init();
	cub3d.window = mlx_new_window(cub3d.mlx, 1920, 1080, "Cub3D");
	while (cub3d.map[j])
	{
		i = 0;
		while (cub3d.map[j][i])
		{
			if (cub3d.map[j][i] == 'N' || cub3d.map[j][i] == 'S'
				|| cub3d.map[j][i] == 'W' || cub3d.map[j][i] == 'E')
				pixels(&cub3d, 0xEB634E, j, i);
			else if (cub3d.map[j][i] == ' ' || cub3d.map[j][i] == '1')
				pixels(&cub3d, 0x808080, j, i);
			else
				pixels(&cub3d, 0xFFFFFF, j, i);
			i++;
		}
		j++;
	}
	mlx_loop(cub3d.mlx);
	free_mem(cub3d.config);
	free_mem(cub3d.map);
}
