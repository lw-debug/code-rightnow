#include<iostream>
#include<unistd.h>
#include"car_static.h"
using std::cout;
using std::cin;
using std::endl;
int main(int argc,char **arg)
{
    Car car1,car2;
    // car1.id++;
    car2.print();
    int a=car2.getid();
    cout<<"a:"<<a<<endl;
    cout<<"aaa:"<<Car::getid_static()<<endl;

    // cout<<"sizeof(Car):"<<sizeof(Car)<<endl;
    return 0;
}