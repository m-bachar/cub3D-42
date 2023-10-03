/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:40:36 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/03 02:00:18 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	find_color(t_cub3D *cub3d, t_3d_var *vars_3d)
{
	if (cub3d->hit_h == 1)
		vars_3d->x = fmod(cub3d->ray->x_f_wall, 64);
	else if (cub3d->hit_v == 1)
		vars_3d->x = fmod(cub3d->ray->y_f_wall, 64);
	vars_3d->c = vars_3d->line + (vars_3d->w_height / 2) \
	- (cub3d->w_height / 2);
	vars_3d->c = vars_3d->c * ((double)64 / vars_3d->w_height);
	vars_3d->color = vars_3d->d[(64 * vars_3d->c) + vars_3d->x];
}

void	draw_map_3d(t_cub3D *cub3d, int colomn)
{
	t_3d_var	*vars_3d;

	vars_3d = malloc(sizeof(t_3d_var));
	init_vars_3d(vars_3d);
	ft_store_image(cub3d, vars_3d);
	wall_info_fish_eye(cub3d, vars_3d);
	vars_3d->line = 0;
	while (vars_3d->line < cub3d->w_height - 1)
	{
		if (vars_3d->line < vars_3d->wall_beg)
			vars_3d->color = ft_rgb(cub3d->textures->c[0], \
			cub3d->textures->c[1], cub3d->textures->c[2]);
		else if ((vars_3d->line >= vars_3d->wall_beg)
			&& (vars_3d->line <= vars_3d->wall_end - 1))
			find_color(cub3d, vars_3d);
		else if (vars_3d->line > vars_3d->wall_end)
			vars_3d->color = ft_rgb(cub3d->textures->f[0], \
			cub3d->textures->f[1], cub3d->textures->f[2]);
		my_mlx_pixel_put(cub3d, colomn, vars_3d->line, vars_3d->color);
		vars_3d->line++;
	}
	free(vars_3d);
}

void	tex(t_cub3D *cub3d, char *path, unsigned int **tex)
{
	t_imgs			wall_img;
	unsigned char	rgb[3];
	int				bytes_per_pixel;
	int				i;
	int				j;

	wall_img.img = mlx_xpm_file_to_image(cub3d->mlx, path, &i, &j);
	if (!wall_img.img || i != 64 || j != 64)
		return (error("Error: Bad Image !\n")); //mbachar must  add a free function here
		 //in the return(free and destroy mlx) before exit
	wall_img.addr = mlx_get_data_addr(wall_img.img, &wall_img.bits_per_pixel,
			&wall_img.line_length, &wall_img.endian);
	bytes_per_pixel = wall_img.bits_per_pixel / 8;
	*tex = malloc(sizeof(unsigned int) * 64 * 64);
	if (!(*tex))
		return (error("Error: Malloc Error !\n")); ///mbachar must  add a free function here
		 //in the return(free and destroy mlx) before exit
	i = -1;
	while (++i < 64 * 64)
	{
		rgb[0] = wall_img.addr[i * bytes_per_pixel + 2];
		rgb[1] = wall_img.addr[i * bytes_per_pixel + 1];
		rgb[2] = wall_img.addr[i * bytes_per_pixel];
		tex[0][i] = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	}
}
