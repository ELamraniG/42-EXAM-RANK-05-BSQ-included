#pragma once
#include <unistd.h>
#include <stdlib.h>

typedef struct t_game
{
    int width;
    int height;
    int iterations;
    char **mapa;
}Game;