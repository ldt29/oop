**请回答下列选择题（多选题漏选得一半分，多选或不选不得分）。**
**请注意提交次数限制**
1. **【多选】下列关于编译和链接正确的有：**  

A. g++ main.cpp -o main 进行了编译和链接两步；  
B. main.cpp代码如下所示。使用命令g++ main.cpp -o main 可以完成编译，但是会有链接错误；    
```cpp
#include <iostream>

int increase(int a);
int add(int a, int b) {return a + b;}

int main() {
    std::cout << increase(1) << std::endl;
    std::cout << add(1, 1) << std::endl;
    return 0;
}
```   
C. main.cpp代码如下所示。使用命令g++ -c main.cpp -o main 可以完成编译；
```cpp
#include <iostream>

float increase(int a);
int increase(int a) { return a + 1; }

int main() {
    std::cout << increase(1) << std::endl;
    return 0;
}
```
D. 头文件中如果正确使用header guards或者#pragma once，即使包含函数或变量的定义，也不会出现重复定义的问题

2. **【单选】有下列宏定义，请问int z = 2 * A * FUNC(A, A);的值为（如果非整数则保留小数点后两位）**
```cpp
#define PI 3.1415926
#define A PI + 3
#define FUNC(n,m) n*m + m
```
A. 34

B. 538.75

C. 469

D. 34.27

3. **【多选】下面关于 makefile 说法正确的有：**  

A. makefile 文件中，每条指令前都必须是`<tab>`或者1个空格；

B. 如果main.cpp 中 include 了 func.h，且 makefile 文件中编译 main.cpp 的命令如下所示，则当func.h更新时间戳晚于main.o时（main.cpp保持不变），重新执行 make 命令，`main.o` 也不会更新
```makefile
main.o: main.cpp
    g++ -c main.cpp -o main.o
```
C. 运行 `make` 命令没有指定任务时，默认会执行所有任务；

D. 假设当前目录下有 main.cpp 和 func.cpp 两个文件，则下面两组代码功能上等价：
```makefile
main: main.o func.o
    g++ main.o func.o -o main
main.o: main.cpp
    g++ -c main.cpp -o main.o
func.o: func.cpp
    g++ -c func.cpp -o func.o
```
```makefile
main: main.o func.o
    g++ $^ -o $@
%.o: %.cpp
    g++ -c $< -o $@
```
4. **【多选】下面说法正确的有：**


A. 函数前有 inline 修饰的函数一定会在编译时被展开；

B. 传入参数的类型可以被用来区分重载函数；

C. 即便是没有被 inline 修饰的函数，编译器也可能将其作为内联函数并展开；

D. 变量定义时被分配内存。

5. **【单选】`make -f Makefile test`这条命令中，传递给 make 的命令行参数 argv[2] 为**


A. Makefile

B. -f

C. test

D. Make

6. **【多选】下面说法正确的是**


A. c++ 中，NULL 可以用来表示空指针，同时也是整数 0。

B. 代码auto a = 10; std::cout << sizeof(auto) << std::endl; 的输出为 4

C. int x = 0为定义 x变量并初始化为0。

D. auto x = new int[5];中 x 的类型为 int 而 auto* x = new int[5];中 x 的类型为 int*

7. **【多选】以下哪些属于下面代码无法正确编译的原因：**
```cpp
class A {
    int a;
public:
  void set(int a) {this->a = a;}
  bool get(int b) {return b > a;}
  bool get(int b, int c=1) {return (b + c) > a;}
};

int main() {
  auto a_test = new A();
  a_test->set(10);
  std::cout << a_test->get(2) << std::endl;
  return 0;
}
```
A. `a_test->set(10);`对私有变量进行了赋值；

B. `a_test->get(2)`函数调用有二义性；

C. 程序结束时没有释放 `a_test` 占用的内存；

D. cout 没有引用相应的头文件。

8. **【多选】下面代码可以正常编译的是**

A.
```cpp
class A{
    int func(int a = 3, int b) { return a + b;}
};
```
B.
```cpp
class A {
    int func(int a, int b) {return a + b;}
};
```
C.
```cpp
class A {
  float func(float a, float b) {return a + b;}
  int func(float a, float b) {return int(a) + int(b);}
};
```
D.
```cpp
class A {
  int func(float a, float b) {return int(a) + int(b);}
  int func(int a, int b) {return a + b;}
};
```

```txt
AB
A
BD
BCD
A
AC
BD
BD
```
