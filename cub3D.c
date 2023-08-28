/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/28 19:25:31 by mbachar          ###   ########.fr       */
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

char	**extract_config(char **splitted)
{
	char	**config;
	int		i;
	int		j;

	i = 0;
	j = 0;
	config = malloc(sizeof(splitted) * 7);
	if (!config)
		error("Error: Malloc failure!\n");
	while (i < 6)
		config[j++] = splitted[i++];
	config[j] = NULL;
	return (config);
}

char	**extract_map(char **splitted)
{
	char	**map;
	int		i;
	int		j;

	i = 6;
	j = 0;
	while (splitted[i])
		i++;
	map = malloc(sizeof(splitted) * (i + 1));
	if (!map)
		error("Error: Malloc failure!\n");
	i = 6;
	while (splitted[i])
		map[j++] = splitted[i++];
	map[j] = NULL;
	return (map);
}

void	count_commas(char *str)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == ',')
			counter++;
		i++;
	}
	if (counter != 2)
		error("Error: RGB code must comply with the following syntax (0-255),(0-255),(0-255) !\n");
}

void	check_rgb_syntax(char *str, int i)
{
	while (str[i] && str[i] == ' ') // Add whitespaces
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			error("Error: RGB code must contain only digits and 2 commas !\n");
		i++;
	}
}

int	check_value(char *str)
{
	int	x;

	x = ft_atoi(str);
	if (x >= 0 && x <= 255)
		return (1);
	return (error("Error: RGB value must be between 0 and 255 !\n"), 0);
}

void	check_rgb_values(char *str, int i)
{
	char	*value;
	int		j;

	j = 0;
	value = malloc(sizeof(char) * 1000000); // Fix allocated size
	if (!value)
		error("Error: Malloc failure !\n");
	while (str[i] && str[i] == ' ') // Add whitespaces
		i++;
	while (str[i])
	{
		if (str[i] == ',')
		{
			value[j] = '\0';
			if (check_value(value))
			{
				j = 0;
				i++;
			}
		}
		if (!str[i])
			break ;
		value[j++] = str[i++];
	}
}

void	check_xpm_path(char *str, int i)
{
	char	*path;
	int		j;
	int		fd;

	j = 0;
	while (str[i] && str[i] == ' ') // Add whitespaces
		i++;
	j = i;
	while (str[j])
		j++;
	path = ft_substr(str, i, j - i);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("Error: Unable to access xpm file !\n");
}

void	parse_config(char *config)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (config[i])
	{
		if (config[i] == 'C' || config[i] == 'F')
		{
			count_commas(config);
			check_rgb_syntax(config, i + 1);
			check_rgb_values(config, i + 1);
			flag++;
		}
		else if ((config[i] == 'N' && config[i + 1] == 'O') || (config[i] == 'S' && config[i + 1] == 'O') || (config[i] == 'E' && config[i + 1] == 'A') || (config[i] == 'W' && config[i + 1] == 'E'))
		{
			check_xpm_path(config, i + 2);
			flag++;
		}
		else if (!flag)
			error("Error: Missing component from configs ! \n");
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**splitted;
	char	**map;
	char	**config;
	int		i;

	splitted = NULL;
	i = 0;
	if (ac < 2)
		error("Error: Missing map path!\n");
	else if (ac > 2)
		error("Error: Too many arguments!\n");
	map_extension(av[1]);
	splitted = ft_split(map_path(av[1]), '\n');
	config = extract_config(splitted);
	map = extract_map(splitted);
	while (config[i])
		parse_config(config[i++]);
}
