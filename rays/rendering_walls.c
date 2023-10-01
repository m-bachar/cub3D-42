/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:40:36 by mbachar           #+#    #+#             */
/*   Updated: 2023/10/01 00:59:23 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    draw_map_3d(t_cub3D *cub3d, int colomn)
{
    double      wall_height;
    int         start_wall;
    int         end_wall;
    int         line;
    int         color;

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
            color = BLACK;
        else if ((line >= start_wall) && (line <= end_wall))
            color = OUSSAMA_CHOUFOUNI;
        else if (line > end_wall)
            color = GREY;
        my_mlx_pixel_put(cub3d, colomn, line, color);
        line++;
    }

    // unsigned int	tex;
    // int				offset_y;
    // int				offset_x;
    // int				y;
    // int				distance_top;
    

    // if(cub3d->hit_v)
    //     offset_x = ((int)cub3d->ray->y_f_wall % 64);
    // else
    //     offset_x = ((int)cub3d->ray->x_f_wall % 64);
    // y = start_wall;
    // while (y < end_wall)
    // {
    //     distance_top = y + (wall_height / 2) - (cub3d->w_height / 2);
    //     offset_y = distance_top * ((float)64 / wall_height);//return here
    //     tex = cub3d->textures->no[(64 * offset_y) + offset_x];
    //     color = tex;
    //     my_mlx_pixel_put(cub3d, colomn, y, color);
    //     y++;
    // }
}


// void    put_texture_bouk(t_cub3D *cub3d)
// {
    
// }

// void	get_correct_texture(t_maps *maps, int i, int wall_top, int wall_bot)
// {
// 	int	y;

// 	y = -1;
// 	while (++y < wall_top)
// 		maps->tex.color_buff[(maps->width * y) + i] = maps->ceiling;
// 	y = wall_bot - 1;
// 	while (++y < 720)
// 		maps->tex.color_buff[(maps->width * y) + i] = maps->floor;
// 	if (maps->rays.wall_hit_vert[i] && maps->rays.ray_right[i])
// 		maps->tex.wall_tex = maps->tex.tex_we;
// 	if (maps->rays.wall_hit_vert[i] && maps->rays.ray_left[i])
// 		maps->tex.wall_tex = maps->tex.tex_ea;
// 	if (!maps->rays.wall_hit_vert[i] && maps->rays.ray_up[i])
// 		maps->tex.wall_tex = maps->tex.tex_no;
// 	if (!maps->rays.wall_hit_vert[i] && maps->rays.ray_down[i])
// 		maps->tex.wall_tex = maps->tex.tex_so;
// 	if (maps->rays.content[i] == 'D')
// 		maps->tex.wall_tex = maps->tex.door;
// }

// void	fill_color_buff(t_maps *maps, int wall_top, int wall_bot, int i)
// {
// 	unsigned int	tex;
// 	int				offset_y;
// 	int				offset_x;
// 	int				y;
// 	int				distance_top;

// 	if (maps->rays.wall_hit_vert[i])
// 		offset_x = (int)maps->rays.wall_hit_y[i] % 64;
// 	else
// 		offset_x = (int)maps->rays.wall_hit_x[i] % 64;
// 	y = wall_top - 1;
// 	while (++y < wall_bot)
// 	{
// 		distance_top = y + ((int)maps->rays.projected_wall_height / 2) - (720 / 2);
// 		offset_y = distance_top * ((float)64 / maps->rays.projected_wall_height);//return here
// 		tex = maps->tex.wall_tex[(64 * offset_y) + offset_x];
// 		maps->tex.color_buff[(maps->width * y) + i] = tex;
// 	}
// }

// double	fish_eye(t_maps *maps, int i)
// {
// 	return ((maps->rays.angle[i] * (M_PI / 180))
// 		- (maps->angle * (M_PI / 180)));
// }

// void	fill_3d_projection(t_maps *maps)
// {
// 	float	distance;
// 	int		wall_top;
// 	int		wall_bot;
// 	int		i;

// 	i = -1;
// 	while (++i < maps->width)
// 	{
// 		distance = (maps->rays.ray_distance[i] * cos(fish_eye(maps, i)));
// 		maps->rays.projected_wall_height = ((64 * maps->width) / distance);
// 		wall_top = (720 / 2) - ((int)maps->rays.projected_wall_height / 2);
// 		if (wall_top < 0)
// 			wall_top = 0;
// 		wall_bot = (720 / 2) + ((int)maps->rays.projected_wall_height / 2);
// 		if (wall_bot > 720)
// 			wall_bot = 720;
// 		get_correct_texture(maps, i, wall_top, wall_bot);
// 		fill_color_buff(maps, wall_top, wall_bot, i);
// 	}
// }
