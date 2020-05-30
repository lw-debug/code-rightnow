#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "car.h"
using std::cin;
using std::cout;
using std::endl;
void test1()
{
    Car *p = new Car("lwww", "yellow");
    p->print();
    // delete p;
    // if (p != NULL)

    // {
    delete p;

    cout << "return test1" << endl;
    cout << "P:" << p << endl;
    p = NULL;
    // }
}
void test2()
{
    Car *q = (Car *)malloc(sizeof(Car));
    // q->set("12","3212",);
    if (q == NULL)
    {
        cout << "error" << endl;
    }
    // cout << "ok" << endl;
    cout << "Q:" << q << endl;

    q->set("sdghha", "adsghsd");
    q->print();
}
int main(int argc, char **arg)
{
    // test1();
    cout << "in main" << endl;
    Car *q = (Car *)malloc(sizeof(Car));
    // q->set("12","3212",);
    if (q == NULL)
    {
        cout << "error" << endl;
    }
    cout << "ok" << endl;
    cout << "Q:" << q << endl;

    q->set("sdghha", "adsghsd");
    q->print();
    q->set("dsas", "sd");
    q->print();
    free(q);
    cout << "Q:" << q << endl;

    q=NULL;
    cout << "Q:" << q << endl;


     Car *qq = (Car *)malloc(sizeof(Car));
    // q->set("12","3212",);
    if (qq == NULL)
    {
        cout << "error" << endl;
    }
    cout << "ok" << endl;
    cout << "Q:" << qq << endl;

    qq->set("sdghha", "adsghsd");
    qq->print();
    qq->set("dsas", "sd");
    qq->print();
    free(qq);
    qq=NULL;

    return 0;
}