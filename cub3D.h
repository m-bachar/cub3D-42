/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:27 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/03 05:14:06 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFFER_SIZE 1

typedef struct cub3D
{
	char	*c;
	char	*f;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
}	t_cub3D;

		/*	Config.c		*/
void	check_rgb_values(char **cf);
void	count_elements(char **config);
void	parse_c_f(char *cf);
void	check_duplicated(char **config);
void	parse_position(char *position);
void	parse_config(char *config);

		/*	Scene.c			*/
void	map_extension(char *av);
char	*map_path(char *map);
char	*read_map(int fd);

		/*	Tools.c			*/
char	**ft_split2(char *s, char *c);

		/*	Tweaked_funcs.c	*/
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr2(char *s, int c);
int		ft_strcmp(char *s1, char *s2);

		/*	Utils.c			*/
void	free_mem(char **str);
int		doublearray_size(char **array);
void	error(char *str);

#endif
