#include "cub3D.h"

void    error(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(2, &str[i++], 1);
    exit (1);
}


int main(int ac, char **av)
{
    if (ac < 2)
        error("Error: Missing map path!\n");
    else if (ac > 2)
        error("Error: Too many arguments!\n");
    map_extension(av[1]);
    printf("%s\n", map_path(av[1]));
}
