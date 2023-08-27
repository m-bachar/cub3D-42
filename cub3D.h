#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

void    error(char *str);
void    map_extension(char *av);
char    *map_path(char *map);
char	*ft_strjoin(char *s1, char *s2);
int	    ft_strchr(char *s, int c);
char	*read_map(int fd);

#endif
