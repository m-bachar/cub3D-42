/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 05:12:11 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/03 06:53:41 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	empty_line(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] == '\n')
		i++;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			error("Error: Empty line in the map !\n");
		i++;
	}
}
