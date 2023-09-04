/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benito <benito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 05:12:11 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/04 23:57:35 by benito           ###   ########.fr       */
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

void	first_last_lines(char **map)
{
	int		i;
	int		j;

	i = doublearray_size(map) - 1;
	j = 0;
	while (map[0][j] && map[0][j] == ' ') // Add whitespaces
		j++;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			error("Erro: Map must be surrounded by walls !\n");
		j++;
	}
	j = 0;
	while (map[i][j] && map[i][j] == ' ') // Add whitespaces
		j++;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			error("Error: Map must be surrounded by walls !\n");
		j++;
	}
}

void	sides(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i] && map[j][i] == ' ') // Add whitespaces
			i++;
		if (map[j][i] != '1')
			error("Error: Map must be surrounded by walls !\n");
		i = ft_strlen(map[j]) - 1;
		while (i && map[j][i] == ' ') // Add whitespaces
			i--;
		if (map[j][i] != '1')
			error("Error: Map must be surrounded by walls !\n");
		j++;
	}
}

void	find_player(char **map)
{
	int	i;
	int	j;
	int	counter;

	j = 0;
	counter = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E')
				counter++;
			i++;
		}
		j++;
	}
	if (counter > 1)
		error("Error: There is more than one player in the map !\n");
	if (counter == 0)
		error("Error: Missing player from the map !\n");
}

void	check_surrounding(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0'
			&& ((map[j][i + 1] != '1' && map[j][i + 1] != '0'
				&& isplayer(map[j][i + 1]))
			|| (map[j][i - 1] != '1' && map[j][i - 1] != '0'
				&& isplayer(map[j][i - 1]))
			|| (map[j + 1][i] != '1' && map[j + 1][i] != '0'
				&& isplayer(map[j + 1][i]))
			|| (map[j - 1][i] != '1' && map[j - 1][i] != '0'
				&& isplayer(map[j - 1][i]))))
				error("Error: Map must be surrounded by walls !\n");
			i++;
		}
		j++;
	}
}