#include"car_static.h"
int Car::id=10;
void Car::set(string setname,string setcolor)
{
// Car::name=name;//
// Car::color=color;

    name=setname;//如果形参与类变量相同则会出错
    color=setcolor;
// or

// this->name=name;
// this->color=color;
}
void Car::print()
{
    cout<<"name:"<<name<<endl;
    cout<<"color:"<<color<<endl;
    cout<<"id"<<id<<endl;
}
