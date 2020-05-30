#include <iostream>
using namespace std;
class Animal //抽象类
{
public:
    virtual void voice() = 0; //纯虚函数
    virtual ~Animal(){cout<<"animal ~"<<endl;}
};
class Dog : public Animal
{
public:
    virtual void voice()
    {
        cout << "Dog wangwangwang!"<< endl;
    }
};
class Cat : public Animal
{
    virtual void voice()
    {
        cout << "Cat wangwangwang!"<< endl;
    }
};
class Tiger : public Animal
{
public:
    virtual void voice()
    {
        cout << "Tiger wangwangwang!"<< endl;
    }
};
int main(int argc, char **arg)
{
    Animal *p=NULL;
    p=new Dog();
    p->voice();
    delete p;

    p=new Cat();
    p->voice();
    delete p;

    p=new Tiger();
    p->voice();
    delete p;

    return 0;
}