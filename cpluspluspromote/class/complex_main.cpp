#include "complex.h"
#if 0
Complex operator+(Complex &c1, Complex &c2)
{
    Complex  temp(c1.a+c2.a,c1.b+c2.b);//调用get或声明友元
    // temp.a=c1.a+c2.a;
    return temp;
}
#endif
ostream & operator<<(ostream &cout, Complex &com)
{
    cout<<com.get_complex_a()<<"+"<<com.get_complex_b()<<"i"<<endl;
    return cout;
}
int main(int argc, char **arg)
{
    Complex c1(1, 2);
    Complex c2(2, 2);
    c1.printComplex();
    c2.printComplex();
    Complex c3 = c1 + c2;
    c1 += c2 += c2;
    c1.printComplex();
    c3.printComplex();
    ++++++++c3;
    // int i=0;
    c3.printComplex();
    cout<<c3<<"adhsdhaj"<<endl;

    return 0;
}