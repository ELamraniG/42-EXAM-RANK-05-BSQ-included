#include "life.h"

void init_game(Game *game) {
  game->mapa = malloc(sizeof(char *) * game->height);
  for (int y = 0; y < game->height; y++) {
    game->mapa[y] = malloc(sizeof(char) * (game->width));
    for (int x = 0; x < game->width; x++)
      game->mapa[y][x] = ' ';
  }
}

void fill_game(Game *game) {
  int pen = 0;
  char s[1];
  int x = 0;
  int y = 0;
  while (read(0, s, 1) == 1) {
    if (s[0] == 'a') {
      if (x > 0)
        x--;
    }
    if (s[0] == 'w') {
      if (y > 0)
        y--;
    }
    if (s[0] == 'd') {
      if (x < game->width - 1)
        x++;
    }
    if (s[0] == 's') {
      if (y < game->height - 1)
        y++;
    }
    if (s[0] == 'x')
      pen = !pen;
    if (pen == 1)
      game->mapa[y][x] = 'O';
  }
}

int calculate_neighbors(Game *game, int cy, int cx) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue;
      int nx = cx + j;
      int ny = cy + i;
      if (nx >= 0 && nx < game->width && ny >= 0 && ny < game->height)
        if (game->mapa[ny][nx] == 'O')
          count++;
    }
  }
  return count;
}

void play_game(Game *game) {
  char **newmapa;
  newmapa = malloc(sizeof(char *) * game->height);
  for (int y = 0; y < game->height; y++) {
    newmapa[y] = malloc(sizeof(char) * (game->width));
  }
  for (int y = 0; y < game->height; y++) {
    for (int x = 0; x < game->width; x++) {
      int cn = calculate_neighbors(game, y, x);
      if (game->mapa[y][x] == 'O')
        if (cn == 2 || cn == 3)
          newmapa[y][x] = 'O';
        else
          newmapa[y][x] = ' ';
      else if (cn == 3)
        newmapa[y][x] = 'O';
      else
        newmapa[y][x] = ' ';
    }
  }
  for (int y = 0; y < game->height; y++)
    free(game->mapa[y]);
  free(game->mapa);
  game->mapa = newmapa;
}
int main(int ac, char **av) {
  if (ac != 4)
    return 0;

  Game game;
  game.width = atoi(av[1]);
  game.height = atoi(av[2]);
  game.iterations = atoi(av[3]);
  init_game(&game);
  fill_game(&game);

  for (int i = 0; i < game.iterations; i++)
    play_game(&game);
  for (int i = 0; i < game.height; i++) {
    for (int j = 0; j < game.width; j++)
      write(1, &game.mapa[i][j], 1);
    write(1, "\n", 1);
  }
  for (int i = 0; i < game.height; i++)
    free(game.mapa[i]);
  free(game.mapa);
  return 0;
}