/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stop_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 05:17:49 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/04 11:10:12 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_all(t_cub3D *cub3d)
{
	free_mem(cub3d->config);
	free_mem(cub3d->map);
	free(cub3d->ray);
	free(cub3d->textures->c);
	free(cub3d->textures->f);
	free(cub3d->textures->no);
	free(cub3d->textures->so);
	free(cub3d->textures->we);
	free(cub3d->textures->ea);
	free(cub3d->textures);
}

int	x_click(t_cub3D *cub3d)
{
	mlx_destroy_image(cub3d->mlx, cub3d->img);
	mlx_clear_window(cub3d->mlx, cub3d->window);
	mlx_destroy_window(cub3d->mlx, cub3d->window);
	free_all(cub3d);
	exit (0);
}

int	key_player_press(int keycode, t_cub3D *cub3d)
{
	if (keycode == 53)
	{
		mlx_destroy_image(cub3d->mlx, cub3d->img);
		mlx_clear_window(cub3d->mlx, cub3d->window);
		mlx_destroy_window(cub3d->mlx, cub3d->window);
		free_all(cub3d);
		exit (0);
	}
	if (keycode == 2)
		cub3d->right_key = 1;
	if (keycode == 0)
		cub3d->left_key = 1;
	if (keycode == 1)
		cub3d->down_key = 1;
	if (keycode == 13)
		cub3d->up_key = 1;
	if (keycode == 123)
		cub3d->left_angle_key = 1;
	if (keycode == 124)
		cub3d->right_angle_key = 1;
	return (0);
}

int	key_player_release(int keycode, t_cub3D *cub3d)
{
	if (keycode == 2)
		cub3d->right_key = 0;
	if (keycode == 0)
		cub3d->left_key = 0;
	if (keycode == 1)
		cub3d->down_key = 0;
	if (keycode == 13)
		cub3d->up_key = 0;
	if (keycode == 123)
		cub3d->left_angle_key = 0;
	if (keycode == 124)
		cub3d->right_angle_key = 0;
	return (0);
}
