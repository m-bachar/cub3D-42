/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizental.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:39:56 by obouya            #+#    #+#             */
/*   Updated: 2023/10/02 05:57:58 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_horizental2(t_cub3D *cub3d, t_horiz *vars_h)
{
	int	m_x;
	int	m_y;

	m_x = 0;
	m_y = 0;
	while (vars_h->h_touch_x >= 0 && vars_h->h_touch_y >= 0 
		&& vars_h->h_touch_x <= (cub3d->map_x_max * cub3d->tile)
		&& vars_h->h_touch_y <= (cub3d->map_y_max * cub3d->tile))
	{
		m_x = vars_h->h_touch_x / cub3d->tile;
		m_y = vars_h->h_touch_y / cub3d->tile;
		if ((cub3d->map[m_y][m_x] && (cub3d->map[m_y][m_x] == '1' 
			|| cub3d->map[m_y][m_x] == ' '
			|| cub3d->map[m_y][m_x] == '\t'
			|| cub3d->map[m_y][m_x] == '#')) || (!cub3d->map[m_y][m_x]))
		{
			cub3d->wall_h_x = vars_h->h_touch_x;
			cub3d->wall_h_y = vars_h->h_touch_y;
			cub3d->hit_h = 1;
			break ;
		}
		vars_h->h_touch_x += vars_h->dx_step;
		vars_h->h_touch_y += vars_h->dy_step;
	}
	free(vars_h);
}

void	init_vars_horiz(t_horiz *vars_h)
{
	vars_h->x_intercept = 0;
	vars_h->y_intercept = 0;
	vars_h->h_touch_x = 0;
	vars_h->h_touch_y = 0;
	vars_h->dx_step = 0;
	vars_h->dy_step = 0;
}

void	check_horizental(t_cub3D *cub3d)
{
	t_horiz	*vars_h;

	vars_h = malloc(sizeof(t_horiz));
	init_vars_horiz(vars_h);
	vars_h->y_intercept = floor(cub3d->yp_c / cub3d->tile) * cub3d->tile;
	if (cub3d->ray->ray_down == 1)
		vars_h->y_intercept += cub3d->tile;
	vars_h->x_intercept = cub3d->xp_c + \
	(vars_h->y_intercept - cub3d->yp_c) / tan(cub3d->rad_a);
	vars_h->dy_step = cub3d->tile;
	if (cub3d->ray->ray_up == 1)
		vars_h->dy_step *= -1;
	vars_h->dx_step = cub3d->tile / tan(cub3d->rad_a);
	if (cub3d->ray->ray_left == 1 && vars_h->dx_step > 0)
		vars_h->dx_step *= -1;
	if (cub3d->ray->ray_right == 1 && vars_h->dx_step < 0)
		vars_h->dx_step *= -1;
	vars_h->h_touch_x = vars_h->x_intercept;
	vars_h->h_touch_y = vars_h->y_intercept;
	if (cub3d->ray->ray_up == 1)
		vars_h->h_touch_y -= 0.01;
	check_horizental2(cub3d, vars_h);
}

