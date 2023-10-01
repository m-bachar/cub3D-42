#include "cub3D.h"

int main()
{
    char *map[4] = {
        "123",//0
        "456",//1
        "789",//2
        NULL
    };
    char *str = "123456789";

    printf("%s", str + (3 * 2 + 0));
}