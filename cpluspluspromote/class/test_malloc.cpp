#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
typedef struct strr
{
    // char*
    string name;
    string color;

} strr;

int main(int argc, char **arg)
{
    // int *p = new int[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     p[i] = i;
    // }
    // cout<<"p:"<<p<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << p[i] << "  ";
    // }
    strr *p = (strr *)malloc(sizeof(strr));
    // strr *p = new strr;
    cout << "p:" << p << endl;
    p->color = "yellow";
    p->name = "lw";
    cout << "p->name:" << p->name << endl;
    cout << "p->color:" << p->color << endl;
    free(p);
    p=NULL;

    strr *qq = (strr *)malloc(sizeof(strr));
    // strr *qq = new strr;
    cout << "qq:" << qq << endl;
    qq->color = "yeow";
    qq->name = "lwwww";
    cout << "qq->name:" << qq->name << endl;
    cout << "qq->color:" << qq->color << endl;
    free(qq);
    qq=NULL;

    
   strr *q = (strr *)malloc(sizeof(strr));
    // strr *q = new strr;
    cout << "q:" << q << endl;

    q->color = "yeo";
    q->name = "lww";
    cout << "q->name:" << q->name << endl;
    cout << "q->color:" << q->color << endl;
    free(q);

    return 0;
}