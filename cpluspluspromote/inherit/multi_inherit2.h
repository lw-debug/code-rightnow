#ifndef _MUL_INHERIT2_H
#define _MUL_INHERIT2_H
#include <iostream>
using namespace std;
class Parent
{
    public:
    Parent(){cout<<"parent";}
    int x;
};
class X:virtual public Parent
{
    public:
    X(){x=1;}
    int y;
};
class Y:virtual  public Parent
{
    public:
    Y(){x=2;}
    int z;
};
class Z:public X,public Y
{
    int z;
};


#endif