/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:03:30 by obouya            #+#    #+#             */
/*   Updated: 2023/10/03 00:50:13 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_vertical2(t_cub3D *cub3d, t_vert *vars_v)
{
	int	m_x;
	int	m_y;

	m_x = 0;
	m_y = 0;
	while (vars_v->v_touch_x >= 0 && vars_v->v_touch_y >= 0
		&& vars_v->v_touch_x <= (cub3d->map_x_max * cub3d->tile)
		&& vars_v->v_touch_y <= (cub3d->map_y_max * cub3d->tile))
	{
		m_x = vars_v->v_touch_x / cub3d->tile;
		m_y = vars_v->v_touch_y / cub3d->tile;
		if ((cub3d->map[m_y][m_x] && (cub3d->map[m_y][m_x] == '1' 
			|| cub3d->map[m_y][m_x] == ' '
			|| cub3d->map[m_y][m_x] == '\t'
			|| cub3d->map[m_y][m_x] == '#')) || (!cub3d->map[m_y][m_x]))
		{
			cub3d->wall_v_x = vars_v->v_touch_x;
			cub3d->wall_v_y = vars_v->v_touch_y;
			cub3d->hit_v = 1;
			break ;
		}
		vars_v->v_touch_x += vars_v->dx_step;
		vars_v->v_touch_y += vars_v->dy_step;
	}
	free(vars_v);
}

void	init_vars_vert(t_vert *vars_v)
{
	vars_v->x_intercept = 0;
	vars_v->y_intercept = 0;
	vars_v->v_touch_x = 0;
	vars_v->v_touch_y = 0;
	vars_v->dx_step = 0;
	vars_v->dy_step = 0;
}

void	check_vertical(t_cub3D *cub3d)
{
	t_vert	*vars_v;

	vars_v = malloc (sizeof(t_vert));
	init_vars_vert(vars_v);
	vars_v->x_intercept = floor(cub3d->xp_c / cub3d->tile) * cub3d->tile;
	if (cub3d->ray->ray_right == 1)
		vars_v->x_intercept += cub3d->tile;
	vars_v->y_intercept = cub3d->yp_c + \
	(vars_v->x_intercept - cub3d->xp_c) * tan(cub3d->rad_a);
	vars_v->dx_step = cub3d->tile;
	if (cub3d->ray->ray_left == 1)
		vars_v->dx_step *= -1;
	vars_v->dy_step = cub3d->tile * tan(cub3d->rad_a);
	if (cub3d->ray->ray_up == 1 && vars_v->dy_step > 0)
		vars_v->dy_step *= -1;
	if (cub3d->ray->ray_down == 1 && vars_v->dy_step < 0)
		vars_v->dy_step *= -1;
	vars_v->v_touch_x = vars_v->x_intercept;
	vars_v->v_touch_y = vars_v->y_intercept;
	if (cub3d->ray->ray_left == 1)
		vars_v->v_touch_x -= 0.01;
	check_vertical2(cub3d, vars_v);
}
