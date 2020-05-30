#include"multi_inherit2.h"
int main(int argc,char **arg)
{
    Z zz;
    cout<<zz.X::x<<endl;
    cout<<zz.x<<endl;
    cout<<zz.Y::x<<endl;

    return 0;
}