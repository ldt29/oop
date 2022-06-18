答案
C
A
BD
D
B
AB
D
D

1.【单选】关于以下代码，说法正确的是
~~~C++
#include <iostream>
using namespace std;

class Instrument{
public:
    int price;
    void tune() { cout << "Instrument::tune()" << endl; }
    virtual void play() { cout << "Instrument::play()" << endl; }
};

class Violin : public Instrument{
public:
    void tune() { cout << "Violin::tune()" << endl; } // (1)
};

void tune(Instrument* p){
    p->tune();
}

int main(){
    Violin obj;
    tune(&obj); // (2)
    return 0;
}
~~~
A. (1) 处是重写隐藏，在 (1) 处加上override关键字变成 void tune() override {} 后可以实现重写覆盖

B. Instrument类的tune函数继承给了Violin类，(1) 处又一次定义了tune函数，这是函数重载

C. (2) 处函数调用将输出 Instrument::tune()

D. 一个Instrument对象包含一个int成员，因此占用4个字节

2.【单选】下列说法正确的是
A. 虚析构函数可以实现让基类指针指向派生类对象，并用基类的指针析构派生类的对象

B. 在基类中所有的纯虚函数都不必定义函数体

C. 如下代码中所示，Derive1中所有虚函数均使用final关键字修饰了，因此Derive2类中没有虚函数表指针
~~~C++
#include <iostream>
using namespace std;

class Base{
public:
    virtual void func1() {}
    virtual void func2() {}
};
class Derived1: public Base{
public:
    void func1() final {cout << "Derive1::func1" << endl;}
    void func2() final {cout << "Derive1::func2" << endl;}
};
class Derived2: public Derived1{};
D. 下列代码的输出为 Derived\nDerived\n

#include <iostream>
using namespace std;

class Base{
public:
    Base() { func1(); }
    virtual void func1() {cout << "Base" << endl; }
};
class Derived : public Base{
public:
    Derived() { func1(); }
    void func1() {cout << "Derived" << endl; }
};
int main(){
    Base* p = new Derived();
    return 0;
}
~~~
3.【多选】对下面代码，无法编译通过的有
~~~C++
#include <iostream>
using namespace std;

class Base{
public:
    void func1() {cout << "Base::func1()" << endl;}
    virtual void func2() {cout << "Base::func2()" << endl;}
    virtual void func2(int) {cout << "Base::func2(int)" << endl;}
    void func2(float) {cout << "Base::func2(float)" << endl;} // (1)
};
class Derived1: public Base{
public:
    void func1() final {cout << "Derived1::func1()" << endl;} // (2)
    void func2(float) {cout << "Derived1::func2(float)" << endl;}
};
class Derived2: public Base{
public:
    void func2(int) final override {cout << "Derived2::func2(int)" << endl;} // (3)
};

int main(){
    Derived1 obj;
    obj.func2(); // (4)
    return 0;
}
~~~
A. (1)

B. (2)

C. (3)

D. (4)

4.【单选】下列说法正确的有
A. 抽象类中一定有某个成员函数没有函数体

B. 抽象类的派生类就不是抽象类了

C. 只有当一个抽象类的派生类中将该抽象基类的所有纯虚函数都重写覆盖，该派生类才不再是抽象类

D. 抽象类不允许被实例化为对象

5.【单选】关于类型转换，说法正确的有
A. 若Derived是Base的派生类，p为Base类的指针，指向了Derived的对象，则dynamic_cast<Derived*>(p)就可以正确返回Derived的指针

B. 若Derived是Base的派生类，p为Base类的指针，则static_cast<Derived*>(p)就可以返回Derived的指针

C. static_cast与dynamic_cast只能用于基类转换成派生类

D. dynamic_cast只能用于向下类型转换

6.【多选】关于多态，下面说法正确的是
A. 函数重载与模板体现了C++的静态多态

B. 多态可以帮助提高代码的复用率

C. 指针、引用对虚函数的调用总是晚绑定，即运行时绑定

D. 函数模板在编译期间被处理，类模板在运行期间被处理

7.【单选】关于下面代码，说法正确的是
~~~C++
#include <iostream>
using namespace std;

template<typename T0>
T0 func(T0 a, T0 b){
    T0 c = a + b;
    return c;
}

template<typename T1>
T1 func2(T1 a, T1 b){
    T1 c = a - b;
    return c;
}

int main(){
    int a = func(1.2, 1.3); // (1)
    int b = func2(func(1, 2), func(2, 3)); //(2)
    int c = func(1, 1.2); // (3)
    int d = func<int>(1, 1.2); // (4)
    return 0;
}
~~~
A. (1) 处将出现编译错误，因func函数在(1)处的返回值类型为浮点数

B. (2) 处将出现编译错误，因func函数的返回值为T0类型，而func2要求T1类型的参数

C. (3) 处的返回值为2，第二个参数1.2被强制类型转换成了 int 类型

D. (4) 处的返回值为2，第二个参数1.2被强制类型转换成了 int 类型

8.【单选】下列说法正确的是
A. 多重继承中只能继承一个非抽象类

B. 使用类的对象调用虚函数时，可以实现运行时绑定

C. 抽象类不允许有数据成员

D. 基类的析构函数被声明为虚函数后，派生类的析构函数默认也为虚函数
