请回答下列选择题（多选题漏选得一半分，多选或不选不得分）。
请注意提交次数限制
在考虑[X]选项时，请注释choice[Y]()函数的定义和调用，其中X=A/B/C/D/E，Y ≠≠ X。




1.【单选】请阅读或执行以下代码，下列说法正确的是
~~~C++
#include <iostream>
#include <string>

namespace Campus {
    int building_number;
};

namespace ComputerScience {
    using Campus::building_number;

    std::string dean;
    struct Student {
        std::string id;
        int age;
    };
    int student_number;
    void setDean(std::string name) {
        dean = name;
    }
    void setStudentNumber(int number) {
        student_number = number;
    }
    void setStudent(Student &s, std::string id, int age) {
        s.id = id;
        s.age = age;
    }
};

namespace THU {
    using namespace ComputerScience;
    std::string principle;

    int student_number; 
    void setStudentNumber(int number) {
        student_number = number;
    } 
    void setPrinciple(std::string name) {
        principle = name;
    }
};

void choiceA() {
    using namespace THU;
    setStudentNumber(10000); // (1)
}

void choiceB() {
    using namespace THU;
    ComputerScience::setStudentNumber(1000); // (2)
}

void choiceC() {
    using namespace THU;
    ComputerScience::setStudentNumber(1000);
    THU::setStudentNumber(10000);
    std::cout << student_number; // (3)
}

void choiceD() {
    using THU::setDean;
    setDean("Xia Yin"); // (4)
}

void choiceE() {
    using namespace ComputerScience;
    setStudentNumber(10000);
}

int main() {
    choiceA();
    choiceB();
    choiceC();
    choiceD();
    choiceE();
}
A. choiceA()可正常编译运行，(1)处调用的setStudentNumber函数是命名空间THU中的THU::setStudentNumber

B. choiceB()中(2)处不能调用ComputerScience::setStudentNumber，因为命名空间THU将命名空间ComputerScience隐藏了，只声明命名空间THU无法使用命名空间ComputerScience中的函数

C. choiceC()可正常编译运行，(3)处的输出结果是10000

D. choiceD()中(4)处无法对命名空间ComputerScience中的dean变量进行修改，因为ComputerScience::dean在choiceD中被隐藏

E. choiceE()可正常编译运行
~~~

2.【多选】请阅读或执行以下代码，下列说法正确的是
~~~C++
#include <iostream>
#include <tuple>

void choiceA() {
    std::tuple<int, std::string> a;
}

void choiceB() {
    std::tuple<int, int> a;
    auto b = std::make_tuple(2022, 2023);
    a = b;
}

void choiceC() {
    std::tuple<int, int> a;
    auto b = std::make_tuple(2022, 2023);
    a = b;
    std::cout << std::get<0>(a) << " " << std::get<1>(a) << std::get<2>(a) << std::endl;
}

void choiceD() {
    std::tuple<int, int> a = std::make_tuple(1299, 1923);
    int number1;
    int number2;
    a = std::tie(number1, number2) = std::make_tuple(395, 1453);
}

void choiceE() {
    std::tuple<int, int, int> long_tuple = std::make_tuple(0, 0, 0);
    std::tuple<int, int> short_tuple = long_tuple;
}

int main() {
    choiceA();
    choiceB();
    choiceC();
    choiceD();
    choiceE();
    return 0;
}
A. choiceA()会出现编译错误或运行异常

B. choiceB()会出现编译错误或运行异常

C. choiceC()会出现编译错误或运行异常

D. choiceD()会出现编译错误或运行异常

E. choiceE()会出现编译错误或运行异常
~~~

3.【单选】请阅读或执行以下代码，下列说法正确的是
~~~C++
#include <iostream>
#include <vector>

class Data {
private: 
    int _num;
public:
    Data(int num) : _num(num) {
        std::cout << "构造函数" << std::endl;
    }
    Data(const Data& d) : _num(d._num) {
        std::cout << "拷贝构造函数" << std::endl;
    }
    Data(Data&& d) : _num(d._num) {
        std::cout << "移动构造函数" << std::endl;
    }
    Data& operator=(const Data& d) {
        this->_num = d._num;
        std::cout << "拷贝赋值" << std::endl;
        return *this;
    }
    ~Data() {
        std::cout << "析构函数" << std::endl;
    }
};

void choiceA() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto end = vec.end();
    auto begin = vec.begin();
    std::cout << *begin << " " << *end << std::endl; // (1)
}

void choiceB() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto begin_add_2 = vec.begin() + 2;
    auto result = vec.erase(begin_add_2);
    std::cout << *result << std::endl; // (2)
}

void choiceC() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto end = vec.end();
    auto begin_add_2 = vec.begin() + 2;
    auto result = vec.erase(begin_add_2); // (3)
    std::cout << *end << std::endl;
}

std::ostream& operator << (std::ostream& output, std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        output << v[i] << " ";
    }
    output << std::endl;
    return output;
}

void choiceD() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << vec; // (4)
}

void choiceE() {
    std::vector<Data> vec;
    for (int i = 0; i < 4; ++i) {
        vec.push_back(Data(i));
    }
    auto begin = vec.begin();
    std::cout << "==分割线==" << std::endl;
    vec.insert(begin, Data(100)); // (5)
    std::cout << "==分割线==" << std::endl;
}

int main() {
    choiceA();
    choiceB();
    choiceC();
    choiceD();
    choiceE();
    return 0;
}
A. choiceA()可正常编译运行，(1)处输出1 5

B. choiceB()可正常编译运行，(2)处输出3

C. choiceC()是不安全的，因为(3)处对vec进行了修改，而end迭代器处于修改位置之后

D. 对于choiceD()，如果删去函数operator <<，(4)处的<<将调用vector的默认重载流运算符方法

E. choiceE()可正常编译运行，(5)处的输出依次为一行构造函数，四行拷贝构造函数，五行析构函数
~~~

4.【多选】请阅读或执行以下代码，下列说法正确的是
~~~C++
#include <iostream>
#include <list>
#include <algorithm>

void choiceA(std::list<int> lst) {
    auto begin = lst.begin();
    for (int i = 0; i < 2; ++i) {
        begin ++;
    }
    *begin = 100;
}

void choiceB(std::list<int> lst) {
    lst[2] = 100;
}

void choiceC(std::list<int> lst) {
    auto result = std::find(lst.begin(), --lst.end(), 100);
    std::cout << *result << std::endl; // (1)
}

void choiceD(std::list<int> lst) {
    auto begin = lst.begin();
    auto end = --lst.end();
    lst.insert(begin, 101);
    std::cout << *end << std::endl; // (2)
}

void choiceE(std::list<int> lst) {
    auto result = std::find(lst.begin(), lst.end(), 4);
    lst.erase(result);
    --result;
    std::cout << *result << std::endl; // (3)
}

int main() {
    std::list<int> lst;
    for (int i = 0; i < 5; ++i) {
        lst.push_back(i * 2);
    }
    choiceA(lst);
    choiceB(lst);
    choiceC(lst);
    choiceD(lst);
    choiceE(lst);
    return 0;
}
A. choiceA()中可以修改传入lst中的第2个位置上的元素（约定lst.begin()是指向第0个位置的迭代器）

B. choiceB()中可以修改传入lst中的第2个位置上的元素（约定lst.begin()是指向第0个位置的迭代器）

C. choiceC()中(1)处的输出是0

D. choiceD()中第(2)处会出现运行错误，因为insert操作使得迭代器end失效

E. choiceE()中(3)处会出现运行错误，因为erase操作使得迭代器result失效
~~~

5.【多选】请阅读或执行以下代码，下列说法正确的是
~~~C++
#include <iostream>
#include <map>

void choiceA(std::map<std::string, int> m) {
    m["Monday"] = 100; // (1)
    std::cout << m.count("Monday") << std::endl; // (2)
}

void choiceB(std::map<std::string, int> m) {
    m.insert(std::pair<int, std::string>(200, "Tuesday")); // (3)
    std::cout << m.count("Tuesday") << std::endl; // (4)
}

void choiceC(std::map<std::string, int> m) {
    auto result = m.find("May");
    auto tmp = result == m.end();
    std::cout << tmp << std::endl; // (5)
}

void choiceD(std::map<std::string, int> m) {
    m.erase(++m.begin(), --m.end());
    std::cout << m.size() << std::endl; // (6)
}

void choiceE(std::map<std::string, int> m) {
    for (auto element: m) {
        std::cout << element.first << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::map<std::string, int> m;
    m["Sunday"] = 0;
    m["Monday"] = 1;
    m["Tuesday"] = 2;
    m["Wednesday"] = 3;
    m["Thursday"] = 4;
    m["Friday"] = 5;
    m["Saturday"] = 6;
    choiceA(m);
    choiceB(m);
    choiceC(m);
    choiceD(m);
    choiceE(m);
    return 0;
}
A. choiceA()中(1)处能够执行，(2)处的输出是1

B. choiceB()中(3)处能够执行，(4)处的输出是1

C. choiceC()中(5)处的输出是1

D. choiceD()中(6)处的输出是1

E. choiceE()的输出是Sunday Monday Tuesday Wednesday Thursday Friday Saturday，以换行符结尾。
~~~
6.【多选】以下说法正确的是
A. 路由器设计中会含有ARP表，ARP表记录了IP地址与MAC地址的映射关系（即建立IP地址与MAC地址的一一对应关系）。ARP表的设计实现与std::map容器类似

B. 可以使用std::map容器统计一篇文章的词频

C. c++中想让一个 计算函数 返回错误信息和计算结果，错误信息为std::string error_info，计算结果为int calculation，返回值类型可以采用std::pair<std::string, int>、std::tuple<std::string, int>类型

D. 小新想维护一个排队购票系统，记录每个排队者的信息，需要从队尾加入新的排队者或从队头删去排队者信息，可以选用std::list，也可以选用std::queue

E. 使用std::vector过程中，因多次调用push_back()，发生了数组容量的动态扩充，则容量扩充之前的旧迭代器失效

7.【多选】阅读以下代码（linux环境下保存为main.sh）
~~~bash
#!/bin/bash
filename=test
for par in $@;
do
mkdir output-$par && python ${filename}.py $par 
done
同目录下的test.py为

import sys

print(sys.argv[1])
~~~
这个python脚本的意义为打印传递给脚本的一个参数，例如python test.py 2022oop，其执行结果为输出2022oop。

下列说法正确的是

A. 为了美观可以在filename=test的等号边加上空格，即修改为filename = test，bash脚本仍能运行、功能不变。

B. 同目录下依次执行bash main.sh 2022oop，bash main.sh 2022oop thu111year，第二次执行的时候，python脚本只会被执行一次，执行时输出thu111year

C. 同目录下多次执行该脚本后，新建了很多output-xxx的目录，可以通过rm -rf output-*将所有新建的目录清空

D. 小明在resume.md中使用 ![](/home/xiaoming/selfie.png)插入了一张照片，他将该resume.md通过微信发送给了老师，老师在接收文件后就能看到小明的照片

E. 要实现删除线效果，markdown中应该输入~删除线~

8.【多选】以下说法正确的是
A. 在不配置git config --global user.email <email>与git config --global user.name <name>的情况下，用户也能向远端GitHub仓库进行git push

B. 小华git clone了一个远端项目仓库后，他在本地对仓库内一个文件脚本run.sh进行了修改，但还没通过git add run.sh将文件加入git暂存区，也没有提交新的commit。他觉得不妥，他希望放弃这次修改，他可以通过git checkout run.sh放弃本地的修改

C. git branch test会创建名为test的分支并且切换到test中

D. 如果在本地仓库中添加.gitignore文件，并且写入*.cpp，那么之后在该仓库内无法通过git add test.cpp将仓库内test.cpp的修改记录暂存到本地仓库内



```

ABCDE
BC
BD
```
