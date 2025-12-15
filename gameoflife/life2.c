#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **v)
{
   if( ac != 4) return 1;
   int w = atoi(v[1]), h = atoi(v[2]), iters = atoi(v[3]);
   if(w<=0 || h<= 0 || iters < 0) return 1;
   int size = (w + 2) * (h + 2);

   int *g[2];
   g[0]= calloc(size, sizeof(int));
   g[1]= calloc(size, sizeof(int));

   int x = 1, y = 1, pen = 0;
   char c;

   while(read(0, &c, 1) > 0)
   {
    if(c == 'w' && y> 1) y --;
    if(c == 's' && y< h) y++;
    if(c == 'a' && x> 1) x--;
    if(c == 'd' && x< w) x++;
    if(c == 'x') pen = !pen;
    if(pen) g[0][y *(w +2)+ x] = 1; 
   }
   for(int  t = 0; t<iters; t++){
        int cur = t % 2, nxt = 1- cur;
        for(int i = 1; i<= h; i++)
            for(int j = 1; j<= w; j++){
                int n = 0;
                for(int y = i -1; y <= i + 1; y++)
                    for(int x = j -1; x <= j + 1; x++)
                        if(x != j || y != i)    n+= g[cur][y*(w +2)+x];
            g[nxt][i*(w+ 2)+j] = (n==3 ||(n==2 && g[cur][i*(w+ 2)+j]));
            }
   }
   int f = iters%2;
   for(int i = 1; i<=h ; i++ , putchar('\n'))
        for(int j = 1; j<=w ; j++)
            putchar(g[f][i*(w+ 2)+j]? 'O': ' ');
}