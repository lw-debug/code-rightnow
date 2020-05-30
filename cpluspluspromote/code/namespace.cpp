#include<iostream>
#include<unistd.h>
using std::cout;
using std::cin;
using std::endl;

namespace lw{

    int a=10;
}
using namespace std;
int main(int argc,char **arg)
{
    cout<<"lwwa"<<lw::a<<endl;
    return 0;
}