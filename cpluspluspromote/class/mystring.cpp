#include "mystring.h"
Mystring::Mystring()
{
    this->len = 0;
    cout << "无参构造" << endl;
    this->str = new char[this->len + 1];
    strcpy(this->str, "");
}
Mystring::Mystring(const char *str2)
{
    if (str2 == NULL)
    {
        const char *tmp = "";
        str2 = tmp;
    }
    this->len = strlen(str2);
    this->str = new char[this->len + 1];
    strcpy(this->str, str2);
    cout << "char*构造" << endl;
}
Mystring::Mystring(const Mystring &another)
{
    this->len = another.len;
    this->str = new char[this->len + 1];
    strcpy(this->str, another.str);
    cout << "拷贝构造" << endl;
}

Mystring Mystring::operator+(const Mystring &another)
{
    Mystring tmp;
    tmp.len = this->len + another.len;
    tmp.str = new char[tmp.len + 1];
    strcpy(tmp.str, this->str); //也可用strcat ，但要先memset;
    strcat(tmp.str, another.str);
    return tmp;
}
char &Mystring::operator[](int index)
{
    return this->str[index];
}

Mystring &Mystring::operator=(const Mystring &another)
{
    if (this == &another)
    {
        return *this;
    }
    this->len = another.len;
    if (this->str != NULL)
        delete[] this->str;
    this->str = new char[this->len + 1];
    strcpy(this->str, another.str);
    return *this;
}
