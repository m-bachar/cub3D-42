/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/03 05:10:24 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	main(int ac, char **av)
{
	char	*fullmap;
	char	*map;
	char	*config;
	int		map_size;

	map_size = 0;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");
	fullmap = map_path(av[1]);
	map_extension(av[1]);
	map_size = sizeof_map(fullmap);
	config = extract_config(fullmap);
	map = extract_map(fullmap);
	parse_config(config);
	// parse_map(map);
	printf("%s\n", map);
}
