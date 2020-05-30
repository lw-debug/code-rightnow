#include <iostream>
using namespace std;
template <typename T, typename M>
class Pointer
{
public:
    Pointer(T *p)
    {
        this->pointer = p;
    }

public:
    T *pointer;
};

int main(int argc, char **arg)
{
    cout << "class Template" << endl;
    int a = 10;
    Pointer<int, int> poi(&a);
    cout << *poi.pointer << endl;

    return 0;
}