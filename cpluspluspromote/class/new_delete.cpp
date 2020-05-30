#include <iostream>
#include <unistd.h>
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char **arg)
{
    int *p = new int[10];
    for (int i = 0; i < 10; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < 10; i++)
        cout << p[i] << "\t";
    // delete p;
    free(p);

    return 0;
}