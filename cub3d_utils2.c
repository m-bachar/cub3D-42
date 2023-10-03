/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 06:06:30 by obouya            #+#    #+#             */
/*   Updated: 2023/10/03 16:16:18 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_mlx(t_cub3D *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->window = mlx_new_window(cub3d->mlx, cub3d->w_width,
			cub3d->w_height, "Cub3D");
	cub3d->img = mlx_new_image(cub3d->mlx, cub3d->w_width, cub3d->w_height);
	cub3d->addr = mlx_get_data_addr(cub3d->img,
			&cub3d->bits_per_pixel, &cub3d->line_length, &cub3d->endian);
}

void	max_x_y(t_cub3D *cub3d)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	cub3d->map_y_max = doublearray_size(cub3d->map);
	while (cub3d->map[i])
	{
		size = ft_strlen(cub3d->map[i]);
		if (size >= cub3d->map_x_max)
			cub3d->map_x_max = size;
		i++;
	}
}

int	longest_line(char **map)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (map[j])
	{
		if ((int)ft_strlen(map[j]) >= len)
			len = ft_strlen(map[j]);
		j++;
	}
	return (len);
}

char	*copy_line(char *src, char *dst, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
		dst[j++] = src[i++];
	while (j < len)
	{
		dst[j] = '#';
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

void	fillmap(t_cub3D *cub3d)
{
	char	**new_map;
	int		counter;
	int		j;

	j = 0;
	counter = 0;
	new_map = malloc(sizeof(char *) * (doublearray_size(cub3d->map) + 1));
	while (cub3d->map[j])
	{
		new_map[j] = malloc(sizeof(char) * \
			((counter * 4) + (longest_line(cub3d->map) + 1)));
		new_map[j] = copy_line(cub3d->map[j],
				new_map[j], longest_line(cub3d->map));
		j++;
	}
	new_map[j] = NULL;
	free_mem(cub3d->map);// i added this free to handle leaks
	cub3d->map = new_map;
}
