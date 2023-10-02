/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:40:36 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/02 04:56:23 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int ft_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// int	get_ofset_colomn(t_ply *data)
// {
// 	int		x;
// 	char	*view;

// 	x = 0;
// 	view = check_view(data);
// 	if (data->check_h_v == 0)
// 		x = fmod(data->x_wall, NUM_PIXELS);
// 	else if (data->check_h_v == 1)
// 		x = fmod(data->y_wall, NUM_PIXELS);
// 	if (data->check_h_v == 1
// 		&& (!ft_strcmp(view, "down_right") || !ft_strcmp(view, "up_left")))
// 		data->img = data->img_w;
// 	else if (data->check_h_v == 1)
// 		data->img = data->img_e;
// 	else if (data->check_h_v == 0
// 		&& (!ft_strcmp(view, "up_right") || !ft_strcmp(view, "up_left")))
// 		data->img = data->img_n;
// 	else
// 		data->img = data->img_s;
// 	return (x);

// 	//-----------------

// 	void	draw_map_3d(t_ply *data, int colomn)
// {
// 	int	s_e_h_wall[3];
// 	int	x_y_cl[3];
// 	int	line;

// 	data->len_ray = data->len_ray * cos(data->fov - data->face_rad);//fish eye
// 	s_e_h_wall[2] = (data->width_of_win * NUM_PIXELS) / ((data->len_ray));
// 	s_e_h_wall[0] = cal_str_wall(data->height_of_win, s_e_h_wall[2]);
// 	s_e_h_wall[1] = cal_end_wall(data->height_of_win, s_e_h_wall[2]);
// 	x_y_cl[0] = get_ofset_colomn(data);
// 	line = -1;
// 	while (++line < data->height_of_win - 1)
// 	{
// 		if (line < s_e_h_wall[0])
// 			x_y_cl[2] = to_rgb(data->c_1, data->c_2, data->c_3);
// 		else if ((line >= s_e_h_wall[0]) && (line <= s_e_h_wall[1] - 1))
// 		{
// 			x_y_cl[1] = line + (s_e_h_wall[2] / 2) - (data->height_of_win / 2);
// 			x_y_cl[1] = x_y_cl[1] * ((double)NUM_PIXELS / s_e_h_wall[2]);
// 			x_y_cl[2] = data->img->tab_color[(NUM_PIXELS * x_y_cl[1]) + x_y_cl[0]];
// 		}
// 		else if (line > s_e_h_wall[1])
// 			x_y_cl[2] = to_rgb(data->f_1, data->f_2, data->f_3);
// 		my_mlx_pixel_put(data->mydata, colomn, line, x_y_cl[2]);
// 	}
// }


void	draw_map_3d(t_cub3D *cub3d, int colomn)
{
	int	wall_height;
	int	start_wall;
	int	end_wall;
	int	line;
	int	color;
	unsigned int 	*d;

	if (cub3d->hit_v && cub3d->ray->ray_right && !cub3d->ray->ray_left && !cub3d->hit_h)
		d = cub3d->textures->ea;
	else if (cub3d->hit_v && !cub3d->ray->ray_right && cub3d->ray->ray_left && !cub3d->hit_h)
		d = cub3d->textures->we;
	else if (cub3d->hit_h && !cub3d->ray->ray_up && cub3d->ray->ray_down && !cub3d->hit_v)
		d = cub3d->textures->so;
	else if (cub3d->hit_h && !cub3d->ray->ray_down &&  cub3d->ray->ray_up && !cub3d->hit_v)
		d = cub3d->textures->no;
	cub3d->ray->distance = cub3d->ray->distance * cos(deg_to_rad(cub3d->angle) - cub3d->rad_a);
	color = 0;
	wall_height = (cub3d->w_width * cub3d->tile) / ((cub3d->ray->distance));
	start_wall = (cub3d->w_height / 2) - (wall_height / 2);
	end_wall = (cub3d->w_height / 2) + (wall_height / 2);
	if (start_wall <= 0)
		start_wall = 0;
	if (end_wall >= cub3d->w_height)
		end_wall = cub3d->w_height;
	line = 0;
	while (line < cub3d->w_height - 1)
	{
		if (line < start_wall)
			// color = ft_rgb(cub3d->textures->c[0], cub3d->textures->c[1], cub3d->textures->c[3]);
			color = ft_rgb(33, 41, 128);
		else if ((line >= start_wall) && (line <= end_wall - 1))
		{
			int				x=0;
			unsigned int	c;
			if (cub3d->hit_h == 1)
				x = fmod(cub3d->ray->x_f_wall, 64);
			else if (cub3d->hit_v == 1)
				x = fmod(cub3d->ray->y_f_wall, 64);
			c = line + (wall_height / 2) - (cub3d->w_height / 2);
			c = c * ((double)64 / wall_height);
			color = d[(64 * c) + x];
		}
		else if (line > end_wall)
			// color = ft_rgb(cub3d->textures->f[0], cub3d->textures->f[1], cub3d->textures->f[2]);
			color = ft_rgb(62, 63, 64);
		my_mlx_pixel_put(cub3d, colomn, line, color);
		line++;
	}
}

void    tex(t_cub3D *cub3d, char *path, unsigned int **tex)
{
    t_imgs            wall_img;
    unsigned char    rgb[3];
    int                bytes_per_pixel;
    int                i;
    int                y;

    wall_img.img = mlx_xpm_file_to_image(cub3d->mlx, path, &i, &y);
    if (!wall_img.img || i != 64 || y != 64)
        return (error("Error\nBad Image\n"));//freee everything
    wall_img.addr = mlx_get_data_addr(wall_img.img, &wall_img.bits_per_pixel,
            &wall_img.line_length, &wall_img.endian);
    bytes_per_pixel = wall_img.bits_per_pixel / 8;
    *tex = malloc(sizeof(unsigned int) * 64 * 64);
    if (!(*tex))
        return (error("Error\nMalloc Error\n"));//free everything
    i = -1;
    while (++i < 64 * 64)
    {
        rgb[0] = wall_img.addr[i * bytes_per_pixel + 2];
        rgb[1] = wall_img.addr[i * bytes_per_pixel + 1];
        rgb[2] = wall_img.addr[i * bytes_per_pixel];
        tex[0][i] = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
		// printf("tex ==== %d\n",tex[0][i]);
    }
}
