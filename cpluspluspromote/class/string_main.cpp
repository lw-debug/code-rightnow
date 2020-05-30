#include"mystring.h"
ostream & operator<<(ostream &os,Mystring &str)
{
os<<str.str;
return os;
}
istream & operator>>(istream &is,Mystring &str)
{
    if (str.str != NULL)
        delete[] str.str;
    char tmp[4096]={0};
    is>>tmp;
    str.len=strlen(tmp);
    str.str=new char[str.len+1];
    strcpy(str.str,tmp);
    return is;
}

int main(int argc,char **arg)
{
    Mystring str1("123");
    cout<<str1<<endl;
    cin>>str1;
    cout<<str1<<endl;
    // Mystring str1("123");
    // Mystring str2=str1;
    // Mystring str3=str1+"dssaj"+"d"+"adf";
    // cout<<str1<<endl;
    // cout<<str2<<endl;
    // cout<<str3<<endl;
    // Mystring str4="2123";
    // cout<<str4<<endl;
    // str4=str1+str2;
    // cout<<str4<<endl;
    // str1[1]='x';

    // cout<<str1<<endl;
    // cout<<str4<<endl;

    return 0;
}