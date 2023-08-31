/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benito <benito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:35:11 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/31 16:27:19 by benito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	first_and_last_lines(char **map)
{
	int	i;
	int	j; // function arg to reduce lines count

	i = 0;
	j = 0;
	while (map[j])
		j++;
	while (map[0][i])
	{
		while (map[0][i] && map[0][i] == ' ') // Add whitespaces
			i++;
		if (map[0][i] != '1')
			error("Error: Map must be surrounded by walls !\n");
		else
			i++;
	}
	i = 0;
	while (map[j - 1][i])
	{
		while (map[j - 1][i] && map[j - 1][i] == ' ') // Add whitespaces
			i++;
		if (map[j - 1][i] != '1')
			error("Error: Map must be surrounded by walls !\n");
		else
			i++;
	}
}

void    check_perimeter(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			while (map[j][i] && map[j][i] == ' ') // Add whitespaces
				i++;
			if (map[j][i] != '1')
				error("Error: Map must be surrounded by walls !\n");
			else
				break ;
		}
		i = 0;
		j++;
	}
}

void	space_in_between(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			while (map[j][i] && map[j][i] == ' ') // Add whitespaces
				i++;
			while (map[j][i] && map[j][i] != ' ') // Add whitespaces
				i++;
		}
		i = 0;
		j++;
	}
}
