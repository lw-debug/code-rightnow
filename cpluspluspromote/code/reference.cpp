#include<iostream>
#include<unistd.h>
using std::cout;
using std::cin;
using std::endl;
int main(int argc,char **arg)
{
    int a=10;
    int &re=a;
    re=100;
    cout<<"re:"<<re<<endl;
    return 0;
}