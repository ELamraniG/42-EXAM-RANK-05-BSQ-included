#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct s_bsq
{
    int x;
    int y;
    int size;

}t_bsq;

#define max 1000
#define max 1000
enum {
    EMPTY,OBSTACLE,FULL
};

typedef struct s_data
{
    int x;
    int size;
    t_bsq bsq;
    char **map;
}t_data;

void process_map(FILE *file);
int read_map(t_data *data,FILE *file);
void find_bsq(t_data *data);
void print_map(t_data *data);




int main(int ac,char **av)
{
    if (ac == 1)
    {
        process_map(stdin);
    }
    else if (ac == 2)
    {
        FILE *file = fopen(av[1],"r");
        if (file == NULL)
        {
            fprintf(stderr,"Error in the file\n");
            return 1;
        }
        process_map(file);
        fclose(file);
    }
}




void process_map(FILE *file)
{
    t_data data = {0};
    
}
int read_map(t_data *data,FILE *file)
{
    gi
}