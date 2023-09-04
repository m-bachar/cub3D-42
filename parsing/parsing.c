/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benito <benito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:37:14 by benito            #+#    #+#             */
/*   Updated: 2023/09/04 22:45:30 by benito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*extract_config(char *fullmap)
{
	char	*config;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (fullmap[i])
	{
		if (fullmap[i] != '\n')
			counter++;
		while (fullmap[i] && fullmap[i] != '\n')
			i++;
		if (counter == 6)
			break ;
		i++;
	}
	config = ft_substr(fullmap, 0, i);
	return (config);
}

char	*extract_map(char *fullmap)
{
	char	*map;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (fullmap[i])
	{
		if (fullmap[i] != '\n')
			counter++;
		while (fullmap[i] && fullmap[i] != '\n')
			i++;
		if (counter == 6)
			break ;
		i++;
	}
	map = ft_substr(fullmap, i, ft_strlen(fullmap));
	return (map);
}

void	parse_config(char *config)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(config, '\n');
	count_elements(splitted);
	check_duplicated(splitted);
	while (splitted[i])
	{
		if (!ft_strncmp("C", splitted[i], 1)
			|| !ft_strncmp("F", splitted[i], 1))
			parse_c_f(splitted[i]);
		else if (!ft_strncmp("NO", splitted[i], 2)
			|| !ft_strncmp("SO", splitted[i], 2)
			|| !ft_strncmp("WE", splitted[i], 2)
			|| !ft_strncmp("EA", splitted[i], 2))
			parse_position(splitted[i]);
		i++;
	}
	free_mem(splitted);
}

void	parse_map(char *map)
{
	char	**splitted;

	splitted = ft_split(map, '\n');
	empty_line(map);
	first_last_lines(splitted);
	sides(splitted);
	find_player(splitted);
	check_surrounding(splitted);
	free_mem(splitted);
}

void	parsing(char *av)
{
	char	*fullmap;
	char	*map;
	char	*config;

	fullmap = map_path(av);
	map_extension(av);
	config = extract_config(fullmap);
	map = extract_map(fullmap);
	parse_config(config);
	parse_map(map);
	printf("Success !\n");
	free(map);
	free(config);
	free(fullmap);
}