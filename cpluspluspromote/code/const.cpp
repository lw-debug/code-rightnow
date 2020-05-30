#include<iostream>
#include<unistd.h>
using std::cout;
using std::cin;
using std::endl;
int main(int argc,char **arg)
{
    const int a=10;
    cout<<a<<endl;
    int *p=(int *)&a;
    int  arr[10];
    *p=1200;
    cout<<*p<<endl;
    return 0;
}