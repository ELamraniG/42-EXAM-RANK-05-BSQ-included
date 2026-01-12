#include <unistd.h>
#include <stdlib.h>
typedef struct s_map
{
    char **mapa;
    int width;
    int height;
    int iter;
}t_game;
#include <stdio.h>


void init_game(t_game *game)
{
    game->mapa = (char **) malloc(sizeof(char *) * game->height);
    for (int i = 0; i < game->height;i++)
    {
        game->mapa[i] = (char*) malloc(sizeof(char) * (game->width));
        for (int j = 0; j < game->width;j++)
            game->mapa[i][j] = ' ';
    }
}

void move_game(t_game *game)
{
    char buff[1];
    int x = 0;
    int y = 0;
    int pen = 0;
    while (read(0,buff,1) > 0)
    {
        char c = buff[0];
        if (c == 'w')
        {
            if (y > 0)
                y--;
        }
        if (c == 's')
        {
            if (y < game->height - 1)
                y++;
        }   
        if (c == 'a')
        {
            if (x > 0)
                x--;
        }
        if (c == 'd')
        {
            if (x < game->width - 1)
                x++;
        }
        if (c == 'x') 
            pen = !pen;
        if (pen == 1)
        {
            game->mapa[y][x] = 'O';
        }
    }

}

int count_nightbors(int oy,int ox,t_game *game)
{
    int nb = 0;
    int nx = 0;
    int ny = 0;
    for (int i = -1; i <= 1;i++)
    {
        for (int j = -1; j <= 1;j++)
        {
            if (i == 0 && j == 0)
                continue;
            ny = i + oy;
            nx = j + ox;
            if (nx >= 0 && nx < game->width && ny >= 0 && ny < game->height)
                if (game->mapa[ny][nx] == 'O')
                    nb++;
        }
    }
    return nb;
}

void play_game(t_game *game)
{
    char **new_map;
    new_map = (char **) malloc(sizeof(char *) * game->height);
    for (int i = 0; i < game->height;i++)
    {
        new_map[i] = (char*) malloc(sizeof(char) * (game->width + 1));
        new_map[i][game->width] = 0;
    }
    for (int i = 0;i < game->height;i++)
    {
        for (int j = 0;j < game->width;j++)
        {
            if(game->mapa[i][j] == 'O')
            {
                if (count_nightbors(i,j,game) == 2 || count_nightbors(i,j,game) == 3)
                {
                    new_map[i][j] = 'O';
                }
                else
                    new_map[i][j] = ' ';
            }
            if(game->mapa[i][j] == ' ')
            {
                if (count_nightbors(i,j,game) == 3)
                    new_map[i][j] = 'O';
                else
                    new_map[i][j] = ' ';
            }
        }
    }
    for (int i = 0;i < game->height;i++)
    {
        free(game->mapa[i]);
    }
    free(game->mapa);
    game->mapa = new_map;
}

int main(int ac,char **av)
{
    if (ac != 4)
        return 1;
    t_game game;
    game.width = atoi(av[1]);
    game.height = atoi(av[2]);
    game.iter = atoi(av[3]);
    init_game(&game);
    move_game(&game);
    for (int i = 0; i < game.iter;i++)
        play_game(&game);
    for (int i = 0;i < game.height;i++)
    {
        for (int j = 0; j < game.width;j++)
            write(1,&(game.mapa[i][j]),1);
        write(1,"\n",1);
    }
    return 0;
}