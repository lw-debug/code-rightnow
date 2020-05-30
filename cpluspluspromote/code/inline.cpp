#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
void   printAB(int a, int b)
{
    printf("a:%d", a);
    printf("b:%d\n", b);
}

int main()
{
    clock_t start, end;
    start=clock();
    int a=1,b=10000;
    for(int i=0;i<100000;i++,a++,b--)
    {
        printAB(a,b);
    }
    end=clock();
    printf("%f",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}