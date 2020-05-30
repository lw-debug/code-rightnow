#include"car_name_char.h"
void Car::set(char * setname,char* setcolor,int id=0)
{
// Car::name=name;//
// Car::color=color;
    cout<<"in set"<<endl;
    strcpy(this->name,setname);//如果形参与类变量相同则会出错
    strcpy(this->color,setcolor);//如果形参与类变量相同则会出错
    // this->color=setcolor;
    this->id=id;
    cout<<"set ok"<<endl;

// or

// this->name=name;
// this->color=color;
}
void Car::print()
{
    cout<<"in print"<<endl;
    cout<<"name:"<<this->id<<endl;
    cout<<"color:"<<this->color<<endl;
}
