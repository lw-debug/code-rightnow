#include"operater.h"
int main(int argc,char **arg)
{
    #if 0
    Car car1(0,"lww");
    Car car2(211,"csds");
    Car car3;
    car3=car1+car2;
    car3.print();
    #endif
    Car car1(0,"lw");
    car1.print();
    Car car2=++car1;
    car2.print();
    car1.print();
    return 0;
}