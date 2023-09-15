/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:05:44 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/15 02:11:32 by mbachar          ###   ########.fr       */
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
int	key(int keycode, t_cub3D *cub3d)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		right_arrow(cub3d);
	if (keycode == 123)
		left_arrow(cub3d);
	if (keycode == 125)
		down_arrow(cub3d);
	if (keycode == 126)
		up_arrow(cub3d);
	mlx_destroy_image(cub3d->mlx, cub3d->img);
	// mlx_clear_window(cub3d->mlx,cub3d->window);
	draw_map(cub3d);
	return (0);
}
