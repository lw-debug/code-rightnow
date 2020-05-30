#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using namespace std;
class Complex
{
    // friend Complex operator+(Complex &c1, Complex &c2);
public:
    Complex(int a=0,int b=0):a(a),b(b){}
    void printComplex();
    Complex operator+(const Complex&);
    Complex &operator+=(const Complex&);
    Complex &operator++();
    Complex operator++(int);
    int get_complex_a(){return this->a;}
    int get_complex_b(){return this->b;}
private:
    int a;//实部
    int b;//虚部

};
#endif