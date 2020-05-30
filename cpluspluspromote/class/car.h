#ifndef _CAR_H
#define _CAR_H
#include<iostream>
#include<string.h>
using namespace std;
class Car
{
private:
    string name;
    string color;

public:
    Car()
    {
        name = "lw";
        color = "yellow";
    }
    Car(string name ,string color):name(name),color(color){}
    Car(const Car & another)
    {
        name=another.name;
        color=another.color;

    }
    void set(string,string);
    void print(void);
    
};

#endif