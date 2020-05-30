#include "friend_class.h"
void readid(Car car)
{
    car.print();
    cout<<car.id<<endl;
}
int main(int argc,char **arg)
{
    Car car(102,"lw");
    car.print();
    readid(car);
    return 0;
}