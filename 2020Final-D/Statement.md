### 题目描述
一家跨国公司需要向员工们发放工资，他们找到你，他们想知道每个员工到手的工资是多少？

这家公司由两种类型的员工组成：

* 销售人员 SalesmanStrategy
* 开发人员 DeveloperStrategy
这两种员工的工资均有基础工资(base)+奖金(bonus)构成，但他们的奖金有着不同的考核标准。 销售人员的奖金由签单率决定奖金获得比例，具体换算如下表:

|签单率X|	奖金获得比例|
|-|-|
|X < 60%	|0|
|60 <= X < 70%|	60%|
|70 <= X < 80%|	70%|
|80 <= X < 100%|	100%|

开发人员的奖金由上级部门根据KPI完成情况评级打分，具体换算如下表（保证得分一定是下表中存在的值）:

|得分X|	奖金获得比例|
|-|-|
|X = 20	|20%|
|X = 40|	40%|
|X = 60	|60%|
|X = 80|	80%|
|X = 100|	100%|

另一方面，根据分公司所处地方不同，公司总部有以下三种方式向员工支付:

* 国内转账 NormalStrategy, 无需手续费
* 跨国转账 SwiftStrategy, 转账金额小于等于10000元时手续费为10元，大于10000元时手续费为转账金额的千分之一 (20元封顶)
* 比特币转账 BitcoinStrategy, 转账手续费为每字节0.01元，金额由8字节的double类型存储，如向zhangsan转账1000元，需支付 (len(zhangsan)+8) * 0.01=0.16 元手续费

题目已提供main.cpp，请使用策略模式补充Calculator.h/OccupationStrategy.h/PayStrategy.h，实现计算类/工资计算策略类/转账策略类。注意：我们已经提供了部分不完整的声明，请完善这部分实现，不要重新使用别的声明或采用其他方法。具体来说，你提交的程序必须满足OccupationStrategy中应有double getSalary(double, double, double)函数，PayStrategy中应有double pay(string, double)函数。

文件下载地址：下载链接见problem_63.zip

### 输入样例
第一行为两个以空格隔开的字符串，分别表示员工类型(Salesman/Developer)和转账类型(Normal/Swift/Developer)，具体参考main.cpp。

接下来若干行，每行四个元素，分别为按此方式结算的员工名称，基础工资，奖金，签单率/得分。
```
样例1:
Salesman Swift
zhangsan1 8000 5000 50
zhangsan2 8000 5000 60
zhangsan3 20000 5000 100
样例2:
Developer Bitcoin
zhangsan 8000 5000 80
DalabonBarbandBedibuDobiruon 30000 5000 20
```
### 输出样例
若干个实数，每个实数保留两位小数，表示每位员工的到手工资。
```
样例1:
7990.00
10989.00
24980.00
样例2:
11999.84
30999.64
```
### 要求
不修改 main.cpp
完善 Calculator.h/OccupationStrategy.h/PayStrategy.h 中的实现
### 提交格式
你应该将 Calculator.h/OccupationStrategy.h/PayStrategy.h 打包成一个zip压缩包并上传，我们会将 main.cpp 复制进你上传的文件中编译并运行。编译命令:
```
g++ main.cpp -o main -lm -O2 -DONLINE_JUDGE --std=c++14
```
如果出现编译错误，首先检查你的文件是否在压缩包根目录下。换句话说，压缩包内不应该包含任何文件夹。

### 评分标准
OJ评分占100%。其中60%得分来自于检测你的程序是否能完成相应功能。剩下40%为隐藏测试点，将检测你的程序是否正确使用了策略模式，请注意策略模式的设计规范（包括但不限于以下几点：正确实现题目要求的函数，正确实现析构函数，正确使用抽象类）。
