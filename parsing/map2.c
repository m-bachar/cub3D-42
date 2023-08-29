/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:34:35 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/29 17:34:38 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	**extract_config(char **splitted)
{
	char	**config;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (splitted[i][0] != '1' && splitted[i][0] != '0')
		i++;
	config = malloc(sizeof(splitted) * (i + 1));
	if (!config)
		error("Error: Malloc failure !\n");
	i = 0;
	while (splitted[i][0] != '1' && splitted[i][0] != '0')
		config[j++] = splitted[i++];
	config[j] = NULL;
	if (j > 6)
		error("Error: Too many components !\n");
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
		error("Error: Malloc failure !\n");
	i = 6;
	while (splitted[i])
		map[j++] = splitted[i++];
	map[j] = NULL;
	return (map);
	// free splitted?
}

void	count_commas(char *str)
{
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split2(str, " ,"); // Add whitespaces
	while (splitted[i])
		i++;
	free_mem(splitted);
	if (i != 4)
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
		if (str[i] == ',' || !str[i])
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
	free(value);
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
	// free path?
}

void	check_duplicated(char *map)
{
	char	**splitted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	splitted = ft_split2(map, " \n"); // Add whitespaces
	while (i < 12)
	{
		if (j == 12)
		{
			j = 0;
			i += 2;
		}
		if (!ft_strcmp(splitted[i], splitted[j]) && i != j)
		{
			free_mem(splitted);
			error("Error: Duplicated components !\n");
		}
		else
			j += 2;
	}
}

void	parse_config(char *config)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (config[i])
	{
		if ((config[i] == 'C' || config[i] == 'F') && config[i + 1] == ' ') // Add whitespaces
		{
			count_commas(config);
			check_rgb_syntax(config, i + 1);
			check_rgb_values(config, i + 1);
			flag++;
		}
		else if (((config[i] == 'N' && config[i + 1] == 'O') || (config[i] == 'S' && config[i + 1] == 'O') || (config[i] == 'E' && config[i + 1] == 'A') || (config[i] == 'W' && config[i + 1] == 'E')) && config[i + 2] == ' ') // Add whitespaces
		{
			check_xpm_path(config, i + 2);
			flag++;
		}
		else if (!flag)
			error("Error: Missing component from configs !\n");
		i++;
	}
}
