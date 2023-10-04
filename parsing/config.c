/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:16:18 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/04 15:44:04 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_rgb_values(char **cf, t_cub3D *cub3d, int flag)
{
	int	value;
	int	i;
	int	j;

	i = 1;
	while (cf[i])
	{
		j = 0;
		while (cf[i][j])
		{
			if (!ft_isdigit(cf[i][j]))
				error("Error: RGB values must contain only digits !\n");
			j++;
		}
		value = ft_atoi(cf[i]);
		if (flag == 0)
			cub3d->textures->c[i - 1] = value;
		else if (flag == 1)
			cub3d->textures->f[i - 1] = value;
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
		if (((!ft_strncmp("C", config[i], 1) || !ft_strncmp("F", config[i], 1))
				&& config[i][1] && !iswhitespaces(config[i][1]))
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

void	count_commas(char *cf)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (cf[i])
	{
		if (cf[i] == ',')
			counter++;
		i++;
	}
	if (counter != 2)
	{
		free(cf);
		error("Error: RGB syntax must comply with (0-255),(0-255),(0-255) !\n");
	}
}

void	parse_c_f(char *cf, t_cub3D *cub3d)
{
	char	**splitted;
	int		size;
	int		i;

	i = 1;
	while (cf[i] && !iswhitespaces(cf[i]))
		i++;
	count_commas(cf);
	if (cf[i] == 'C' || cf[i] == 'F')
		error("Error: RGB syntax must comply with (0-255),(0-255),(0-255) !\n");
	splitted = ft_split2(cf, " ,\t\r");
	size = doublearray_size(splitted);
	if (size != 4)
	{
		free(cf);
		free_mem(splitted);
		error("Error: RGB syntax must comply with (0-255),(0-255),(0-255) !\n");
	}
	if (!ft_strncmp("C", splitted[0], 1))
		check_rgb_values(splitted, cub3d, 0);
	else if (!ft_strncmp("F", splitted[0], 1))
		check_rgb_values(splitted, cub3d, 1);
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
