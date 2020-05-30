#include "operater.h"
void Car::set(int id, string name)
{

    this->id = id;
    this->name = name;
}
void Car::print()
{

    cout << "Car id is " << this->id << endl;
    cout << "Car name is " << this->name << endl;
}
Car Car::operator+(const Car &car)
{
    Car temp;
    temp.id=this->id+car.id;
    temp.name=this->name+car.name;
    return temp;
}

Car Car::operator++()
{
    ++this->id;
    return *this;
}

Car  Car::operator++(int i)
{
    Car tem=*this;
    this->id++;
    return tem;
}