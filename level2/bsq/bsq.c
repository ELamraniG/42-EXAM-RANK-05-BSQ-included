#include <string.h>
#include <stdlib.h>
#include <stdio.h>
enum 
{
    EMPTY,OBSTACLE,FULL
};
#define max 1000
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
    char empty,obstacle,full;
    int map[max][max];
} t_data;

int read_map(FILE *file,t_data *data)
{
    if (fscanf(file,"%d %c %c %c\n",&data->y,&data->empty,&data->obstacle,&data->full) != 4 || data->y < 1)
        return -1;
    if (data->empty == data->obstacle || data->empty == data->full || data->obstacle == data->full)
        return -1;
    size_t len = 0;
    int read_len = 0;
    char *line = NULL;
    int y = 0;
    while (getline(&line,&len,file) != -1 && y < data->y)
    {
        read_len = strlen(line);
        if (line[read_len - 1] == '\n')
            line[--read_len] = 0;
        if (read_len < 0 || read_len > max)
            return -1;
        if (y == 0)
            data->x = read_len;
        else if (data->x != read_len)
        {
            free(line);
            return -1;
        }
        for (int x = 0; x < read_len;x++)
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
    return 0;
}

int min3(int a,int b,int c)
{
    int small = a;
    if (b < a)
        small = b;
    if (c < small)
        small = c;
    return small;
}
void print_bsq(t_data *data)
{
	for (int y = 0; y < data->y;y++)
	{
		for (int x = 0;x < data->x;x++)
		{
			if (data->map[y][x] == EMPTY)	
				fputc(data->empty,stdout);
			if (data->map[y][x] == OBSTACLE)	
				fputc(data->obstacle,stdout);
			if (data->map[y][x] == FULL)	
				fputc(data->full,stdout);
		}
			fputc('\n',stdout);
	}
}
void find_bsq(t_data *data)
{
    int dp[max][max];
    for (int y = 0;y < data->y;y++)
    {
        for (int x = 0; x < data->x;x++)
        {
            if (y == 0 && x == 0)
                dp[y][x] = 0;
            else if (data->map[y][x] == OBSTACLE)
                dp[y][x] = 1;
            else
                dp[y][x] = 1 + min3(dp[y -1][x],dp[y][x-1],dp[y-1][x-1]);
            if (data->bsq.size < dp[y][x])
            {
                data->bsq.size = dp[y][x];
                data->bsq.y = y - dp[y][x] + 1;
                data->bsq.x = x - dp[y][x] + 1;
            }
        }
    }
    for (int y = 0;y < data->bsq.size;y++)
        for (int x = 0; x < data->bsq.size;x++)
            data->map[y + data->bsq.y][x + data->bsq.x]  = FULL;
}






void process_map(FILE *file)
{
    t_data data = {0};
    if (read_map(file,&data) == -1)
        return;
    find_bsq(&data);
    print_bsq(&data);

}
int main(int ac,char **av)
{
    if (ac == 1)
        process_map(stdin);
    if (ac == 2)
    {
        FILE *filee = fopen(av[1],"r");
        if (!filee)
            return 1;
        process_map(filee);
        fclose(filee);
    }
    return 0;
}