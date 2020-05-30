// #pragma once
#include <iostream>
using namespace std;

class Parent
{
public:
    int a;
    Parent(int a)
    {
        cout << "Parent init" << endl;
        this->a = a;
        print();
    }
    void virtual print()
    {
        cout << "Parent print() a:" << a << endl;
    }
};
class Child : public Parent
{
public:
    int b;
    Child(int a, int b) : Parent(a)
    {
        
        cout << "Child init" << endl;
        this->b = b;
        print();
    }
    void virtual print()
    {
        cout << "Child print() b:"<<b << endl;
    }
};

int main()
{
Parent *p=new Child(1,2);
p->print();
delete p;
return 0;

}