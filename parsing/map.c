#include "../cub3D.h"

void    map_extension(char *map)
{
    char    *extension;
    int     i;
    int     j;

    i = strlen(map) - 1; // ft_strlen
    j = 0;
    extension = calloc(4, sizeof(char)); // ft_calloc
    if (!extension)
        error("Error: Malloc failure!\n");
    while (i && map[i] != '.')
        extension[j++] = map[i--];
    if (map[i] == '.')
        extension[j] = map[i];
    if (strcmp("buc.", extension)) //ft_strcmp
    {
        free(extension);
        error("Error: Map extension must be .cub!\n");
    }
    free(extension);
}

char    *map_path(char *map)
{
    int i;
    int fd;

    i = 0;
    fd = open(map, O_RDONLY);
    if (fd == -1 && !access(map, F_OK))
        error("Error: Permission denied!\n");
    else if (fd == -1)
        error("Error: File not found!\n");
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
		error("Error: Malloc failure!\n");
	while (i > 0 && !ft_strchr(stash, '\0'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0 || (i == 0 && !stash)
			|| (i == 0 && !stash[0]))
			return (free(buff), free(stash), NULL);
		buff[i] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	return (free(buff), stash);
}
