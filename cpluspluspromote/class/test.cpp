#include<iostream>
#include<unistd.h>
#include"car.h"
using std::cout;
using std::cin;
using std::endl;
int main(int argc,char **arg)
{
    // Car car1;
    // car1.print();
    // car1.set("klas","dasdk");
    // car1.print();
    Car car2("dasdass","dsa");
    // car2.print();
    Car car3(car2);
    // car3.print();
    car3.set("lww","adds");
    Car car4;
    car4=car3;
    car4.print();

    return 0;
}