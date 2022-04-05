## 题目描述
《艾尔登法环 (Elden Ring)》是一款由日本开发商 From Software 开发、Bandai Namco 发行的黑暗幻想风格动作角色扮演游戏，玩家将扮演被称作“褪色者” (Tarnished) 的角色去战斗、探索、拯救或毁灭世界。不要慌，这个作业既不需要你玩过这款游戏，也不会让你开发这款游戏，只是需要你基于已有代码实现点儿简单的武器锻造模拟而已。已有代码在这里(见problem_110.zip)下载

褪色者在游戏中会收集到各式各样的武器，并且会利用锻造石来强化它们。

武器分为普通武器 (Normal Weapon) 与失色武器 (Somber Weapon) ，它们有各自的“武器名”。武器默认为零级，我们可以把它们强化到更高的等级，一般会在武器名后加上一个 +x 后缀表示（x≥1），为避免歧义我们将这种表示称作“扩展武器名”，特别的，没有强化过的武器的扩展武器名与武器名相同。

普通武器可以由 普通锻造石 k (Normal Smithing Stone k) 可以锻造出 +(3 * k-2) 到 +(3 * k)，分别需要 2、4、6 个（1≤k≤8）普通锻造石 k。失色武器由 1 个 失色锻造石 k (Somber Smithing Stone k)可以锻造出 +k （1≤k≤8）。（实际机制比这略复杂一点，出于关怀同学的目的，助教做了一定调整）

例如一把普通武器 匕首，可以通过 2 个 普通锻造石 1 强化到 +1，此时它的扩展武器名会变为 匕首+1；接下来用 4 个 普通锻造石 1、6 个 普通锻造石 1、2 个 普通锻造石 2 可以依次将它强化到 匕首+2、匕首+3、匕首+4。强化需要按照从低到高的顺序依次强化，不能跳步，例如你不能用 2 个 普通锻造石 2 将 匕首+2 直接强化为 匕首+4。

褪色者会把东西放到自己的物品栏中（即 Tarnished 的各个成员数组中的元素，用空指针表示物品栏为空），物品栏中的一个格子可以存放若干个同一种锻造石（如 普通锻造石 5）或者一把武器（不存在同名武器）。物品栏不会显示数量为 0 的物品，因此如果某种锻造石消耗一空，则你应该销毁（析构）对应的物品（对象）。

你需要完成的事情如下：

* 实现普通武器类 NormalWeapon 和失色武器类 SomberWeapon，它们继承自基类武器类 Weapon。
* 实现普通锻造石类 NormalSmithingStone 和失色锻造石 SomberSmithingStone，它们继承自基类锻造石类 SmithingStone。
* 褪色者类 Tarnished 的定义已经给出，它将由 普通/失色 武器/锻造石 类进行组合，你需要完成它的成员函数定义。
* 所有操作结束后，褪色者会销毁（析构）所有物品，销毁不同武器时，按照获得顺序析构；销毁不同等级锻造石时，按照等级从低到高顺序销毁；总的销毁顺序为普通锻造石、失色锻造石、普通武器、失色武器。
* 所有框架函数中实现的基类（即 Weapon 与 SmithingStone）的非常量成员函数（包括构造/析构函数、Weapon::upgrade、SmithingStone::add_amount）在被外部调用时都应该有新的输出，这里不再逐一赘述格式，请直接参照样例。
* 根据格式说明、样例展示和设计模式在你的程序的合适位置进行输出。
### 输入格式
第一行输入两个正整数 n 和 m，表示有 n 次操作，全局 magic number 为 m（magic number 用于一定程度上确定你确实正确继承了基类）。 接下来有 2n 行输入，每 2 行为一次操作，一次操作内部第一行为一个数字 operation，第二行内容由 operation 决定，规则如下：

1. 如果 operation 为 0，表示褪色者获得了若干锻造石，则第二行有 3 个数字 type, level, number：其中 type 为 0 表示普通锻造石，为 1 表示失色锻造石；level 表示锻造石等级，number 表示锻造石数量。
2. 如果 operation 为 1，表示褪色者得了一把武器，则第二行有一个数字 type 和一个字符串 name：其中 type 为 0 表示这是一把普通武器，为 1 表示这是一把失色武器；name 表示武器名。我们保证输入数据中所获得的武器的武器名两两不同，且仅由大小写字母组成。
3. 如果 operation 为 2，表示褪色者试图强化一把武器，则第二行有一个数字 target 和一个字符串 name，target 表示褪色者想强化到的等级，name 表示武器名。此时如果强化成功了，则输出 Upgrade <x> to <y> Successfully.，其中 <x> 为强化前的扩展武器名， <y> 为强化后的扩展武器名；如果锻造石不足导致强化失败，则输出 Upgrade failed for lacking <xxx>.，其中 <xxx> 为缺少的最低等级的锻造石名字（不需要输出缺失数量），格式如 normal smithing stone 2、somber smithing stone 3 ；如果褪色者没有该武器，则输出 You don't have the right!；如果 target 不大于武器当前等级，则不进行强化（也无法进行）并输出 Stay calm!
如果褪色者的锻造石足够将武器强化到预期目标，则成功强化武器并消耗掉相应的锻造石；否则褪色者会选择根本不强化这把武器（而不是强化到尽可能高的等级），也即强化失败。成功强化时注意你每消耗一级的锻造石，则应立刻完成一级的强化，不能一次消耗完所有需要的锻造石连续强化若干级。

提示：由于数据范围不大，因此你可以用遍历的方法寻找对应的武器，实际上相当多的褪色者确实是这么干的；而锻造石建议直接利用位置（数组下标）记录等级。

### 输出格式
输出内容即上述各类操作中的输出，一句话一行。

### 输入样例
```
13 1234
1
1 CrystalSword
2
1 ShortSord
1
0 ShortSord
0
0 1 12
2
4 ShortSord
2
2 ShortSord
0
0 2 7
2
5 ShortSord
2
4 ShortSord
0
1 1 2
0
1 2 1
0
1 3 1
2
2 CrystalSword
```
注：为了便于你 debug，输入样例即为第一个数据点。

输出样例
```
[magic=1234] Weapon created: CrystalSword
Somber weapon CrystalSword was created.
You don't have the right!
[magic=1234] Weapon created: ShortSord
Normal weapon ShortSord was created.
[magic=1234] Smithing stone 1 was created
Normal smithing stone 1 was created.
[magic=1234] Smithing stone 1 from 0 to 12
Normal smithing stone 1 was added with 12.
Upgrade failed for lacking normal smithing stone 2.
[magic=1234] Smithing stone 1 from 12 to 10
Normal smithing stone 1 was substracted with 2.
[magic=1234] Weapon upgraded: ShortSord
Normal weapon ShortSord was upgraded to ShortSord+1.
[magic=1234] Smithing stone 1 from 10 to 6
Normal smithing stone 1 was substracted with 4.
[magic=1234] Weapon upgraded: ShortSord
Normal weapon ShortSord+1 was upgraded to ShortSord+2.
Upgrade ShortSord to ShortSord+2 Successfully.
[magic=1234] Smithing stone 2 was created
Normal smithing stone 2 was created.
[magic=1234] Smithing stone 2 from 0 to 7
Normal smithing stone 2 was added with 7.
[magic=1234] Smithing stone 1 from 6 to 0
Normal smithing stone 1 was substracted with 6.
Normal smithing stone 1 was destroyed.
[magic=1234] Smithing stone 1(0) was destroyed
[magic=1234] Weapon upgraded: ShortSord
Normal weapon ShortSord+2 was upgraded to ShortSord+3.
[magic=1234] Smithing stone 2 from 7 to 5
Normal smithing stone 2 was substracted with 2.
[magic=1234] Weapon upgraded: ShortSord
Normal weapon ShortSord+3 was upgraded to ShortSord+4.
[magic=1234] Smithing stone 2 from 5 to 1
Normal smithing stone 2 was substracted with 4.
[magic=1234] Weapon upgraded: ShortSord
Normal weapon ShortSord+4 was upgraded to ShortSord+5.
Upgrade ShortSord+2 to ShortSord+5 Successfully.
Stay calm!
[magic=1234] Smithing stone 1 was created
Somber smithing stone 1 was created.
[magic=1234] Smithing stone 1 from 0 to 2
Somber smithing stone 1 was added with 2.
[magic=1234] Smithing stone 2 was created
Somber smithing stone 2 was created.
[magic=1234] Smithing stone 2 from 0 to 1
Somber smithing stone 2 was added with 1.
[magic=1234] Smithing stone 3 was created
Somber smithing stone 3 was created.
[magic=1234] Smithing stone 3 from 0 to 1
Somber smithing stone 3 was added with 1.
[magic=1234] Smithing stone 1 from 2 to 1
Somber smithing stone 1 was substracted with 1.
[magic=1234] Weapon upgraded: CrystalSword
Somber weapon CrystalSword was upgraded to CrystalSword+1.
[magic=1234] Smithing stone 2 from 1 to 0
Somber smithing stone 2 was substracted with 1.
Somber smithing stone 2 was destroyed.
[magic=1234] Smithing stone 2(0) was destroyed
[magic=1234] Weapon upgraded: CrystalSword
Somber weapon CrystalSword+1 was upgraded to CrystalSword+2.
Upgrade CrystalSword to CrystalSword+2 Successfully.
Normal smithing stone 2 was destroyed.
[magic=1234] Smithing stone 2(1) was destroyed
Somber smithing stone 1 was destroyed.
[magic=1234] Smithing stone 1(1) was destroyed
Somber smithing stone 3 was destroyed.
[magic=1234] Smithing stone 3(1) was destroyed
Normal weapon ShortSord+5 was destroyed.
[magic=1234] Weapon destroyed: ShortSord
Somber weapon CrystalSword+2 was destroyed.
[magic=1234] Weapon destroyed: CrystalSword
```
注：为便于区分，所有框架自带的输出都有 [magic=xxxx] 的前缀且末尾没有标点符号，你需要完成的输出则没有前缀且末尾有标点符号。

### 样例解释
样例的操作及结果如下：

1. 获得失色武器 CrystalSword ：操作成功
2. 将武器 ShortSord 升级到+1 ：操作失败；无该武器
3. 获得普通武器 ShortSord ：操作成功
4. 获得普通锻造石1(12) ：操作成功；物品栏新建普通锻造石1；普通锻造石1数量由0变为12
5. 将武器 ShortSord 升级到+4 ：操作失败；需要普通锻造石1(12)与普通锻造石2(2)；缺少普通锻造石2
6. 将武器 ShortSord 升级到+2 ：操作成功；需要普通锻造石1(6)；普通锻造石1数量由12变为6；ShortSord 升级为 ShortSord+2
7. 获得普通锻造石2(7) ：操作成功；物品栏新建普通锻造石2；普通锻造石2数量由0变为7
8. 将武器 ShortSord 升级到+5 ：操作成功；需要普通锻造石1(6)，普通锻造石2(6)；普通锻造石1数量由6变为0，物品栏销毁普通锻造石1，普通锻造石2数量由7变为1；ShortSord+2 升级为 ShortSord+5
9. 将武器 ShortSord 升级到+4 ：操作失败；无法降级锻造
10. 获得失色锻造石1(2) ：操作成功；物品栏新建失色锻造石1；失色锻造石1数量由0变为2
11. 获得失色锻造石2(1) ：操作成功；物品栏新建失色锻造石2；失色锻造石1数量由0变为1
12. 获得失色锻造石3(1) ：操作成功；物品栏新建失色锻造石3；失色锻造石3数量由0变为1
13. 将武器 CrystalSword 升级到+2：操作成功；需要失色锻造石1(1)，失色锻造石2(1)；失色锻造石1数量由2变为1，失色锻造石2数量由1变为0，物品栏销毁失色锻造石2；CrystalSword 升级为 CrystalSword+2
最终按顺序销毁物品栏：

1. 普通锻造石2(1)
2. 失色锻造石1(1)，失色锻造石3(1)
3. 普通武器 ShortSord
4. 失色武器 CrystalSword
### 要求
1. main.cpp、tarnished.h、weapon.cpp\/h、smithing_stone.cpp\/h 已经被预置，你不应也不能修改这些文件，你打包时是否包含它们不会产生任何影响，提交后 OJ 会自动将这些文件放入你的目录并编译
2. 在已有代码的基础上编写 NormalWeapon、SomberWeapon、NormalSmithingStone、SomberSmithingStone、Tarnished 类，请合理设计几个类的组合与继承关系
3. 你需要提交Makefile，且生成的可执行文件名为 main
### 限制与约定
* 1≤n≤1000
* 0≤type≤1
* 1≤name.length≤50
* 1≤number≤100
* 1≤level≤8
* 对普通武器 1≤target≤241≤target≤24，对失色武器 1≤target≤8
