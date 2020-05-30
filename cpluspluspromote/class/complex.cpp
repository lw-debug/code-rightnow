#include "complex.h"

void Complex::printComplex()
{
    cout << a << "+" << b << "i" << endl;
}

Complex Complex::operator+(const Complex &another)
{
    Complex temp;
    temp.a = this->a + another.a;
    temp.b = this->b + another.b;
    return temp;
}
Complex &Complex::operator+=(const Complex &another)
{
    // Complex temp;
    this->a += another.a;
    this->b += another.b;
    return *this;
}
Complex &Complex::operator++()
{
    this->a++;
    this->b++;
    return *this;
}
Complex Complex::operator++(int)
{   Complex temp(this->a,this->b);
    this->a++;
    this->b++;
    return temp;
}
