## 题目描述
本题需要用类模拟鸟类（Bird）和鱼类（Fish）两种动物，实现歌唱（sing）和游泳（swim）两个方法。两种动物都有红色（Red）和蓝色（Blue）两种。鸟类会歌唱但不会游泳，鱼类会游泳但不会歌唱。对某种动物调用方法时，需要输出对应的动物、方法以及颜色信息。例如，对红色的鸟类调用 sing 方法时，输出 Red bird is singing.，对任何颜色的鸟类调用 swim 方法时，输出Bird can not swim.。同理，对蓝色的鱼类调用 swim 方法时，输出 Blue fish is swimming.，对任何颜色的鱼类调用 swim 方法时，输出Fish can not sing.。当动物类被析构时，也需要输出相关信息，例如蓝色的鸟类被析构，输出 Blue bird is gone.。

要求：

* 使用抽象类 Animal表示动物，Bird和Fish两个类继承自Animal。你需要实现虚函数以便通过指向Animal的指针访问Bird和Fish的实例。
* 根据题目提供的 main.cpp 文件（见problem_118.zip）进行数据的输入输出。你需要实现Animal.h，Bird.h和Fish.h三个文件。
### 输入说明
输入第一行时是 n（5≤n≤10000），代表模拟的次数。

接下来n行，每行有两个0或1的整数op和color，op为0代表构造鸟类，op为1代表构造鱼类。color为0代表构造的动物为红色，color为1代表构造的动物为蓝色。

### 输出说明
输出若干行，为每次模拟得到的信息。

### 输入样例
```
8
0 0
1 0
0 0
1 0
0 1
1 1
0 1
1 1
```
### 输出样例
```
Red bird is singing.
Bird can not swim.
Red bird is gone.
Fish can not sing.
Red fish is swimming.
Red fish is gone.
Red bird is singing.
Bird can not swim.
Red bird is gone.
Fish can not sing.
Red fish is swimming.
Red fish is gone.
Blue bird is singing.
Bird can not swim.
Blue bird is gone.
Fish can not sing.
Blue fish is swimming.
Blue fish is gone.
Blue bird is singing.
Bird can not swim.
Blue bird is gone.
Fish can not sing.
Blue fish is swimming.
Blue fish is gone.
```
### 提交格式
你需要提交Animal.h，Bird.h和Fish.h三个文件。我们会将你提交的文件和我们预先设置好的main.cpp、makefile一起编译运行。

### 评分标准
考试100%为OJ评分。
