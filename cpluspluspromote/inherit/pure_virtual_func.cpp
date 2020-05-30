#include <iostream>
#include <cmath>
#define PI 3.1415926
using namespace std;
class Shape
{
public:
    virtual double getArea() = 0;
    virtual double printArea() = 0;
};
class Circle : public Shape
{
public:
    Circle(int radius)
    {
        this->radius = radius;
    }
    virtual double getArea()
    {
        return PI * radius * radius;
    }
    virtual double printArea()
    {
        cout << "Circle Area :" << getArea()<<endl;
    }

private:
    int radius;
};
class Rectangle : public Shape
{
public:
    Rectangle(int length, int width)
    {
        this->length = length;
        this->width = width;
    }
    virtual double getArea()
    {
        return length * width;
    }
    virtual double printArea()
    {
        cout << "Rectangle Area :" << getArea()<<endl;
    }

private:
    int length;
    int width;
};
class Triangle : public Shape
{
public:
    Triangle(int edges1, int edges2, int edges3)
    {
        this->edges1 = edges1;
        this->edges2 = edges2;
        this->edges3 = edges3;
    }
    virtual double getArea()
    {
        double p = (edges1 + edges2 + edges3) / 2;
        return sqrt(p * (p - edges1) * (p - edges2) * (p - edges3));
    }
    virtual double printArea()
    {
        cout << "Triangle Area :" << getArea()<<endl;
    }

private:
    int edges1;
    int edges2;
    int edges3;
};
int main(int argc, char **arg)
{
    Shape *p = NULL;
    p = new Circle(1);
    p->printArea();
    delete p;
    p = NULL;

    p = new Rectangle(1, 2);
    p->printArea();
    delete p;
    p = NULL;

    p = new Triangle(3, 4, 5);
    p->printArea();
    delete p;
    p = NULL;

    return 0;
}
