## 题目描述
注意：请合理安排考试时间，可以选择实现部分任务以获得部分分数

小明最近学习了C++的多态，多态的一个重要意义是为不同类型的对象复用相同的代码。小明尝试设计了一个MagicArray，这个MagicArray不保存具体数值，但可以对它及它的元素做一些操作，这些操作将被记录下来，之后能够复用到一个同样长度的std::vector容器中去。

首先为了简单，小明只允许arr[0] += i这样的操作，其中数组长度固定为1，i为int类型。具体来说：
```cpp
//subtask1
MagicArray arr(1);  // create a MagicArray with length=1
for(int i = 0; i < 10;  i++){
    arr[0] += 1; // create and store 10 instructions: arr[0] += 1
}

cout << "#### Test Case 1-1 ####" << endl;
std::vector<int> vec1{0};
arr.apply(vec1); //apply "vec1[0] += 1" for 10 times
cout << vec1[0] << endl; // 10

cout << "#### Test Case 1-2 ####" << endl;
std::vector<int> vec2{5};
arr.apply(vec2); //apply "vec2[0] += 1" for 10 times
cout << vec2[0] << endl; // 15

cout << "#### Test Case 1-3 ####" << endl;
std::vector<double> vec3{1.5}; // You can even use vector<double>
arr.apply(vec3); //apply "vec3[0] += 1" for 10 times
cout << vec3[0] << endl; // 11.5
```
接下来，小明希望进一步增加两个功能：

MagicArray能够支持更长的数组
为了记录arr[0] += i这一操作，同时支持进一步拓展，你需要定义一个Instruction的派生类对象。代码在调用arr[0] += i的同时，一个派生类对象将会被创建并储存起来，作为操作记录。同时为了方便调试，MagicArray能够通过输出记录的所有操作。
```cpp
//subtask2
MagicArray arr(5);  // create a MagicArray with length=5
for(int i = 0; i < 5;  i++){
    arr[i] += i; // create and store 10 instructions: arr[0] += i
}

cout << "#### TestCase 2: Output Instructions ####" << endl;
static_assert(std::is_abstract<Instruction>(), "Instruction should be an abstract class");
std::vector<Instruction*> &instructions = arr.getInstructions();
for(auto ins : instructions) {
    ins -> output(); // output the stored instructions
}
// arr[0] += 0
// arr[1] += 1
// arr[2] += 2
// arr[3] += 3
// arr[4] += 4

cout << "#### TestCase 2-1 ####" << endl;
std::vector<int> vec1{0, 0, 0, 0, 0};
arr.apply(vec1);
for(auto x : vec1) cout << x << " "; // 0 1 2 3 4
cout << endl;

cout << "#### TestCase 2-2 ####" << endl;
std::vector<double> vec2{5.5, 4.4, 3.3, 2.2, 1.1};
arr.apply(vec2);
for(auto x : vec2) cout << x << " "; // 5.5 5.4 5.3 5.2 5.1
cout << endl;
其中，Instruction为抽象类，小明已经写好了该基类的接口。如果有必要，你也可以对该接口做一些修改。

class Instruction
{
public:
    virtual void apply(std::vector<int> &vec) = 0;
    virtual void apply(std::vector<double> &vec) = 0;
    virtual void output() = 0;
};
```
接下来，小明希望MagicArray可以支持更多操作，例如a[i] = a[j]和a[i] += a[j] （保证操作符右边一定直接是形如a[j]的数组元素，而不是a[j]+a[k]这样的表达式）。
```cpp
//subtask3
MagicArray arr(3);  // create a MagicArray with length=3
for(int i = 0; i < 2;  i++){
    arr[i+1] += arr[i];
    arr[i] = arr[i+1];
    arr[i] += i+1;
}
arr[2] += arr[2];

cout << "#### TestCase 3: Output Instructions ####" << endl;
static_assert(std::is_abstract<Instruction>(), "Instruction should be an abstract class");
std::vector<Instruction*> instructions = arr.getInstructions();
for(auto ins : instructions) {
    ins -> output();
}

// arr[1] += arr[0]
// arr[0] = arr[1]
// arr[0] += 1
// arr[2] += arr[1]
// arr[1] = arr[2]
// arr[1] += 2
// arr[2] += arr[2]

cout << "#### TestCase 3-1 ####" << endl;
std::vector<int> vec1{0, 0, 0};
arr.apply(vec1);
for(auto x : vec1) cout << x << " "; //1 2 0
cout << endl;

cout << "#### TestCase 3-2 ####" << endl;
std::vector<double> vec2{0.3, 0.2, 0.1};
arr.apply(vec2);
for(auto x : vec2) cout << x << " "; //1.5 2.6 1.2
cout << endl;
```
最后，小明为MagicArray添加了一个输出操作，例如cout << arr[i]。该输出操作不会立即执行，而是会等到调用apply时才会进行输出。为了在apply的输出中换行，小明使用了个特殊函数arr.endl()。
```cpp
//subtask4
MagicArray arr(3);  // create a MagicArray with length=3
arr[2] += arr[2];
for(int i = 0; i < 2;  i++){
    arr[i] += arr[i+1];
    cout << arr[i] << arr.endl(); // arr.endl() is a special object for linebreak
    arr[i] += i + 1;
    arr[i+1] = arr[i];
}

cout << "#### TestCase 4: Output Instructions ####" << endl;
static_assert(std::is_abstract<Instruction>(), "Instruction should be an abstract class");
std::vector<Instruction*> instructions = arr.getInstructions();
for(auto ins : instructions) {
    ins -> output();
}
// arr[2] += arr[2]
// arr[0] += arr[1]
// cout << arr[0]
// cout << endl
// arr[0] += 1
// arr[1] = arr[0]
// arr[1] += arr[2]
// cout << arr[1]
// cout << endl
// arr[1] += 2
// arr[2] = arr[1]

cout << "#### TestCase 4-1 ####" << endl;
std::vector<int> vec1{3, 2, 1};
arr.apply(vec1);
//5
//8
for(auto x : vec1) cout << x << " "; //6 10 10
cout << endl;

cout << "#### TestCase 4-2 ####" << endl;
std::vector<double> vec2{0.3, 0.2, 0.1};
arr.apply(vec2);
//0.5
//1.7
for(auto x : vec2) cout << x << " "; //1.5 3.7 3.7
cout << endl;
```
* 提示：
  * 你应该自定义一个类型作为MagicArray中operate[]返回的元素
  * 对于MagicArray及其元素的任意操作都应转换为相应的Instruction派生类，储存在MagicArray中
* 为了简单考虑，我们对题目做出以下限制：
  * 你只用考虑vector<int>和vector<double>
  * 元素下标访问保证不会越界
  * 保证apply中传入的vector长度与MagicArray一致
  * 保证输出流对象只会使用cout，需要在apply中输出的对象只有MagicArray的元素或arr.endl()
* 我们的main.cpp和Makefile已经给定，同时我们也给出了Instruction.h的基类接口。如果需要，你可以适当修改Instruction.h。该Makefile将自动的将该目录下的所有的后缀名为cpp的程序编译并链接。
  * 特殊地，Makefile支持测试部分subtask。如果你只想测试subtask1，可以使用make subtask1命令。
  * 你可以修改Instruction.h，但不能修改main.cpp和Makefile。无论你是否修改Instruction.h，你都应该上传该文件。
* 文件下载地址：下载链接见problem_96.zip。
### 样例输出
针对我们给出的main.cpp，输出如下。
```py
#### Test Case 1-1 ####
10
#### Test Case 1-2 ####
15
#### Test Case 1-3 ####
11.5
#### TestCase 2: Output Instructions ####
arr[0] += 0
arr[1] += 1
arr[2] += 2
arr[3] += 3
arr[4] += 4
#### TestCase 2-1 ####
0 1 2 3 4 
#### TestCase 2-2 ####
5.5 5.4 5.3 5.2 5.1 
#### TestCase 3: Output Instructions ####
arr[1] += arr[0]
arr[0] = arr[1]
arr[0] += 1
arr[2] += arr[1]
arr[1] = arr[2]
arr[1] += 2
arr[2] += arr[2]
#### TestCase 3-1 ####
1 2 0 
#### TestCase 3-2 ####
1.5 2.6 1.2 
#### TestCase 4: Output Instructions ####
arr[2] += arr[2]
arr[0] += arr[1]
cout << arr[0]
cout << endl
arr[0] += 1
arr[1] = arr[0]
arr[1] += arr[2]
cout << arr[1]
cout << endl
arr[1] += 2
arr[2] = arr[1]
#### TestCase 4-1 ####
5
8
6 10 10 
#### TestCase 4-2 ####
0.5
1.7
1.5 3.7 3.7
```
### 提交格式
你可以提交一个压缩包，其中必须包含MagicArray.h和Instruction.h。我们会将你提交的文件和我们预先设置好的main.cpp、Makefile一起编译运行。

注意：你的文件应该在压缩包的根目录下，而不是压缩包的一个子文件夹下。若发现提交后OJ反馈不正常，请尽快与监考老师联系。

### 评分标准
我们会有1个样例测试点，即下发的main.cpp。另外有1个隐藏测试点，会相应的更改main.cpp中内容进行测试。一般来说，如果正确实现了题目要求，并能通过样例测试点（而不是通过某种方法直接输出标准答案），也应该能够通过隐藏测试点。（如果出现问题，你可以自行测试一些边界情况。）

本题按照以上描述分为了4个子任务，每个子任务各占25分。只有你通过了同一个子任务的样例测试点和隐藏测试点，你才能获得该子任务的分数。

* subtask1：保证MagicArray长度为1，只有+= (int)操作
* subtask2：保证MagicArray长度小于100，在subtask1基础上，需要输出Instruction
* subtask3：保证MagicArray长度小于100，在subtask2基础上，有+= a[j]、= a[j]操作
* subtask4：保证MagicArray长度小于100，在subtask3基础上，有cout << a[j]、cout << arr.endl()操作。
注意你不用同时通过4个子任务再提交，我们会将每一个子任务的代码拆开，分别编译。（但是后一个子任务会依赖于前一个子任务，例如：如果想要第三个子任务正确，必须先保证第一、二个子任务正确。）

考试100%为OJ评分。

