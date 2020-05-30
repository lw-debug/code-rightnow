#ifndef _MUL_INHERIT_H
#define _MUL_INHERIT_H
#include <iostream>
using namespace std;
class Furniture
{
    public:
    int material;
    Furniture(){
        cout<<"in Furniture"<<endl;
        material=1;}
};

class Bed:virtual public Furniture
{
public:
    Bed(){
        cout<<"in Bed"<<endl;
        material=2;}
    void sleep()
    {
        cout << "Bed sleep" << endl;
    }
};
class Sofa:virtual public Furniture
{
    public:
    Sofa(){
        cout<<"in sofa"<<endl;
        material=3;}
    void sit()
    {
        cout<<"Sofa sit"<<endl;
    }
};

class BedandSofa:public Sofa,public Bed
{
    public:
    BedandSofa(){
        cout<<"in bedsofa"<<endl;

    }
    void print()
    {
        // sleep();
        this->sleep();
        this->sit();
    }
};


#endif