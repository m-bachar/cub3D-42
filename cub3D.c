/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/31 02:15:11 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	char	**splitted;
	char	**config;
	char	*mappath;
	int		i;
	char	**map;

	splitted = NULL;
	config = NULL;
	i = 0;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");

	/*	Map1.c	*/
	mappath = map_path(av[1]);
	map_extension(av[1]);
	splitted = ft_split(mappath, '\n');
	config = extract_config(splitted);
	map = extract_map(splitted);

	/*	Map2.c	*/
	while (config[i])
		parse_config(config[i++]);
	check_duplicated(mappath);

	/*	Map3.c	*/
	first_and_last_lines(map);
	check_perimeter(map);
	space_in_between(map);
	free_mem(splitted);
	free(config);
}
