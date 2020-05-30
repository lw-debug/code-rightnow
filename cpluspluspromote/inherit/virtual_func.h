#ifndef VIRTUAL_FUNC_H
#define VIRTUAL_FUNC_H
#include <iostream>
using namespace std;

class Parent
{
public:
    void virtual print()
    {
        cout << "Parent print()" << endl;
    }

};
class Child : public Parent
{
public:
    void virtual printSS()
    {
        cout << "Child print()" << endl;
    }
    
};
#endif