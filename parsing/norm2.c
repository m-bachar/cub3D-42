/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:55:47 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/04 17:01:45 by mbachar          ###   ########.fr       */
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

void	check_tabs(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '\t')
			{
				free_mem(map);
				error("Error: Tabs detected in the map !\n");
			}
			i++;
		}
		j++;
	}
}
