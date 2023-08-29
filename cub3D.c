/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/29 18:08:23 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	char	**splitted;
	char	**map;
	char	**config;
	int		i;

	splitted = NULL;
	i = 0;
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");

	/*	Map1.c	*/
	map_extension(av[1]);
	splitted = ft_split(map_path(av[1]), '\n');
	config = extract_config(splitted);
	map = extract_map(splitted);

	/*	Map2.c	*/
	while (config[i])
		parse_config(config[i++]);
	check_duplicated(map_path(av[1]));

	/*	Map3.c	*/
	check_perimeter(map);
}
