有一段不完整的程序，你需要在(1)~(9)处填入代码，并使得程序的输出和标准输出(stdout.txt)一致，文件内容见problem_45.zip。

### Example.h
```
#ifndef __EXAMPLE__
#define __EXAMPLE__

class Example {

private:

    (1)

public:

    Example(int data);
    void getData();
    ~Example();
};

#endif
```
### Example.cpp
```
#include <iostream>
#include "Example.h"

using namespace std;

    (2)

Example::Example(int data) {
    (3)
}

void Example::getData() {
    (4)
}

Example::~Example() {
    (5)
}
```
### main.cpp
```
#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {

    cout << "--------create_example is ready--------\n";

    Example* e[10];

    for (int i = 0; i < n; i++)
        e[i] = new Example(i);

    (6)

    cout << "--------create_example is over--------\n";
}

    (7)

int main() {

    cout << "--------main_function is ready--------\n";

    (8)

    create_example(3);

    (9)

    cout << "--------main_function is over---------\n";

    return 0;
}
```
### stdout.txt
```
Example #1 is created
--------main_function is ready--------
Example #2 is created
--------create_example is ready--------
Example #3 is created
Example #4 is created
Example #5 is created
Example #6 is created
The data of Example #3 is 0
The data of Example #4 is 1
The data of Example #5 is 2
Example #3 is destroyed
Example #4 is destroyed
Example #5 is destroyed
The data of Example #6 is 2333
--------create_example is over--------
Example #7 is created
The data of Example #1 is 23
The data of Example #2 is 233
The data of Example #7 is 23333
--------main_function is over---------
Example #7 is destroyed
Example #2 is destroyed
Example #6 is destroyed
Example #1 is destroyed
```
说明： 在类实例化时，构造函数需输出“Example #XXX is created”。在析构时，需输出“Example #XXX is destroyed”。在调用 getData() 时，需输出“The data of Example #XXX is XXXX”。其中“#XXX”是实例的编号，编号从1开始累计增长，XXXX是实例里的数据。

提示：建议在类中增加一个成员变量，记录类已经有了多少实例了。建议在类中再增加一个成员变量，记录实例的编号。

注意：我们会检测你是否只是添加了代码，所以切记不要在(1)~(9)之外的地方改动、添加代码。

### 编译选项
```
g++ main.cpp Example.cpp -o main -lm -O2 -DONLINE_JUDGE --std=c++14
```
### 提交方式
提交三个文件：填好后的 Example.h、Example.cpp、main.cpp。

### 评分标准
OJ评分占100%。
