#include "friend_class.h"
void Car::set(int id, string name)
{

    this->id = id;
    this->name = name;
}
void Car::print()
{

    cout<<"Car id is "<<this->id<<endl;
    cout<<"Car name is "<<this->name<<endl;
}