#ifndef MY_STRING_H
#define MY_STRING_H
#include<iostream>
// #include<stdlib.h>
// #include<stdio.h>
#include<string.h>
using namespace std;
class Mystring
{
friend ostream & operator<<(ostream &os,Mystring &str);
friend istream & operator>>(istream &is,Mystring &str);

private:
    int len;
    char *str;

public:
//构造
    Mystring();
    Mystring(const char *);
    Mystring(const Mystring &);
//运算符重载
    Mystring  operator+(const Mystring & another);
    char& operator[](int index);
    Mystring & operator=(const Mystring & another);

};
#endif