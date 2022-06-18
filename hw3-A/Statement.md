1.【单选】下面说法正确的有:

A) 若已定义类Obj，则对于Obj a; Obj b=a;，第二个语句首先调用Obj的默认构造函数（已定义）初始化b，再调用Obj的赋值运算符（已定义）实现a到b的拷贝。

B) 如果一个类没有显式定义拷贝构造函数但重载了赋值运算符，且编译器自动合成了拷贝构造函数，则合成的拷贝构造函数会调用拷贝赋值运算符完成拷贝。

C) 若有int x;，则int *y = &x;和int *z = &(x-7);都是合法的语句。

D) const int &x = -1;是合法的语句。

2.【单选】以下代码的输出是:
```cpp
01    #include<iostream>
02    using namespace std;
03   

04    class T{
05    public:
06        T(){}
07        T(T& t){cout<<"A";}
08        T(T&& t){cout<<"B";}
09        T& operator =(T&& t){cout<<"C"; return *this;}
10    };
11    
12    void swap(T& a, T& b) { 
13        T tmp(std::move(a));
14        a = std::move(b);
15        b = std::move(tmp);
16    }
17    
18    int main(){
19        T a;
20        T b;
21        swap(a,b);
22        return 0;
23    }
```
A) ABCC

B) BCC

C) CCC

D) BBCBC

3.【多选】关于以下代码说法正确的有:
```cpp
01     #include <iostream>
02     using namespace std;
03   
04     class Complex
05     {  
06     public:  
07         int real;  
08         int imag; 
09         Complex():real(0),imag(0){}
10         Complex(int r, int i):real(r),imag(i){cout<<"B";}
11         Complex(int r): real(r),imag(0){cout<<"A";}
12         operator int(){
13             return real;
14         }
15         Complex operator+(const Complex& c){
16             return Complex(this->real+c.real,this->imag+c.imag);
17         } 
18     };  
19    
20     int main()
21     {
22         Complex c(3,4);
23         c=c+3.4;
24         cout<<c.real+c.imag;
25         return 0;
26     }
```
A) 该代码在第23行产生歧义会导致编译错误。可以将12-14行的代码注释或15-17行的代码注释，两种情况均可编译通过。

B) 如果注释15-17行，并且在12行前加explicit关键字，则第23行不可以通过编译。

C) 如果注释12-14行，输出结果是BA10。

D) 如果注释15-17行，输出结果是BA10。

4.【单选】下面说法错误的有：
A) 考虑代码int x; int &y=x;，则y是x的别名。

B) 编译器自动合成的拷贝构造函数对指针类型数据成员采用位拷贝。

C) int a=5; int &&x=a;是合法的语句。

D) int &&x=3;x=5;是合法的语句。

5.【单选】关于以下代码说法正确的有:
```cpp
01    #include <iostream>
02    using namespace std;
03    class A {
04    public:
05        int a=1;
06    protected:
07        int b=2;
08    private:
09        int c=3;
10    };
11    
12    class B {
13    public:
14        int d=4;
15    protected:
16        int b=5;
17    private:
18        int e=6;
19    };
20    
21    class C: public A, private B{
22    public:
23        void print() {
24            cout << [1] << endl;
25        }
26    };
27    
28    int main() {
29        C obj_c;
30        obj_c.print();
31        cout << [2] << endl;
32        return 0;
33    }
```
A) 在[1]处，填a或c均可编译通过（可认为[2]填写正确，不影响编译）。

B) 在[2]处，填obj_c.a或obj_c.d均可编译通过（可认为[1]填写正确，不影响编译）。

C) 在[1]处，可以通过A::b和B::b分别访问A类和B类中的成员变量b。

D) 在[2]处，可以通过obj_c.A::b来访问A类中的成员变量b。

6.【单选】关于下面这段代码运行结果说法正确的有 (编译选项含有-std=c++11):
```cpp
01   #include <iostream>
02   using namespace std;
03   class A {
04       int data;
05   public:
06       static int count;
07       A():data(2019){count += 1; cout << count << endl;} 
08       A& operator = (const A & a){
09           if (this != &a) data = a.data;
10           return *this;
11       }
12       A(int i):data(i){count += 2; cout << count << endl;}
13       ~A(){cout << "destructor "<< data << endl;}
14   };
15    
16   class B {
17       int data{2020};
18       A a1,a2;
19   public:
20       B(){}
21       B(int i):a2(i){a1 = a2;}
22       ~B(){cout<<"destructor "<< data <<endl;}
23   };
24    
25   int A::count = 0;
26    
27   int main() {
28       B obj1;
29       B obj2(2021);
30       return 0;
31   }
```
A) 将第8-11行去掉对程序运行结果会有影响。

B) 输出的前4行是1\n2\n4\n5\n。

C) 将第20行去掉对程序编译不会有影响。

D) 输出中前缀是destructor的行，后面的数字按顺序是2020,2021,2021,2020,2019,2019。

7.【单选】关于下面代码说法正确的有:
```cpp
01   #include <iostream>
02   using namespace std;
03   
04   class Animal{
05   public:
06       Animal(){};
07       Animal(int d){};
08       void move(double d) { cout << "Animal move" << d << "km\n"; }
09       void eat(double d) { cout << "Animal eat " << d << "g food\n"; }
10    };
11    
12    class Bird: public Animal{
13    public:
14        using Animal::move;
15        void move() { cout << "Bird move"; }
16        void move(int i) { cout << "Bird move" << i << "m\n"; }
17    };
18    
19    class Crow : public Bird{
20    public:
21        using Bird::move;
22        void move(int i) { cout << "Crow move" << i << "m\n"; }
23    };
24    
25    int main() {
26        Crow crow;
27        crow.move(10);
28        crow.move(4.9);
29        crow.eat(4.8);
30        crow.move();
31        return 0;
32    }
```
A) 如果将6行注释掉, 程序可以通过编译。

B) 如果将第14行注释掉, 程序仍能通过编译,且输出没有变化。

C) 如果将第21行注释掉, 程序仍能通过编译,但是输出有变化。

D) 如果将第12行改为class Bird: protected Animal{, 只需要去掉第29行就可以成功编译运行。

8.【多选】以下说法正确的有:
A) 派生类的成员函数可以访问通过私有继承的基类的保护成员。

B) 继承时，友元函数不可以被派生类继承。

C) 类C直接public继承类B和类A，而类B和类A中都包含public变量x，则代码`C c;cout<<c.x;`会因为二义性而编译错误。

D) 派生类的构造函数的成员初始化列表中，可以包含基类数据成员的初始化。
```
D
B
AB
C
C
D
D
ABC
```
