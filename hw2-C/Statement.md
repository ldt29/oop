### 题目描述
你需要在这份代码(见problem_76.zip)的基础上帮忙完善Map类的实现（补充Map.h和Map.cpp）。Map类是一个能够实现std::string到int的映射的容器类，具有如下特性：

* 一个Map对象含有两个数据成员如下：
```
#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    // TODO
};
```
构造函数Map(int n);的形参int n指示被创建的Map对象需要能够容纳不多于n个键值对，一个键值对由Pair类的一个对象维护。你需要在构造函数内开辟一个大小为n个Pair对象的数组，并让数据成员data指向该数组的首位。

数据成员sz表明Map对象实际包含的键值对数量（必有0≤ sz ≤n)。

* 假定s是一个string对象，map是一个Map对象，则调用map[s]满足如下性质：

    * 如果map是常量且s是map的一个键：map[s]返回s对应的值，只能读，不能写
    * 如果map是常量且s不是map的一个键：map[s]返回默认值0
    * 如果map不是常量且s是map的一个键：map[s]返回s对应的值，能读写
    * 如果map不是常量且s不是map的一个键：map[s]将s和默认值0配对添加到map中，并返回s对应的值，能读写
### 输入输出
* main.cpp文件读取输入并构造一个Map类对象map（及其常量引用cmap）进行测试；
* 输入第一行是两个用空格隔开的整型数：n和k，其中n表示被测试的Map对象的最大容纳量为n个键值对，n >0；
* 输入后面是k行，每行是如下三种格式中的一种：
    * 1 [key]: 查询并输出map中键为[key]（字符串）对应的值，输出占一行
    * 2 [key] [val]：将map中键为[key]的值改为[val]（整型数）
    * 3 [key]：查询并输出cmap中键为[key]（字符串）对应的值，输出占一行
* 最后输出map实际包含的键值对数量。
### 提交格式
* 你需要提交多个文件，包含Map.h和Map.cpp，可以不包括提供的Map.h之外的其他文件。
* 你应该将你的文件打包成一个zip压缩包并上传。注意：你的文件应该在压缩包的根目录下，而不是压缩包的一个子文件夹下。评测时，OJ会将除Map.h和Map.cpp之外的评测所需的文件（包括main.cpp等）贴入你的目录下进行编译并执行。
