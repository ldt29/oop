请回答下列选择题（多选题漏选得一半分，多选或不选不得分）。
请注意提交次数限制

答案
BD
BCD
AB
ABD
ACD
CD
AD
C


1.【多选】下列说法正确的是
A. std::string str("abc");和std::vector<char> str("abc");这两种对象构造方式都是可以通过编译的；

B. std::string类型的对象和std::vector<char>类型的对象都可以通过索引进行元素修改，如str[0]='o'；

C. std::string类型的对象可以通过c_str()方法转化为C风格字符串，返回char*类型字符指针，并可以通过指针对字符串进行修改；

D. std::string类型的对象和std::vector<char>类型的对象都可以调用push_back方法；

2.【多选】下列说法正确的是
A. std::cout和std::endl是ostream类型的对象；

B. std::cout不允许复制，若允许复制，则多个对象之间难以同步输出状态；

C. 流操纵算子可以用来设置整数的进制、设置浮点数的精度等，如使用setprecision(2)可以设置输出保留2位精度；

D. std::cout << setw(3) << setfill('*')是一个ostream类型的对象；

3.【多选】下列说法正确的是
A. scanf的格式字符串可以在运行时确定，需要在运行期间解析；

B. 使用stringstream可以连接多个字符串，也可以将读入的字符串转换为其它类型的数据；

C.对于stringstream类的对象ss，可以通过ss.str()获取未读取的内容；

D. stringstream和ifstream，实现了输⼊流和输出流的接⼝；

4.【多选】关于下列代码说法正确的是
~~~C++
#include<iostream>
using namespace std;

void bar(char ch, int i) {
    cout << "bar " << ch << ' ' << i << " ";
    return ;
}

class func {
    public: //(7)
        void operator()(char ch, int i) const { 
            cout << "func " << ch << ' ' << i << " ";
        }
};

template<class Pclass>
void foo(char ch, int i, Pclass p) { // (6)
    p(ch, i);
}

int main() {
    void (*P) (char, int); // (1)
    P = bar(); // (2)
    foo('e', 13, P); // (3) 

    auto F = func(); // (4)
    foo('e', 13, F); // (5)
}
~~~
A. (1) 声明P是函数指针，(4) 声明F是函数对象；

B. (2)把bar()改为bar，该代码即可编译成功，输出结果为"bar e 13 func e 13 "；

C. (5)传参错误，(6)处foo函数Pclass只能是函数指针类型；

D. (7)不能把operator()设置为private成员；

5.【多选】下列关于智能指针的说法正确的是
~~~C++
#include <iostream> 
using namespace std; 
void f1(shared_ptr<int> p1) {
    cout << p1.use_count();
}

shared_ptr<int> f2(shared_ptr<int> &p1){
    f1(p1);
    cout << p1.use_count();
    return p1;
}

void f3(shared_ptr<int> p2){
    cout << p2.use_count();  // (1)
}

int main(){
    shared_ptr<int> p1(new int); //(2)
    f1(p1); //(3)
    cout << p1.use_count(); //(4)
    shared_ptr<int> p2 = f2(p1); //(5)
    cout << p1.use_count();  //(6)
    cout << p2.use_count();  //(7)
    f3(p2); // (8)
    cout << p1.use_count();  //(9)
    cout << p2.use_count();  //(10)
    return 0;
}
~~~
A. 把(8)处f3(p2);改为f3(p1);输出结果不变；

B. 在有标号的代码中，发生拷贝构造的只有(3)(8)；

C. (1)行输出为3；

D. 若把f3的参数类型shared_ptr<int>改为shared_ptr<int>&，只影响(1)行的输出，其他输出不变；

6.【多选】下列说法正确的是
A. 智能指针可以自动管理资源，从而完全避免内存泄露；

B. 弱引用weak_ptr无法获取引用计数；

C. unique_ptr指针无法复制，只能移动；

D. unique_ptr不涉及引用计数，它保证一个对象只被一个指针引用

7.【多选】以下关于迭代器模式的说法正确的是:
A. 迭代器模式实现了算法和数据存储的隔离。

B. 存储器类需要是迭代器类的友元。

C. 实现了基于继承的迭代器模式后，可以在算法中使用基类迭代器对象表示派生类迭代器。

D. 实现了基于模板的迭代器模式后，生成的头尾迭代器对象不必手动销毁。

8.【单选】以下关于模板方法和策略模式的说法不正确的是:
A. 模板方法和策略模式分别对应继承和组合两种设计思路。

B. 模板方法适用于业务场景相对稳定的场景，策略模式适用于业务场景相对多样灵活的场景。

C. 当算法的每一个步骤都有多种解决方案时，模板方法优势较大。

D. 策略模式会对外暴露策略组合，封装性相对较差。
