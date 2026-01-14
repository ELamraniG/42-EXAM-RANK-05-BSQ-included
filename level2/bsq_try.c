#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define max 1000

enum
{
    EMPTY,OBSTACLE,FULL
};

typedef struct s_bsq
{
    int x;
    int y;
    int size;
}t_bsq;


typedef struct s_data
{
    int x;
    int y;
    t_bsq bsq;
    char obstacle,full,empty;
    int map[max][max];
}t_data;

int get_min(int a,int b,int c)
{
    int small;
    if (a < b)
        small = a;
    else
        small = b;
    if (c < small)
        small = c;
    return small;
}

int read_map(FILE *file,t_data *data)
{
    if (fscanf(file,"%d %c %c %c\n",&data->y,&data->empty,&data->obstacle,&data->full) != 4 || data->y < 1)
    {
        return -1;
    }
    if (data->empty == data->obstacle || data->empty == data->full || data->obstacle == data->full)
        return -1;
    
    char *line = NULL;
    size_t read_size = 0;
    int y = 0;
    while (y < data->y && getline(&line,&read_size,file) != -1)
    {
        int len = strlen(line);
        if (line[len - 1] == '\n')
            line[--len] = 0;
        if (len == 0 || len > max)
        {
            free(line);
            return -1;
        }

        if (y == 0)
            data->x = len;
        else if (data->x != len)
        {
            free(line);
            return -1;
        }
        for (int x = 0;x < data->x;x++)
        {
            if (line[x] == data->empty)
                data->map[y][x] = EMPTY;
            else if (line[x] == data->obstacle)
                data->map[y][x] = OBSTACLE;
            else
            {
                free(line);
                return -1;
            }
        }
        y++;

    }

    free(line);
    if (y != data->y)
        return -1;
    return 1;
}

void find_bsq(t_data *data)
{
    int dp[max][max];
    for (int i = 0; i < data->y;i++)
    {
        for (int j = 0; j < data->x; j++)
        {
            if (data->map[i][j] == OBSTACLE)
                dp[i][j] = 0;
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else 
                dp[i][j] = 1 + get_min(dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1]);
            if (data->bsq.size < dp[i][j])
            {
                data->bsq.size = dp[i][j];
                data->bsq.x = j - dp[i][j] + 1 ;
                data->bsq.y = i - dp[i][j] + 1 ;
            }
        }
    }

    for (int i = 0;i <  data->bsq.size;i++)
    {
        for(int j = 0;j < data->bsq.size;j++)
            data->map[data->bsq.y + i][data->bsq.x + j] = FULL;
    }
}


void print_bsq(t_data *data) {
    for (int y = 0; y < data->y; y++) {
        for (int x = 0; x < data->x; x++) {
            if (data->map[y][x] == EMPTY)
                fputc(data->empty, stdout);
            else if (data->map[y][x] == OBSTACLE)
                fputc(data->obstacle, stdout);
            else
                fputc(data->full, stdout);
        }
        fputc('\n', stdout);
    }
}


void process_map(FILE *file)
{
    t_data data= {0};    
    if (read_map(file,&data) == -1)
    {
        fprintf(stderr,"Error: invalid map");
        return ;
    }
    find_bsq(&data);
    print_bsq(&data);
}





int main(int ac, char **av) {
    if (ac == 1) {
        process_map(stdin);
    } else if (ac == 2){
            FILE *file = fopen(av[1], "r");
            if (!file) {
                fprintf(stderr, "Error: can't open the file %s\n",av[1]);
                return 1;
            }
            process_map(file);
            fclose(file);
        }
    return 0;
}
