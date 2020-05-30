#include<iostream>
#include<unistd.h>
using std::cout;
using std::cin;
using std::endl;
int volume(int x,int y,int z)
{
    cout<<"x:"<<x<<endl;
    cout<<"y:"<<y<<endl;
    cout<<"z:"<<z<<endl;
    return x*y*z;
}
double volume(int x,int y)
{

    cout<<"double:"<<endl;
}
int main(int argc,char **arg)
{
    int a=1,b=2,c=3;
    int v=0;
    v=volume(b,c);
    cout<<"v:"<<v<<endl;
    return 0;
}