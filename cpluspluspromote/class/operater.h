#ifndef OPERATOR_H
#define OPERATOR_H

#include<iostream>
#include<string.h>

using namespace std;
// class friend_class;
// class Car;
// void readid(Car);
class Car
{
private:
    int id;
    string name;
public:
    Car(){}
    Car(int id,string name):id(id),name(name){}
    void set(int id,string name);
    void print();
    Car  operator+(const Car & car);
    Car  operator++();
    Car  operator++(int);

};
#endif
