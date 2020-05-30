#include"virtual_func.h"
int main(int argc,char **arg)
{
    Parent pa;
    Child ch;
    Parent *pa_point=&ch;
    Child *ch_point;
    // pa.print(1);
    pa_point->print();
    // ch.print();
    // ch.Parent::print();

   
    return 0;
}