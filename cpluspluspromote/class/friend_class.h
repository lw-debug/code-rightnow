#ifndef FRIEND_H
#define FRIEND_H
#include<iostream>
#include<string.h>
using namespace std;
class friend_class;
class Car;
void readid(Car);
class Car
{
    friend class friend_class;  
    friend void readid(Car car);

private:
    int id;
    string name;
public:
    Car(int id,string name):id(id),name(name){}
    void set(int id,string name);
    void print();

};
#endif