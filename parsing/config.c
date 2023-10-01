/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:16:18 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/01 21:10:35 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_rgb_values(char **cf)
{
	int	value;
	int	i;
	int	j;

	i = 0;
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

void	parse_c_f(char *cf)
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
	splitted = ft_split2(cf, " CF,\t\r");
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

void	read_and_store(int fd, char **config, t_cub3D *cub3d)
{
	int	x;
	int	y;
	(void)fd;
	if (!ft_strcmp(config[0], "NO"))
		cub3d->textures->no = mlx_xpm_file_to_image(cub3d->mlx, config[1], &x, &y);
	else if (!ft_strcmp(config[0], "SO"))
		cub3d->textures->so = mlx_xpm_file_to_image(cub3d->mlx, config[1], &x, &y);
	else if (!ft_strcmp(config[0], "WE"))
		cub3d->textures->we = mlx_xpm_file_to_image(cub3d->mlx, config[1], &x, &y);
	else if (!ft_strcmp(config[0], "EA"))
		cub3d->textures->ea = mlx_xpm_file_to_image(cub3d->mlx, config[1], &x, &y);
	// if (!cub3d->textures->no || !cub3d->textures->no[0]
	// 	|| !cub3d->textures->so || !cub3d->textures->so[0]
	// 	|| !cub3d->textures->we || !cub3d->textures->we[0]
	// 	|| !cub3d->textures->ea || !cub3d->textures->ea[0])
	// 	error("Error: One of the XPM files is empty !\n");
}

void	parse_position(char *position, t_cub3D *cub3d)
{
	(void)cub3d;
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
		read_and_store(fd, splitted, cub3d);
	free_mem(splitted);
}
