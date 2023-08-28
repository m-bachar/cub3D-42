/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:32:27 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/28 16:45:51 by mbachar          ###   ########.fr       */
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

void	error(char *str);
void	map_extension(char *av);
char	*map_path(char *map);
char	*ft_strjoin(char *s1, char *s2);
char	*read_map(int fd);
int		ft_strchr2(char *s, int c);
char	**ft_split2(char *s, char *c);
void	free_mem(char **str);

#endif
