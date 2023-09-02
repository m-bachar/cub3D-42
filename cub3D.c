/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/02 04:19:30 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int sizeof_map(char *map)
{
    int i;
    int map_size;

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

char    *extract_config(char *fullmap)
{
    char    *config;
    int     i;
    int     counter;

    i = 0;
    counter = 0;
    while (fullmap[i])
    {
        if (fullmap[i] == '\n' && fullmap[i + 1] && fullmap[i + 1] != '\n')
            counter++;
        i++;
        if (counter == 6)
            break ;
    }
    config = ft_substr(fullmap, 0, i);
    return (config);
}

char    *extract_map(char *fullmap)
{
    char    *map;
    int     i;
    int     counter;

    i = 0;
    counter = 0;
    while (fullmap[i])
    {
        if (fullmap[i] == '\n' && fullmap[i + 1] && fullmap[i + 1] != '\n')
            counter++;
        i++;
        if (counter == 6)
            break ;
    }
    map = ft_substr(fullmap, i, ft_strlen(fullmap));
    return (map);
}

int config_size(char **config)
{
    int i;

    i = 0;
    while (config[i])
        i++;
    if (i != 6)
        return (1);
    return (0);
}

int rgb_values(char **rgb)
{
    int i;
    int value;

    i = 0;
    while (rgb[i])
    {
        value = ft_atoi(rgb[i]);
        if (value >= 0 && value <= 255)
            i++;
        else
            return (1);
    }
    return (0);
}

int rgb_syntax(char **rgb)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (rgb[j])
    {
        while (rgb[j][i])
        {
            if (!ft_isdigit(rgb[j][i]))
                return (1);
            i++;
        }
        i = 0;
        j++;
    }
    return (rgb_values(rgb));
}

int parse_rgb(char **config) // if C or F have tabs before start
{
    char    **rgb;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (config[i])
    {
        while (config[i][j])
        {
            if ((config[i][j] == 'C' || config[i][j] == 'F') && j != 0)
            {
                rgb = ft_split2(config[i], " ,CF"); // Add whitespaces
                if (rgb_syntax(rgb))
                {
                    free_mem(config);
                    free_mem(rgb);
                    error("Error: Rgb syntax error !\n");
                }
                else
                    j++;
            }
            else
                j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

void	parse_config(char *config)
{
	char	**splitted;

	splitted = ft_split(config, '\n');
	if (config_size(splitted))
	{
		free_mem(splitted);
		error("Error: Too many or too few components !\n");
	}
    if (parse_rgb(splitted))
    {
        free_mem(splitted);
		error("Error: RGB must comply with the following syntax (0-255),(0-255),(0-255) !\n");
    }
}

int main(int ac, char **av)
{
    char    *fullmap;
    char    *map;
    char    *config;
    int      map_size;

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
	printf("%s", config);
	// printf("%s", map);
    free(fullmap);
    free(config);
    free(map);
}
