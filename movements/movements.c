/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:05:44 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/17 04:16:14 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	left_arrow(t_cub3D *cub3d)
{
	cub3d->xp -= 1 * cub3d->speed;
	if (cub3d->xp < 0)
		return ;
}

void	right_arrow(t_cub3D *cub3d)
{
	cub3d->xp += 1 * cub3d->speed;
	if (cub3d->xp < 0)
		return ;
}

void	up_arrow(t_cub3D *cub3d)
{
	cub3d->yp -= 1 * cub3d->speed;
	if (cub3d->yp < 0)
		return ;
}

void	down_arrow(t_cub3D *cub3d)
{
	cub3d->yp += 1 * cub3d->speed;
	if (cub3d->yp < 0)
		return ;
}

int	key_player(int keycode, t_cub3D *cub3d)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 2 && stop_in_2d_r(cub3d))
		right_arrow(cub3d);
	if (keycode == 0 && stop_in_2d_l(cub3d))
		left_arrow(cub3d);
	if (keycode == 1 && stop_in_2d_d(cub3d))
		down_arrow(cub3d);
	if (keycode == 13 && stop_in_2d_u(cub3d))
		up_arrow(cub3d);
	if (keycode == 123)
		left(cub3d);
	if (keycode == 124)
		right(cub3d);
	mlx_destroy_image(cub3d->mlx, cub3d->img);
	mlx_clear_window(cub3d->mlx, cub3d->window);
	draw_map(cub3d);
	return (0);
}

void	left(t_cub3D *cub3d)
{
	cub3d->angle -= 5;
}

void	right(t_cub3D *cub3d)
{
	cub3d->angle += 5;
}
