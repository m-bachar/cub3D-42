/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouya <obouya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:22:22 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/03 15:46:44 by obouya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	update(t_cub3D *cub3d)
{
	init_vars_update(cub3d);
	key_player(cub3d);
	cub3d->i = cub3d->angle - 30;
	mlx_destroy_image(cub3d->mlx, cub3d->img);
	mlx_clear_window(cub3d->mlx, cub3d->window);
	cub3d->img = mlx_new_image(cub3d->mlx, cub3d->w_width, cub3d->w_height);
	cub3d->addr = mlx_get_data_addr(cub3d->img, &cub3d->bits_per_pixel,
			&cub3d->line_length, &cub3d->endian);
	while (cub3d->i < cub3d->angle + 30)
	{
		if (cub3d->j == 0)
		{
			cub3d->angle2 = cub3d->angle - 30;
			cub3d->j = 1;
		}
		update2(cub3d);
		draw_map_3d(cub3d, cub3d->k);
		cub3d->angle2 += cub3d->fov / cub3d->w_width;
		ft_normalize_angle2(cub3d);
		cub3d->i += cub3d->fov / cub3d->w_width;
		cub3d->k++;
	}
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->img, 0, 0);
	return (0);
}

void	ft_init_vars(t_cub3D *cub3d)
{
	cub3d->fov = 60;
	cub3d->xp_c = 0;
	cub3d->yp_c = 0;
	cub3d->speed = 10;
	cub3d->radius = 6;
	cub3d->w_height = 720;
	cub3d->w_width = 1080;
	cub3d->rotation_speed = 5;
	cub3d->flag = 0;
	cub3d->wall_h_x = 0;
	cub3d->wall_h_y = 0;
	cub3d->wall_v_x = 0;
	cub3d->wall_v_y = 0;
	cub3d->map_x_max = 0;
	cub3d->map_y_max = 0;
	cub3d->tile = 64;
	cub3d->i = 0;
	cub3d->j = 0;
	cub3d->k = 0;
}

void	ft_init_vars2(t_cub3D *cub3d)
{
	cub3d->ray = malloc(sizeof(t_rays));
	cub3d->ray->distance = 0;
	cub3d->ray->x_f_wall = 0;
	cub3d->ray->y_f_wall = 0;
	cub3d->textures = malloc(sizeof(t_textures));
	cub3d->textures->c = malloc(sizeof(int) * 4);
	cub3d->textures->f = malloc(sizeof(int) * 4);
	cub3d->textures->c[0] = 0;
	cub3d->textures->c[1] = 0;
	cub3d->textures->c[2] = 0;
	cub3d->textures->c[3] = '\0';
	cub3d->textures->f[0] = 0;
	cub3d->textures->f[1] = 0;
	cub3d->textures->f[2] = 0;
	cub3d->textures->f[3] = '\0';
	cub3d->right_key = 0;
	cub3d->left_key = 0;
	cub3d->down_key = 0;
	cub3d->up_key = 0;
	cub3d->left_angle_key = 0;
	cub3d->right_angle_key = 0;
}

void	parsing_total(int ac, char **av, t_cub3D *cub3d)
{
	if (ac < 2)
		error("Error: Missing map path !\n");
	else if (ac > 2)
		error("Error: Too many arguments !\n");
	parsing(av[1], cub3d);
	fillmap(cub3d);
	check_player_surrounding2(cub3d->map);
	// for (int i = 0; i < doublearray_size(cub3d->map); i++)
	// 	printf("%s\n", cub3d->map[i]);
	max_x_y(cub3d);
}

int	main(int ac, char **av)
{
	t_cub3D	cub3d;
	char	*protection;

	protection = malloc(sizeof(char) * 0);
	if (!protection)
		return (1);
	ft_init_vars(&cub3d);
	ft_init_vars2(&cub3d);
	ft_mlx(&cub3d);
	parsing_total(ac, av, &cub3d);
	player_position(&cub3d);
	ft_find_angle(&cub3d);
	mlx_hook(cub3d.window, 2, 0, key_player_press, &cub3d);
	mlx_hook(cub3d.window, 3, 0, key_player_release, &cub3d);
	mlx_loop_hook(cub3d.mlx, update, &cub3d);
	mlx_loop(cub3d.mlx);
	free_mem(cub3d.config);
	free_mem(cub3d.map);
}
