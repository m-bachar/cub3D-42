/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:35:11 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/29 18:07:39 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    check_perimeter(char **map)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (map[0][j])
	{
		while (map[0][j] && map[i][j] == ' ') // Add whitespace
			j++;
		if (map[0][j] != '1')
			error("Error: Map must be surrounded by walls !\n");
		j++;
	}
	j = 0;
	while (map[i][j])
	{
		while (map[i][j] && map[i][j] == ' ') // Add whitespace
			j++;
		if (map[i][0] != '1' || map[i][ft_strlen(map[i] - 1)] != '1')
			error("Error: Map must be surrounded by walls !\n");
		j++;
	}
}
