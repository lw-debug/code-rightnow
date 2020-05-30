#include <iostream>
using namespace std;
class A
{
    public:
    // int x;
   virtual void print1(){}
   virtual void print2(){}
   virtual void print3(){}
   virtual void print4(){}
//    virtual void print5(){}
   virtual void print6(){}
};

class B:public A
{
   virtual void print1(){}
    virtual void print20(){}
    void print3(){}
};
int main(int argc,char **arg)
{
    cout<<"sizeof(A):"<<sizeof(A)<<endl;
    cout<<"sizeof(B):"<<sizeof(B)<<endl;
    return 0;
}
