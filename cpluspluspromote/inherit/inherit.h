#ifndef _INHERIT_H
#define _INHERIT_H
#include <iostream>
#include <string.h>
using namespace std;
class Student
{
public:
int pub;
protected:
 int pro;
private:
    int pri;
};

class Student2 : public Student
{
private:
    int score;
public:
    void printS()
    {
        pub=10;
        pro=10;
        cout<<""<<pub<<" "<<pro<<"protect";
        // pri=10

    }
};

class Student3 : public Student2
{
private:
    int score;
public:
    void printS()
    {
        pub=10;
        pro=10;
        cout<<""<<pub<<" "<<pro<<"protect";
        // pri=10

    }
};

#endif