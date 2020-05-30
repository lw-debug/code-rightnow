#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
enum season
{
    spring=0,
    sum=1,
    autom=2

};
int main()
{
    
    enum season s=1;
    printf("%d\n",s);
    if(s==sum)
    printf("%d\n",s);


    return 0;
}