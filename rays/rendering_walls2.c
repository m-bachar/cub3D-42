/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:59:16 by obouya            #+#    #+#             */
/*   Updated: 2023/10/03 01:59:35 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	init_vars_3d(t_3d_var *vars_3d)
{
	vars_3d->w_height = 0;
	vars_3d->wall_beg = 0;
	vars_3d->wall_end = 0;
	vars_3d->line = 0;
	vars_3d->color = 0;
	vars_3d->d = 0;
	vars_3d->x = 0;
	vars_3d->c = 0;
}

void	ft_store_image(t_cub3D *cub3d, t_3d_var *vars_3d)
{
	if (cub3d->hit_v && cub3d->ray->ray_right)
		vars_3d->d = cub3d->textures->ea;
	else if (cub3d->hit_v && cub3d->ray->ray_left)
		vars_3d->d = cub3d->textures->we;
	else if (cub3d->hit_h && cub3d->ray->ray_down)
		vars_3d->d = cub3d->textures->so;
	else if (cub3d->hit_h && cub3d->ray->ray_up)
		vars_3d->d = cub3d->textures->no;
}

void	wall_info_fish_eye(t_cub3D *cub3d, t_3d_var *vars_3d)
{
	cub3d->ray->distance = cub3d->ray->distance * \
	cos(deg_to_rad(cub3d->angle) - cub3d->rad_a);
	vars_3d->w_height = (cub3d->w_width * cub3d->tile) / \
	((cub3d->ray->distance));
	vars_3d->wall_beg = (cub3d->w_height / 2) - (vars_3d->w_height / 2);
	vars_3d->wall_end = (cub3d->w_height / 2) + (vars_3d->w_height / 2);
	if (vars_3d->wall_beg <= 0)
		vars_3d->wall_beg = 0;
	if (vars_3d->wall_end >= cub3d->w_height)
		vars_3d->wall_end = cub3d->w_height;
}
