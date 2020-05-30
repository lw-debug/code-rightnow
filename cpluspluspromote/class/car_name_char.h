#ifndef _CAR_H
#define _CAR_H
#include <iostream>
#include <string.h>
using namespace std;
class Car
{
private:
    char  name[64];
    char color[64];
    int id=0;

public:
    Car()
    {
        strcpy(name,"lw");
        strcpy(color,"yellow");
        // color = "yellow";
        cout << "Car 构造" << endl;
    }
    Car(char* namep, char * colorp)
    {
        strcpy(name,namep);
        strcpy(color,colorp);

        cout << "Car 构造" << endl;
    }
    Car(const Car &another)
    {
        strcpy(this->name,another.name);
        strcpy(this->color,another.color);
        // color = another.color;
        cout << "Car 构造" << endl;
    }
    void set(char *, char*,int);
    void print(void);
    ~Car()
    {
        cout<<"Car 析构"<<name<<endl;
// 
    }
};

#endif