## 题目描述
小明最近了解了动态语言（python和javascript），这些语言中变量的类型是动态的，因此可以为同一个变量赋予不同类型的值。小明想在C++中也做到类似的事情，于是它设计了一个类Object，任意的变量都可以储存进该类中。具体来说：
```cpp
//subtask 1
Object x;
x = 1;
std::cout << x << std::endl; //1
x = std::string("text");
std::cout << x << std::endl; //text
x = CustomClass("obj1"); //a user-defined class
```
Object一般都是以引用的形式储存数据，这种方式可以避免多余的复制操作。这也使得有时候对某一Object的修改导致另一Object的变化，举例来说：
```cpp
//subtask 2
Object x, y, z;
x = 1;
y = x; // y point to the same value of x
z = CustomClass("obj2");
std::cout << x << " " << y << std::endl; //1 1

x += 1;
std::cout << x << " " << y << std::endl; //2 2

x = std::string("text"); // x points to "text", but y still points to 2
std::cout << x << " " << y << std::endl; //text 2

y = x;
x += std::string("1");
std::cout << x << " " << y << std::endl; //text1 text1
x = z;
```
注意这里=和+=的不同，=是让Object改为储存另一个数据，+=是修改储存的数据。

接下来，小明考虑让std::vector能够装进不同类型的对象。
```cpp
//subtask 3
std::vector<Object> arr;
arr.push_back(Object(1));
arr.push_back(Object("text"));
arr.push_back(Object(CustomClass("obj3")));
std::cout << arr[0] << " " << arr[1] << std::endl; //1 text
arr[0] = arr[1];
std::cout << arr[0] << " " << arr[1] << std::endl; //text text
arr[1] += std::string("1");
std::cout << arr[0] << " " << arr[1] << std::endl; //text1 text1
arr[0] = arr[2];
std::cout << arr[1] << std::endl; //text1
```
如果将std::vector赋给Object，甚至能够做到在std::vector中包含std::vector。对于以下代码，如果存在理解困难，下载文件中提供了一个instruction.pdf解释了操作的过程。
```cpp
//subtask 4
std::vector<Object> inner_arr1 = {Object(1), Object("text1"), CustomClass("obj4")};
std::vector<Object> inner_arr2 = {Object(2), Object("text2")};
std::vector<Object> arr = {Object(inner_arr1), Object(inner_arr2), CustomClass("obj5")};

std::cout << arr[0][0] << " " << arr[0][1] << std::endl; // 1 text1
std::cout << arr[1][0] << " " << arr[1][1] << std::endl; // 2 text2

arr[1] = arr[0];
std::cout << arr[1][0] << " " << arr[1][1] << std::endl; // 1 text1

arr[0][0] += 2;
std::cout << arr[0][0] << " " << arr[1][0] << std::endl; // 3 3

arr[0][1] = arr[1][0]; // arr[1][1] and arr[0][1] is the same Object
std::cout << arr[0][1] << " " << arr[1][1] << std::endl; // 3 3

arr[0][0] = arr[2];
```
* 为了简单考虑，我们对题目做出以下限制：  
    * 只要求`Object`能够储存以下类型`int`，`std::string`，`std::vector<Object>`，`CustomClass`。其中`CustomClass`是一个用户自定义类，该类会统计其对象构造与析构的次数，并测试你的代码是否存在内存泄露。
    * `+=`运算右侧只会出现`int`和`std::string`，并且保证类型与`Object`中存储的类型一致。
    * 中括号运算`[]`只会对储存了`std::vector<Object>`的`Object`使用，并且保证不会越界访问。  
 
小明已经完成了部分代码，但是调试一直没法通过。你需要帮助他改好相应的功能（或者自己重新实现），并通过测试程序。main.cpp为测试程序，Object.h是小明实现的部分代码。 文件下载地址：下载链接，见problem_64.zip。

如果觉得太困难，你可以选择完成一部分的功能以获取一部分的分数，请看评分标准。

### 对小明代码的解释
你可以采用小明的代码，也可以完全不使用小明的代码，他的代码只作为本题的提示。你只用提交Object.h，通过测试即可。

需要注意的是，小明的已完成的代码里包含一些错误和未完成的部分，你需要进行修改。提示：包含STL的程序往往编译错误较多，建议每次先解决第一个error，然后重新编译。

这里对小明的设计做一些解释。小明首先发现，Object储存的都是引用，而不应该是真实的值（因为两个Object可能指向同一个值，分开储存无法做到同时修改）。因此，小明新增了一个Content类，该类作为真正储存数据的位置。Object储存了指向Content的指针。由于Content可以储存不同类型的数据，因此该类应该是一个基类，其派生类IntContent,StringContent,VectorContent,CustomContent分别储存int, std::string, std::vector<Object>, CustomClass数据。

该设计的示意图可以参考instruction.pdf。小明在大部分存在问题的地方添加了注释，请仔细阅读注释中给予的提示完成代码。

### 提交格式
你只能提交头文件Object.h

我们会将你提交的文件和我们预先设置好的main.cpp和CustomClass.h一起编译运行。

### 评分标准
我们会有1个样例测试点，即下发的main.cpp。另外有1个隐藏测试点，会相应的更改main.cpp中内容进行测试。一般来说，如果正确实现了题目要求，并能通过样例测试点（而不是通过某种方法直接输出标准答案），也应该能够通过隐藏测试点。（若提交后存在问题，请及时联系助教。）

本题按照以上描述分为了4个子任务，每个子任务各占25分。只有你通过了同一个子任务的样例测试点和隐藏测试点，你才能获得该子任务的分数。如果你的程序在样例测试点或隐藏测试点中出现了内存泄露，该子任务只会获得15分。

注意你不用同时通过4个子任务再提交，我们会将每一个子任务的代码拆开，分别编译。（但是后一个子任务会依赖于前一个子任务，例如：如果想要第三个子任务正确，必须先保证第一、二个子任务正确。）

考试100%为OJ评分。

