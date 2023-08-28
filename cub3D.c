/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/28 04:29:03 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	exit(1);
}

int	main(int ac, char **av)
{
	char	**splitted;

	splitted = NULL;
	if (ac < 2)
		error("Error: Missing map path!\n");
	else if (ac > 2)
		error("Error: Too many arguments!\n");
	map_extension(av[1]);
	splitted = ft_split(map_path(av[1]), '\n');
	int	i = 0;
	while (splitted[i])
		printf("====> %s\n", splitted[i++]);
}
