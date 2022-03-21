## 题目描述
在刚进入大学的学习中，微积分这门数学课让很多人头疼，但其中与整式相关的运算已经被研究得很透彻，很容易在计算机上实现。为简化问题，需要大家在给定代码的基础上实现单项式类Monomial，并重载流运算符、四则运算符、以及实现定积分、求导、代入求值操作。

Monomial.h
```
#include <iostream>
#include <string>

class Monomial
{
private:
    int coe;
    int deg;
public:
    Monomial();
    Monomial(int _c, int _d);
    Monomial operator+(const Monomial &x) const;
    Monomial operator-(const Monomial &x) const;
    Monomial operator*(const Monomial &x) const;
    Monomial operator/(const Monomial &x) const;
    int definite_integral(const int a, const int b) const;
    Monomial derive() const;
    int get_val(int x) const;
    //TODO
};
```
文件下载地址：见problem_86.zip

### 输入格式
第一行包含一个正整数n，表示一共有n个给定的单项式。

对每个单项式，第一行给出一个字符串描述该单项式，形如sx^q的形式。第二行包含一个正整数m，表示对该单项式一共有m个操作。接下来m行，每行包含一个正整数opr，和若干个参数，opr表示操作类型，如下：

* opr为1时，将当前单项式加上另一单项式，参数为另一单项式tx^p，保证当前单项式的次数为p；

* opr为2时，将当前单项式减去另一单项式，参数为另一单项式tx^p，保证当前单项式的次数为p；

* opr为3时，将当前单项式乘上另一单项式，参数为另一单项式tx^p；

* opr为4时，将当前单项式除以另一单项式，参数为另一单项式tx^p，保证t不为0且能整除当前多项式的系数；

* opr为5时，求定积分 ∫abf(x)dx ，参数为两个整数a,b，保证当前单项式的次数不为-1，次数+1能整除系数，运算结果为整数；

* opr为6时，对当前单项式求导，输出一行包含运算后的结果。

接下来一行包含一个整数par，将par带入当前单项式求值，保证当次数为负时，结果为整数。

### 输出格式
对每个操作输出一行，包含运算后的结果:

* opr为1, 2, 3, 4, 6时输出一个字符串cx^d。

* opr为5时输出一个整数。

对每个单项式代入求值时输出一行，包含一个整数，为运算后的结果。

### 数据规模和约定
1≤n≤100 , 1≤m≤40 , 1≤opr≤6 ，−15≤a,b,par≤15
所有输入的单项式，和运算后的单项式系数绝对值小于100，次数绝对值不大于5

注意当系数为0时，次数也应为0

时间限制：1s

空间限制：256MB

### 输入样例
```
1
10x^3
6
1 -2x^3
2 -3x^3
3 1x^-1
4 1x^-2
6
5 1 11
9
```
### 输出样例
```
8x^3
11x^3
11x^2
11x^4
44x^3
161040
32076
```
### 提交格式
* 根据提供的main.cpp、Monomial.h及Makefile的内容，编写Monomial.cpp并完善Monomial.h。应该将Monomial.cpp和Monomial.h打包成一个zip压缩包并上传。评测时，OJ会将提供的 main.cpp贴入目录下进行编译并执行。
* 编译命令 g++ main.cpp Monomial.cpp -o main -std=c++11
