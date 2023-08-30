/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benito <benito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 00:44:57 by mbachar           #+#    #+#             */
/*   Updated: 2023/08/30 11:53:03 by benito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	map_extension(char *map)
{
	char	*extension;
	int		i;
	int		j;

	i = ft_strlen(map) - 1;
	j = 0;
	extension = malloc(sizeof(char) * i);
	if (!extension)
		error("Error: Malloc failure !\n");
	while (i && map[i] != '.' && map[i])
		extension[j++] = map[i--];
	if (map[i] == '.')
		extension[j++] = map[i];
	extension[j] = '\0';
	if (ft_strncmp("buc.", extension, 4))
	{
		free(extension);
		error("Error: Map extension must be .cub !\n");
	}
	free(extension);
}

char	*map_path(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1 && !access(map, F_OK))
		error("Error: Permission denied !\n");
	else if (fd == -1)
		error("Error: File not found !\n");
	return (read_map(fd));
}

char	*read_map(int fd)
{
	char	*stash;
	char	*buff;
	int		i;

	i = 1;
	stash = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		error("Error: Malloc failure !\n");
	while (i > 0 && !ft_strchr2(stash, '\0'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0 || (i == 0 && !stash) || (i == 0 && !stash[0]))
			return (free(buff), free(stash), NULL);
		buff[i] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	return (free(buff), stash);
}
