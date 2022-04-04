## 题目描述
* 现有Test类定义如下：
```
#include <iostream>

using namespace std;

class Test {
    int *buf;
public:
    Test() {
        buf = new int(0);
        cout << "Test(): this->buf @ " << hex << buf << endl;
    }
    Test(int val) {
        buf = new int(val);
        cout << "Test(int): this->buf @ " << hex << buf << endl;
    }
    ~Test() {
        cout << "~Test(): this->buf @ " << hex << buf << endl;
        if (buf) delete buf;
    }
    Test(const Test& t) : buf(new int(*t.buf)) {
        cout << "Test(const Test&) called. this->buf @ "
            << hex << buf << endl;
    }
    Test(Test&& t) : buf(t.buf) {
        cout << "Test(Test&&) called. this->buf @ "
            << hex << buf << endl;
        t.buf = nullptr;
    }
    Test& operator= (const Test& right) {
        if (this != &right){
            if(buf) delete buf;
            buf = new int(*right.buf);
        }
        return *this;
    }
    Test& operator= (Test&& right) {
        if (this != &right){
            if(buf) delete buf;
            this->buf = right.buf;
            right.buf = nullptr;
        }
        return *this;
    }
    void print(const char *name) {
        cout << name << ".buf @ " << hex << buf << endl;
    }
};
```
* 下列有5个使用Test类的小程序
```
// A
0: Test F(Test a){
1:     Test b = std::move(a);
2:     return b;
3: }
4: int main(){
5:     Test a;
6:     a = 1;
7:     Test A = F(a);
8:     return 0;
9: }

// B
0: Test F(const Test& a){
1:     Test b = std::move(a);
2:     return b;
3: }
4: int main(){
5:     Test A = F(1);
6:     return 0;
7: }

// C
0: Test F(Test &&a){
1:     Test b = std::move(a);
2:     return b;
3: }
4: int main(){
5:     Test A = F(1);
6:     return 0;
7: }

// D
0: Test&& F(Test &a){
1:     Test b = a;
2:     return std::move(b);
3: }
4: int main(){
5:     Test A = F(Test(1));
6:     return 0;
7: }

// E
0: const Test& F(const Test& a){
1:     Test b = a;
2:     return Test(1);
3: }
4: int main() {
5:     Test a;
6:     const Test &A = F(std::move(a));
7:     return 0;
8: }
```
* 你需要按如下要求填写annotation.json文件（见problem_108.zip），为上面每一段程序标注构造函数、复制构造函数、移动构造函数、赋值运算、移动赋值运算被调用的所有位置
```
{
    "A": { // 对程序A的标注
        "status": "", // 若程序A存在编译错误或潜在风险，"status"的值标注为"error"，以下5个字段无需标注，否则"status"的值为"ok"，并标注以下5个字段
        "constructor": [], // 填写构造函数在程序A中被调用的所有行号，用逗号分隔，如，[0, 1]；如无调用，则无需标注
        "copy_constructor": [], // 填写拷贝构造函数在程序A中被调用的所有行号，用逗号分隔，如，[0, 1]；如无调用，则无需标注
        "move_constructor": [], // 填写移动构造函数在程序A中被调用的所有行号，用逗号分隔，如，[0, 1]；如无调用，则无需标注
        "assignment_operator": [], // 填写赋值运算在程序A中被调用的所有行号，用逗号分隔，如，[0, 1]；如无调用，则无需标注
        "move_assignment_operator": [] // 填写移动赋值运算在程序A中被调用的所有行号，用逗号分隔，如，[0, 1]；如无调用，则无需标注
    },
    "B": { // 对程序B的标注参考上述说明
        ...
    }
    "C": {
        ...
    }
    ...
}
```
注意：如果构造或赋值运算发生在函数调用内部（包括参数对象的构造、函数体、所返回临时对象的构造，不包括所返回临时对象被用于构造或赋值的过程），则应当标注函数定义中相应的行号，不要标注函数调用所在行（如程序A中的第7行）

### 编译选项
```
g++ main.cpp -o main -lm -O2 -DONLINE_JUDGE -fno-elide-constructors -std=c++11
```
### 提交文件
* 你需要提交标注后的annotation.json文件，在作业结束前，只显示程序A、B的标注得分（最高显示40分）；作业结束后公布最终得分（满分100分）。
### 评分标准
* OJ评分占100%，每个小程序的标注占20%。
