/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:27 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/29 18:08:07 by mbachar          ###   ########.fr       */
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

		/*	Utils.c			*/
void	error(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr2(char *s, int c);
void	free_mem(char **str);
int	    ft_strcmp(char *s1, char *s2);

		/*	Tools.c			*/
char	**ft_split2(char *s, char *c);

		/*	Map1.c			*/
void	map_extension(char *av);
char	*map_path(char *map);
char	*read_map(int fd);

		/*	Map2.c	*/
char	**extract_config(char **splitted);
char	**extract_map(char **splitted);
void	count_commas(char *str);
void	check_rgb_syntax(char *str, int i);
int		check_value(char *str);
void	check_rgb_values(char *str, int i);
void	check_xpm_path(char *str, int i);
void	check_duplicated(char *map);
void	parse_config(char *config);

		/*	Map3.c			*/
void    check_perimeter(char **map);

#endif
