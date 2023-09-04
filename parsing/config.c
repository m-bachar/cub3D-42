/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benito <benito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:16:18 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/04 23:23:04 by benito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_rgb_values(char **cf)
{
	int	i;
	int	value;

	i = 0;
	while (cf[i])
	{
		value = ft_atoi(cf[i]);
		if (value >= 0 && value <= 255)
			i++;
		else
			error("Error: RGB values must be between 0 and 255 !\n");
	}
}

void	count_elements(char **config)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (config[i])
	{
		if (!ft_strncmp("C", config[i], 1) || !ft_strncmp("F", config[i], 1)
			|| !ft_strncmp("NO", config[i], 2)
			|| !ft_strncmp("SO", config[i], 2)
			|| !ft_strncmp("WE", config[i], 2)
			|| !ft_strncmp("EA", config[i], 2))
			counter++;
		i++;
	}
	if (counter != 6)
	{
		free_mem(config);
		error("Error: Missing or too many elements !\n");
	}
}

void	parse_c_f(char *cf)
{
	char	**splitted;
	int		size;

	splitted = ft_split2(cf, " CF,"); // Add whitespaces
	size = doublearray_size(splitted);
	if (size != 3)
	{
		free(cf);
		free_mem(splitted);
		error("Error: RGB syntax must comply with (0-255),(0-255),(0-255) !\n");
	}
	check_rgb_values(splitted);
	free_mem(splitted);
}

void	check_duplicated(char **config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (config[i])
	{
		while (config[j])
		{
			if (!ft_strncmp(config[i], config[j], 1) && i != j)
			{
				free_mem(config);
				error("Error: Duplicated elements detected !\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	parse_position(char *position)
{
	char	**splitted;
	int		fd;

	splitted = ft_split2(position, " "); // Add whitespaces
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
	free_mem(splitted);
}
