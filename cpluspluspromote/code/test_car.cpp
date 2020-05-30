#include "myarray.h"
ostream &operator<<(ostream &os, Myarray const &array)
{
    for (int i = 0; i < array.getLen(); i++)
    {
        os << array(i) << "  ";
    }
    os << endl;
    return os;
}
int main(int argc, char **arg)
{
    // Myarray array1;
    // int ar[]={1,2,3,4,5,6};
    // // array1.printArray();
    // // Myarray array2(array1);
    // // array2.printArray();
    // Myarray array3(ar,6);
    // array1.printArray();
    // array3=array1;
    // array3.printArray();
    // array1[7]=0;
    Myarray arr(10);
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i * i;
    }
    cout << arr;
    Myarray *p=new Myarray(1);
    delete p;
    Myarray *q=new Myarray[10]{1,2,3,4,5,6,7,7,9,10};
    delete []q ;

    return 0;
}