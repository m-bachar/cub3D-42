/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:48:10 by obouya            #+#    #+#             */
/*   Updated: 2023/10/02 05:19:59 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	left(t_cub3D *cub3d)
{
	cub3d->angle -= cub3d->rotation_speed;
	ft_normalize_angle(cub3d);
}

void	right(t_cub3D *cub3d)
{
	cub3d->angle += cub3d->rotation_speed;
	ft_normalize_angle(cub3d);
}
