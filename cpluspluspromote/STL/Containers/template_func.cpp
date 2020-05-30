#include <iostream>
using namespace std;
template <typename T>
T myadd(T a,T b)
{return a+b;}

template <typename T>
T substract(T a, T b)
{

    return a + b;
}


int main(int argc, char **arg)
{
    cout << myadd(1, 2) << endl;
    return 0;
}