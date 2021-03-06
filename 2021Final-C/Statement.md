## 题目描述
现有一个用户通讯系统，其中RealUser类支持sendMessage函数，该函数将输出两行信息：用户名和消息。

该系统有两个缺点，它采用的是明文传输，并且无法验证消息在传输中的完整性。现需要升级系统，希望在不改变原来类的相关代码的情况下，增加以下功能：

1. 加密传输，在消息发送时增加加密操作；
2. 消息验证，消息发送方在发送消息时多发送一行消息验证码。

增加以上功能后，能够使得消息的传输更加安全与可靠。举例来说，user1发送消息I_love_oop.，在原来的系统中将发送：
```
user1
I_love_oop.
```
新的系统中将发送：
```
user1
I#_#l#o#v#e#_#o#o#p#.#  (加密的消息，具体看下方解释)
I_l  （消息的验证码，具体看下方解释）
```
加密方式有以下两种：

* 插入字符加密：每隔一个字符插入字符 #

* 倒序加密：将字符全部倒转

  * 加密前：I_love_oop.

  * 插入字符加密：I#_#l#o#v#e#_#o#o#p#.#

  * 倒序加密：.poo_evol_I

消息验证码生成方式也有以下两种：

* 前缀验证：验证码为消息的前3个字符（题目数据保证每条消息长度均超过3）

* 间隔验证：验证码为从消息的第1个字符开始，每隔1个字符抽取1个字符组合而成

  * 消息：I_love_oop.

  * 前缀验证：I_l

  * 间隔验证：Ilv_op

请你帮助完善这个系统，实现中可能会使用到策略模式和代理模式。

我们已经提供了Makefile，main.cpp，User类User.h，同时也给出了两种策略的基类EncryptStrategy.h，VerificationStrategy.h，你可以进一步对策略头文件进行修改，并实现UserProxy.h。代码下载地址：下载链接见problem_98.zip

### 样例输入
第一行为整数 N ，表示接来下将有 N 轮对话

接下来 N 行，每行包含四个部分，一个用户名，两个整数 p、 q和一个没有空格的语句 s。p 用来表示加密类型，其中 1 表示插入字符加密，2 表示倒序加密；q 用来指示验证类型，其中 1 表示前缀验证，2 表示间隔验证；s 表示该轮对话中发送方应该发送的内容。
```
3
1 1 uname1 I_love_oop.
1 2 uname2 Glad_to_meet_you.
2 1 uname3 Happy_Dragon_Boat_Festival.
```
样例输出
输出为 3N 行，每行为 1 个字符串，每三行对应一次发送，每行分别为发送方用户名，发送方加密后的消息、验证码。
```
uname1
I#_#l#o#v#e#_#o#o#p#.#
I_l
uname2
G#l#a#d#_#t#o#_#m#e#e#t#_#y#o#u#.#
Ga_ome_o.
uname3
.lavitseF_taoB_nogarD_yppaH
Hap
```
### 提示与要求
* 由于这些策略较为简单，你可以直接将函数实现写在头文件，不需要将声明与实现分开。
* 你需要提交EncryptStrategy.h，VerificationStrategy.h和UserProxy.h。我们会将提供的main.cpp、Makefile、User.h贴入到你的文件夹下一起编译。
### 评分标准
OJ评分 100%

