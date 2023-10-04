/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:26:24 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/04 10:57:04 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	iswhitespaces(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	return (1);
}

void	read_and_store(char **config, t_cub3D *cub3d)
{
	if (!ft_strcmp(config[0], "NO"))
		tex(cub3d, config[1], &cub3d->textures->no);
	else if (!ft_strcmp(config[0], "SO"))
		tex(cub3d, config[1], &cub3d->textures->so);
	else if (!ft_strcmp(config[0], "WE"))
		tex(cub3d, config[1], &cub3d->textures->we);
	else if (!ft_strcmp(config[0], "EA"))
		tex(cub3d, config[1], &cub3d->textures->ea);
}

void	parse_position(char *position, t_cub3D *cub3d)
{
	char	**splitted;
	int		fd;

	splitted = ft_split2(position, " \t\r");
	if (ft_strcmp(splitted[0], "NO") && ft_strcmp(splitted[0], "SO")
		&& ft_strcmp(splitted[0], "WE") && ft_strcmp(splitted[0], "EA"))
	{
		free_mem(splitted);
		error("Error: Missing or too many elements !\n");
	}
	fd = open(splitted[1], O_RDWR);
	if (fd == -1 && !access(splitted[1], F_OK))
	{
		free_mem(splitted);
		error("Error: Permission denied !\n");
	}
	else if (fd == -1)
	{
		free_mem(splitted);
		error("Error: XPM file not found !\n");
	}
	else
		read_and_store(splitted, cub3d);
	free_mem(splitted);
}

void	check_map_content(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0'
				&& map[j][i] != 'N' && map[j][i] != 'S'
				&& map[j][i] != 'W' && map[j][i] != 'E'
				&& iswhitespaces(map[j][i]))
				error(\
				"Error: A different element has been detected in the map !\n");
			i++;
		}
		j++;
	}
}

void	check_player_surrounding(char **map)
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
			&& ((map[j][i + 1] && map[j][i + 1] != '1' && map[j][i + 1] != '0')
			|| (map[j][i - 1] && map[j][i - 1] != '1' && map[j][i - 1] != '0')
			|| (map[j + 1][i] && map[j + 1][i] != '1' && map[j + 1][i] != '0')
			|| (map[j - 1][i] && map[j - 1][i] != '1' && map[j - 1][i] != '0')))
			{
				error("Error: Player must be surrounded by walls or floor !\n");
			}
			i++;
		}
		j++;
	}
}
