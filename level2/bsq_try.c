#include <stdlib.h>
#include <unistd.h>
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

int read_map(FILE *file,t_data *data)
{
    if (fscanf(file,"%d %c %c %c",data->y,data->empty,data->obstacle,data->full) != 4 || data->y < 1)
        return -1;
    if (data->empty == data->obstacle || data->empty == data->full || data->obstacle == data->full)
        return -1;
    
    char *line = NULL;
    size_t read_size;
    int y = 0;
    while (y < data->y && getline(file,&read_size,&line) != -1)
    {
        if (line[read_size - 1] == '\n')
            line[--read_size] = 0;
        if (read_size == 0 || read_size > max)
        {
            free(line);
            return -1;
        }
        if (y == 0)
            data->x = read_size;
        else
        {
            if (data->x != read_size)
            {
                free(line);
                return -1;

            }
        }
        for (int x = 0;x < read_size;x++)
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

void process_map(FILE file)
{
    t_data data= {0};    
    if (read_map(&file,&data) == -1)
    {
        fprintf(stderr,"Error: invalid map");
        return ;
    }
    find_bsq(&data);
    print_bsq(&data);
}


int main(int ac,char **av)
{
    if (ac == 1)
        proccess_map(stdin);
    else 
    {

    }
}