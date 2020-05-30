#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char **arg)
{
    // after c++11
    // ///1.
    for (int i : {1, 3, 5, 7, 8})
    {
        cout << i << "\t";
    }
    cout << endl;
    // 2.
    for (auto it : {1, 3, 4, 5, 7, 8, 9, 9})
    {
        cout << it << "\t";
    }
    // vector Iterator
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec(a, a + 5);
    for (vector<int>::iterator it=vec.begin();it<vec.end();it++)
    {
        cout <<*it<< endl;
    }

    // 4... auto 
    for(auto auto_it:vec)
    {
        cout <<auto_it<< endl;//要修改值就用 auto &

    }

    return 0;
}