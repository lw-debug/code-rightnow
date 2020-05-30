#ifndef _CAR_STATIC_H
#define _CAR_STATIC_H
#include <iostream>
#include <string.h>
using namespace std;
class Car
{
private:
    
    string name;
    string color;
    static int id;
public:
    static int getid_static()
    {
        // cout<<"color:"<<color<<endl;
        return id;
    }
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
    int getid()
    {return getid_static();}
    
};

#endif