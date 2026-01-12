#include <stdio.h>

int main()
{
    int x = 5,y=10;
    int n = x+=y;
    printf("x = %d y= %d n= %d",x,y,n);
    return 0;
}