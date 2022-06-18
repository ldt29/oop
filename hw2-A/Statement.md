1. 【单选】关于运算符重载，下列说法正确的是：


A. 对于下列代码中的两个运算符重载实现：即便它们的参数均为 int 与 Test 的组合，这段代码仍可以通过编译。这是因为在两个重载实现中， int 与 Test 在参数中的顺序不同，编译器能够唯一地确定调用哪个运算符实现代码。
```cpp
#include <iostream>
using namespace std;

class Test{
public:
    int data;
    Test(int d):data(d){}
};

Test operator +(const Test& a, const int& b){
    return Test(a.data + b);
}

Test operator +(const int& b, const Test& a){
    return Test(- a.data - b);
}

int main(){
  Test obj(1);
  int data = 2;
  cout << (obj + data).data << endl;
  cout << (data + obj).data << endl;
  return 0;
}
```
B. A 的说法是错误的。这是因为加法满足交换律，因此即便调换 A 和 int 的顺序，加法运算的实现仍必须保持一致，编译器在编译时也会检查这一点。如将后一处 int 改为 double，则可通过编译。

C. A 和 B 的说法都是错误的。运算符重载时，所有参数以及返回值的类型必须完全相同。因此，即便是下列代码中的运算符重载实现，也不能通过编译。
```cpp
class Test{
public:
    int data;
    Test(int d):data(d){}
};

Test operator +(const Test& a, const int& b){
    return Test(a.data + b);
}
```
D. A、B、C 的说法都是错误的。

2. 【多选】关于运算符重载，下列说法错误的是：


A. 对于 !、~ 等单目运算符，可以通过运算符重载操作，将他们重载为双目运算符，如下面代码所示：
```cpp
class Test{
int data;
friend Test operator !(const Test& a, const Test& b);
public:
  Test(int d): data(d){}
};

Test operator !(const Test& a, const Test& b){
  return Test(!(a.data + b.data));
}
```
B. 运算的优先级无法通过运算符重载改变。

C. 在重载 ++、-- 运算符时，是否定义哑元参数可以用于区分后缀与前缀的同名重载。具体地，定义哑元参数则表示后缀运算重载；否则表示前缀运算重载。例如，对于下列代码，运行输出结果应为 `prefix.suffix.`。
```cpp
#include <iostream>

class Test{
public:
    Test& operator++ (){
        std::cout<<"prefix.";
        return *this;
    }
    Test& operator++ (int){
        std::cout<<"suffix.";
        return *this;
    }
};

int main(){
    Test t;
    ++t;
    t++;
}
```
D. 全局重载运算必须借助友元函数实现，如 `friend istream& operator>> (istream& in, Test& dst);`。

3. 【多选】关于构造函数和析构函数，阅读以下代码，并选出正确的说法：

```cpp
#include <iostream>

class Test{
public:
    int data = -1;
    Test() = default; // (A)
    Test(int dat){ // (B)
        this->data = dat; // (C)
    }
    ~Test(){ // (D)
        std::cout<<data;
    }
};

int main(){
    Test* t = new Test();
    delete t;
    return 0;
}
```
A. 如果将注释 (A) 所在的行删除，则该代码无法通过编译，原因是 main 函数中调用了未定义的缺省构造函数。

B. 将注释 (A) 所在的行删除，将注释 (B) 所在的行改为 Test(int dat = 2022){ // (B)，则该代码可以通过编译，运行输出结果为 2022。

C. 将注释 (A) 和 (C) 所在的行删除，将注释 (B) 所在的行改为 Test(int dat = 2022):data(dat){ // (B)，则该代码可以通过编译，运行输出结果为 2022。

D. （不考虑 A、B、C 选项的改动，）如果将注释 (D) 所在的行改为 ~Test(int data = 0){ // (D)，该代码可以通过编译，运行输出结果为 0。

4. 【单选】关于构造函数和析构函数，阅读以下可以通过编译的代码，并选出其运行输出结果：

```cpp
#include <iostream>

class Member{
public:
    Member(){std::cout<<"Constructing member.";}
    ~Member(){std::cout<<"Destructing member.";}
};

class Group{
public:
    Member member;
    Group(){std::cout<<"Constructing group.";}
    ~Group(){std::cout<<"Destructing group.";}
};

int main(){
    Group group;
    return 0;
}
```
A. Constructing member.Constructing group.Destructing member.Destructing group.

B. Constructing member.Constructing group.Destructing group.Destructing member.

C. Constructing group.Constructing member.Destructing member.Destructing group.

D. Constructing group.Constructing member.Destructing group.Destructing member.

5. 【单选】关于析构函数和友元，阅读下列代码，并选出正确的选项：

```cpp
#include <iostream>

class Student{
    friend class School;
private: // (B)
    ~Student(){std::cout<<"Student fired.";}
public:
    class School* school;
    void interfereSchool();
};

class School{
private:
    void access(){std::cout<<"School accessed.";}
public:
    Student* student;
    void fireStudent();
};

void Student::interfereSchool(){
    school -> access(); // (A)
}
void School::fireStudent(){
    delete student;
}

int main(){
  School* school = new School();
  Student* student = new Student();
  school -> student = student;
  student -> school = school;

  student -> interfereSchool();
  school -> fireStudent();
}
```
A. 该代码不能通过编译。原因：Student 类的 interfereSchool 成员函数访问了 School 类的私有成员 access。解决方案：删除该调用（即：删除代码中注释 (A) 所在的行），方可通过编译。

B. 该代码不能通过编译，原因：Student 类的析构函数被定义为私有成员。解决方案：将其更改为公有成员（即：将代码中注释 (B) 所在的行改为 public:），方可通过编译。

C. 该代码不能通过编译，且 A、B 所述原因都正确，因此必须同时应用 A、B 的解决方案，该代码才能通过编译。

D. 该代码可以通过编译，且输出结果为 School accessed.Student fired.。

6. 【单选】关于常量成员和常量对象，阅读以下可以通过编译的代码，并选出描述正确的选项：

```cpp
class Student{
private:
  const int id;
  double gpa;
public:
  Student(int _id): id(_id), gpa(0.0) {} // (A)
    int getId() const {
      return id;
  }
    void updateGpa(double _gpa) {
        gpa = _gpa;
    }
    double getGpa() {
        return gpa;
    }
};

int main(){
  Student alice(1);
  alice.getId();
  alice.updateGpa(4.0);
  alice.getGpa();

  const Student bob(2);
  bob.getId();

    return 0;
}
```
A. 使用 Student(int _id) {id = _id; gpa = 0.0;} 替换原代码中的 Student 类构造函数（即注释 (A) 所在的行）不会影响编译，因为它们的效果是完全一致的。

B. 在 main 函数中 bob 对象定义后，可以调用 bob.getGpa()，因为没有对 bob 的任何成员变量作修改。

C. Student 类的 getId 成员函数不能改为非常量成员函数，否则 main 函数中常量对象 bob 将无法调用 bob.getId()。

D. Student 类的 getGpa 成员函数不能改为常量成员函数，因为该函数的实现中访问了非常量成员 gpa。

7. 【单选】关于静态成员，阅读以下可以通过编译的代码，并选出其运行输出结果：

```cpp
#include <iostream>

class Counter{
private:
    int cnt;
public:
  Counter(): cnt(0) {
      std::cout<<"Initializing Counter."<<std::endl;
  }
  void count() {
      ++cnt;
  }
  int getCount() {
      return cnt;
  }
};

class Test{
public:
    static Counter counter;
  Test() {
      std::cout<<"Initializing Test."<<std::endl;
      counter.count();
  }
};
Counter Test::counter = Counter();

int main() {
  std::cout<<"main"<<std::endl;
  Test();
  std::cout<<Test::counter.getCount()<<std::endl;
  Test();
  std::cout<<Test::counter.getCount()<<std::endl;
  return 0;
}
```
A.
```
Initializing Counter.
main
Initializing Test.
1
Initializing Test.
2
```
B.
```
main
Initializing Counter.
Initializing Test.
1
Initializing Test.
2
```
C.
```
main
Initializing Test.
Initializing Counter.
1
Initializing Test.
2
```
D.
```
main
Initializing Counter.
Initializing Test.
1
Initializing Counter.
Initializing Test.
1
```
8. 【多选】下列说法中，错误的是：


A. 使用 new[] 构造的对象应当使用 delete 释放内存，如下面代码所示。
```cpp
class Test{};

int main() {
  Test* a = new Test[10];
  delete a;
  return 0;
}
```
B. 下列代码可以通过编译，但由于在函数 func 中返回了局部对象的引用，因此可能在编译时引发警告（Warning），或引起运行时错误。
```cpp
class Test{};

Test& func(){
  Test t;
  return t;
}

int main() {
  Test& t = func();
  return 0;
}
```
C. int 类型的常量静态数据成员可以在类内初始化，如下代码所示。
```cpp
class Test{
public:
    static const int x = 0;
};

int main(){
    return 0;
}
```
D. 使用 delete 释放指针 p 指向的内存单元后，p 将指向 nullptr。即下列代码能够正常运行：
```cpp
#include <cassert>

class Test{};

int main(){
  Test* p = new Test();
  delete p;
  assert(p == nullptr);
  return 0;
}
```
```
A
AD
ABC
B
A
C
A
AD
```
