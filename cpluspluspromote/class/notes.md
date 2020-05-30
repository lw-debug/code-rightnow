#C++提高笔记

#difference c & c++

##1.c++会对全局变量进行重定义检查，c不会
excmple
: int val;//在全局的bss段，初始化为0

: int val=20;//在全局data段

##2.使用struct定义变量不用带（struct 关键字）
##3.C++参数不匹配会报错,c是warning
##4.C++增加了bool 
只取true or false 即0 或 1
:   bool  true=1 false=0 
    bool flag=20 -20; =>>flag=1即非0数即为true
    sizeof(bool)=1 
##5.c语言三目运算符返回值，不能当左值，c++可以
excmple
:  int a=10,b=20,c; c=a>b?a:b;
: (a>b?a:b)=30; c语言不行，c++可以 表示b=30
##6.const
1. C的const 假的 可通过指针间接修改，C++ 的常量会在全局区而不是栈区，会在符号表生成键值表，只读。即a用10替换
2. c定义不赋值则为0,C++ 必须初始化
3. int const a=10;int arr[10];//c error，C++ ok 
int const a=10;int *p=(int *)&a;//此时p指向系统在栈区开辟的空间值为10,可改
##7 enum c里可赋值0或者名字，c++只能用枚举里的名字
#C++

##1.namespace
code
: using namespace XXX; namespace XXX{}
for(int i=0;;) i的作用域只在{}里
##2 引用只有c++有，实质是变量的别名,引用申明一定要初始化，一旦确定不能变
1. **引用实质是常指针（指向不变的指针即指针常量注意与常量指针不同**
2. **引用类型必须一致 如const int a=10;必须const &re=a;但const引用能引用一般类型，此时引用不能改变引用值**   

3. excmple
    : int a;int &re=a;ok
    const int b=10;
    int &ree=b;error
    const int &ree=b;ok 
    const int &reee=a;ok 
    but reee=a+1;error
    **即此引用不能修改值，所以常作为函数参数**
 4. const int &a=40;a是40所对应内存空间的别名
    func(int &p) func(a);即int &p=a;{}此时能改a
    get_Mem2(Teacher  * &p)指针引用，参数是teacher *, p是指针的别名
#3 inline 写在实现之前，由编译器直接插入，增加代码量减少调用开销 gcc inline 编不过加static |extern inline，C++可以
#4计时用time.h里的clock函数
#5重载只有C++有，函数名相同，或者参数个数，类型顺序不同即可重载，但注意要编译器能匹配且只能匹配一个
code
: 1. int func() 与char func()不行 char func(int a)可以
: 2. int func(int a,int b) 与int func(int a,int b,int c=10||int=0) 如调用时只传2个参数，编译报错
: 3. **函数指针不能重载，参数个数必须完全匹配**

#class
1. **构造函数可重载 没有返回类型，一旦有显示构造函数，直接将覆盖默认无参**
2. **析构函数没有参数没有返回值
默认拷贝构造是值拷贝，深拷贝 有显示拷贝构造函数时 ，默认消失,浅拷贝一般有指针**
3. Car car2(car1);等价于 Car  car2=car1;但与Car car2;car2=car1不同

4. **初始化列表主要是为了初始化类里面的其他对象**
5. **友元函数和友元类的声明**
friend class friend_class;  
friend void readid(Car car);

#运算符重载
1. **类外重载operator+(Car &car1,Car &car2),此时需声明友元或用Car.get方法**
    1. Car operator+() 在类内部默认传入this指针
Car  operator++();重载++i,++i没有参数
Car  operator++(int); i++，有int参数表示i++ 默认为0即i++0
同operator++(Car &this) operator++(Car &this,int i)
由于++i中i与表达式值相同，故可返回&，i++返回拷贝
2. **++++++i可以，但是i++只能一次
3. **重载car1+=car2+=car3;返回引用
4. 重载<<需要在全局中而不是类中，不然变成complex1<<cout
5. 以下不可重载 .   .*(即成员有char *name *(class.name))  :: :?四个
6. 操作符重载，参数必须要有自定义的数据类型
7. 重载=是为了深浅拷贝,即成员变量有指针
8. 重载[] int &operator[](int index) const
    {
        return this->array[index];
    }
9. 重载（）与[]相似
complex1+complex2 => complex1.operator+(co2) 返回Complex
int a=0;if((a=0)&&(a=10)) =>a=0 即从左到右判断，遇0即停,注意加括号有优先级
int a=0;if((a=0) ||(a=10)) print a=>0 即从左到右判断，遇1即停 a=0
**重载&&之后不会有这个特性,会算完再判断**
10. 重载new delete []
    **void * operator new(size_t size)**
    {   cout<<"重载了new   "<<size<<endl;
        return malloc(size);}
    **void * operator new[](size_t size)**
    {   cout<<"重载了new   "<<size<<endl;
        return malloc(size); }
    **void  operator delete(void *p)**
    {   cout<<"重载了delete "<<endl;
        free(p);
        p=NULL;}
    **void  operator delete [](void *p)**
    {   cout<<"重载delete[] "<<endl;
        free(p);
        p=NULL;}


#类静态成员变量,类静态成员函数
1. 静态成员变量
static int id;类内部定义
int Car::id=10;类外部初始化 在静态区开辟（一次初始化，不在对象访问）car1.id 或者Car：：id

2. 类静态成员函数 定义实现与普通函数一致
静态函数只能访问静态变量及调用静态函数
普通成员函数皆可用

#new delete

int a(10) === int a=10;
new int[] 则delete []p;
**int *p=new int[10]{10,5,6};可以这样初始化,单个元素可以用（）**
**赋值和打印尽量不要用*(p++),会改变p的指向位置，越界**
Car *p=new Car(0,"lw");
Car *q=(Car *)malloc(sizeof(Car));
**malloc不会调用构造和析构，new会**
**如果class里有c++的类型如string，new delete之后再malloc set 会段错误**
**new malloc总结，new 或malloc之后delete(free)再new 指针指向原区域，先new delete 再malloc也会指向原地址，但是malloc的指针不能修改非c的值(如string)，不混用**

** !!!**  int *p=new int[0];此时p!=NULL,且p[i]有值，即此时指针越界不报错

#class 里定义的函数实质是函数指针，默认有一个this指针当参数传递给func,
**sizeof(class) 是所有成员变量的大小，函数不占,加一个或多个virtual 均加4(x32) 8（x64）本机为8，注意也有对齐**
**传递的this指针是指针常量，即指向不变**
** void printCar() const;此const修饰this指针**

excmple
:    Car(const Car & another)
   {
       another.print();//此处调Car::print参数不匹配
       }
    void print(void) **const**;//不写const报错
**智能指针在<memory>头文件中 std::auto_ptr
auto_ptr<int> ptr(new int);
会自动析构
#继承
基类（父类） ，子类（派生类 ）
1. class Student2:public Student1{};
    S1里的数据S2也有，用this访问，S2调S1函数 Student::printS()
    this

|变量类型  |内部|外部|
|-------  |---|----|
|protected|能 |不能 |
|private  |能 |不能 |
|public   |能 |能   |


|公有继承  |子类内部|子类外部|
|-------  |---   |----   |
|protected|能    |不能    |
|private  |能    | 不能   |
|public   |能    |能      |

public,protected变量公继访问权限与父类相同
protected继承public 变protected ,即子类能，外部不能

private变量不论何种继承子类均不可用
所有变量私继后均为private,只能访问基类中的protected 和public

**子类可以给父类初始化 多赋少，多的去掉，只能多不能少**
**父类指针可以直接指向子类，引用也可，小用大**
**子类构造时一定会调用父类的构造函数，不管你写没写，默认调用父类无参
** this->a 和Parent::a 访问同名变量或函数**
** 静态局部变量父类和子类共享**
**继承默认是private, class Z:X,Y  =>X,Y均私继**
**class Z:public X,Y  =>X公继，Y私继**
**多继承有共同变量x时zz.x报错，只能 zz.X::x，zz.Y::x**
**此时在继承X或Y前面加virtual无用，只能在抽象一个基类，X,Y都虚继承与基类，Z再继承XY,这样Z中只有一份拷贝**
**多继承初始化，按声明的先后初始初始化**
**虚函数为了实现多态,参数为Parent *,编译器默认调用parent的方法
**多态条件：要有继承，有虚函数重写(参数，即名字一样)，父类指针指子类
**父类指针指向子类，相当于只能访问父类大小的区域，所以优先调用父类方法，但虚函数表优先级更高，子类重写虚函数，则表中保存子类虚函数,使用父类的则需加Parent::,虚函数表应该也保存父类**
**构造函数不能为虚函数。**
**基类的析构函数应该为虚函数。**
**友元函数不能为虚，因为友元函数不是类成员，只有类成员才能是虚函数。**
**如果派生类没有重定义函数，则会使用基类版本。**
**重新定义继承的方法若和基类的方法不同（协变除外），会将基类方法隐藏；**
**如果基类声明方法被重载，则派生类也需要对重载的方法重新定义，否则调用的还是基类的方法**
excmple
:  void printClass(Parent *p)
{
    p->print();//此时不论传父子类指针，均调用父函数，基类加virtual即可实现多态，习惯子类也加vir 增加可读性
}  
**继承的函数不能重载，如parent 都有print（）|print(int),此时不会重载
**重写析构函数名字会不一样**

**虚函数多态的实质：如果一个类有virtual关键字的函数，编译器在给对象开辟空间时，会默认加一个vptr的指针，并且会有一个虚函数表，父指针指向子类时，调用方法时首先从虚函数表中查找，找不到再从父类虚函数表找,再找不到，最后是本身**
**继承的同名函数不能重载，会被子类覆,子类中定义的同名函数可以，主要是作用域不同**
excmple
:   Parent::print();
:   child::print(int);
    ch.print(int) ok
    ch.print() error
**vptr在父类初始化时指向父类虚函数表，父类初始化完之后指向子类虚函数表**
**parent_point++ 与child_point++不同，所以不要轻易++**
**纯虚函数在最后加=0;void virtual print() =0;不加编译报错（即不是纯虚函数），含有纯虚函数的类是抽象类，不能实例化，子类必须重写改方法**

**抽象类的作用，与父类指针一起使用，将main函数与类实现隔离virtual ~Animal() 抽象类要加虚析构，不然delete只析构父类**
Shape *p = new Circle(1);
Shape *p = new Rectangle(1, 2);
Shape *p = new Triangle(3, 4, 5);
    p->printArea();



