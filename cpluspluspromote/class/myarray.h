#ifndef MY_ARRAY_H
#define MY_ARRAY_H
#include <iostream>
using namespace std;
int error_1 = -1;
int error_2 = -2;

class Myarray
{
private:
    int *array;
    int len;

public:
    Myarray(int alen);
    Myarray(int *, int);
    Myarray(const Myarray &another); //拷贝构造函数
    Myarray &operator=(const Myarray &another);
    void printArray();
    int getLen() const {return this->len;}

    void * operator new(size_t size)
    {
        cout<<"重载了new   "<<size<<endl;

        return malloc(size);

    }
     void * operator new[](size_t size)
    {
        cout<<"重载了new   "<<size<<endl;
        return malloc(size);

    }

    void  operator delete(void *p)
    {
        cout<<"重载了delete "<<endl;

        free(p);

    }
    void  operator delete [](void *p)
    {
        cout<<"重载delete[] "<<endl;
        free(p);

    }
    int &operator[](int index) const
    {
        return this->array[index];
    }
    int & operator()(int index=0) const
    {
        return this->array[index];
    }
    ~Myarray();
};
Myarray::Myarray(int alen = 0)
{
    // cout << "create err,len<=0" << alen;
    if (alen < 1)
    {
        cout << "create NULL array len=0" << endl;
        this->len = 0;
    }
    else
    {
        this->len = alen;
        this->array = new int[this->len]{0};
    }
}
Myarray::Myarray(const Myarray &another)
{
    this->len = another.len;
    if (this->len)
    {
        this->array = new int[this->len];
        for (int i = 0; i < this->len; i++)
        {
            this->array[i] = another.array[i];
        }
    }
}
Myarray::Myarray(int *another, int len)
{
    this->len = len;
    this->array = new int[this->len];
    for (int i = 0; i < this->len; i++)
    {
        this->array[i] = another[i];
    }
}
void Myarray::printArray()
{
    if (this->len <= 0)
    {
        cout << "array no element" << endl;
        return;
    }
    for (int i = 0; i < this->len; i++)
    {
        cout << array[i] << "  ";
        ;
    }
    cout << endl;
}
Myarray &Myarray::operator=(const Myarray &another)
{
    if (this->len < another.len && another.len > 0) //本身大，则全拷贝，小则扩容拷贝
    {
        if (this->len > 0)
        {
            delete[] this->array;
        }
        this->len = another.len;
        this->array = new int[this->len]{0};
    }

    for (int i = 0; i < another.len; i++)
    {
        this->array[i] = another.array[i];
    }
}
Myarray::~Myarray()
{
    if (this->len > 0)
        delete[] this->array;
    this->len = 0;
    cout<<"~M"<<endl;
}

#endif