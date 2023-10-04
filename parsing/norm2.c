/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:55:47 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/04 11:31:28 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	add_four_spaces(t_cub3D *cub3d, int *j, int *k)
{
	cub3d->new_map[*j][*k] = ' ';
	(*k)++;
	cub3d->new_map[*j][*k] = ' ';
	(*k)++;
	cub3d->new_map[*j][*k] = ' ';
	(*k)++;
	cub3d->new_map[*j][*k] = ' ';
	(*k)++;
}

void	copy_and_increment(t_cub3D *cub3d, int *i, int *j, int *k)
{
	cub3d->new_map[*j][*k] = cub3d->map[*j][*i];
	(*k)++;
}

void	tabs_to_spaces(t_cub3D *cub3d)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	cub3d->new_map = malloc(8 * (doublearray_size(cub3d->map) + 1));
	while (cub3d->map[j])
	{
		i = 0;
		k = 0;
		cub3d->new_map[j] = malloc(sizeof(char) * ((cub3d->map_x_max * 4) + 1));
		while (cub3d->map[j][i])
		{
			if (cub3d->map[j][i] == '\t')
				add_four_spaces(cub3d, &j, &k);
			else
				copy_and_increment(cub3d, &i, &j, &k);
			i++;
		}
		cub3d->new_map[j][k] = '\0';
		j++;
	}
	cub3d->new_map[j] = NULL;
	free_mem(cub3d->map);
	cub3d->map = cub3d->new_map;
}

void	check_player_surrounding2(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!isplayer(map[j][i]) && map[j][i]
			&& ((map[j][i + 1] && (map[j][i + 1] == '#'))
			|| (map[j][i - 1] && map[j][i - 1] == '#')
			|| (map[j + 1][i] && map[j + 1][i] == '#')
			|| (map[j - 1][i] && map[j - 1][i] == '#')))
				error("Error: Player must be surrounded by walls or floor !\n");
			i++;
		}
		j++;
	}
}
