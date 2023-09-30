/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:16:18 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/01 00:06:35 by mbachar          ###   ########.fr       */
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

void	read_and_store(t_cub3D *cub3d, char *path, unsigned int **texture)
{
    t_cub3D				wall; // separate them
    unsigned char		rgb[3];
    int					bytes_per_pixel;
    int					i;
    int					y;

    wall.img = mlx_xpm_file_to_image(cub3d->mlx, path, &i, &y);
    if (!wall.img || i != 64 || y != 64)
        return (error("Error: Bad Image !\n"));
    wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel,
            &wall.line_length, &wall.endian);
    bytes_per_pixel = wall.bits_per_pixel / 8;
    *texture = malloc(sizeof(unsigned int) * 64 * 64);
    if (!(*texture))
        return (error("Error: Malloc Failure !\n"));
    i = -1;
    while (++i < 64 * 64)
    {
        rgb[0] = wall.addr[i * bytes_per_pixel + 2];
        rgb[1] = wall.addr[i * bytes_per_pixel + 1];
        rgb[2] = wall.addr[i * bytes_per_pixel];
        texture[0][i] = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
    }
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
	{
		read_and_store(cub3d, splitted[1], &cub3d->textures->no);
		read_and_store(cub3d, splitted[1], &cub3d->textures->so);
		read_and_store(cub3d, splitted[1], &cub3d->textures->ea);
		read_and_store(cub3d, splitted[1], &cub3d->textures->we);
	}
	free_mem(splitted);
}
