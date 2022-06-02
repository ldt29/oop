你需要使用C++继承和多态的特性来模拟外星人。有以下一段代码（main.cpp）：
```
void doSpeak(WhatCanSpeak* obj) { 
  obj->speak();
  obj->stop();
}
void doMotion(WhatCanMotion* obj) {
  obj->motion();
  obj->stop();
}

int main()
{
  std::string name;
  std::cin >> name;
  Alien alien(name);
  doSpeak(&alien);
  doMotion(&alien);
  return 0;
}
```
其中WhatCanSpeak和WhatCanMotion类都已经写好：
```
class WhatCanSpeak {
public:
  virtual ~WhatCanSpeak() {std::cout << "obj cannot speak" << std::endl; }
  virtual void speak() = 0;  
  virtual void stop() = 0;  
};
class WhatCanMotion {
public:
  virtual ~WhatCanMotion() {std::cout << "obj cannot move" << std::endl; }
  virtual void motion() = 0;
  virtual void stop() = 0;  
};
```
你需要补充头文件alien.h，使得程序能够编译通过。

文件下载地址：下载链接见problem_61.zip

### 输入说明
输入是一个字符串，是alien的名字。

### 输出说明
输出一共六行，请观察样例。

### 输入样例
```
alice
```
### 输出样例
```
alice is speaking
alice stops
alice is moving
alice stops
obj cannot speak
obj cannot move
```
### 提交格式
你只能提交头文件alien.h 我们会将你提交的文件和我们预先设置好的main.cpp, what.h一起编译运行。

### 评分标准
OJ评分占100%。
