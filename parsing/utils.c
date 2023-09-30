/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:14 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/30 03:12:46 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_mem(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	doublearray_size(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

void	error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	// system("leaks cub3D");
	exit(1);
}

int	isplayer(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (1);
}

int	sizeof_map(char *map)
{
	int	i;
	int	map_size;

	i = 0;
	map_size = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			map_size++;
		i++;
	}
	return (map_size);
}

int	iswhitespaces(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	return (1);
}
