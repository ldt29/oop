## 题目描述
小明想要利用类的继承来实现不同种类的宝可梦之间的对战，他已经定好了主游戏流程以及宝可梦的基类，想请你实现两个最基本的宝可梦：杰尼龟（Squirtle）和喷火龙（Charizard）

### 游戏流程
控制游戏流程的代码已经在main.cpp中写好，主要包含如下环节：

1. 对战双方初始化：输入宝可梦的类别type(1时为杰尼龟，2时为喷火龙)、生命值hp、攻击力atk
2. 输入最大对战轮数rounds，若经过rounds轮后双方宝可梦均存活，则自动结束游戏
3. 每回合由player[0]先开始操作，输入skill和target决定使用的技能和目标，再由player[1]进行同样的操作
4. 当某方的宝可梦死亡，或对战回合数达到rounds时，结束游戏，输出双方宝可梦当前的生命值与攻击力
```
#include "Pokemon.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    Pokemon *players[2];
    for(int i = 0; i < 2; ++i)
    {
        int type, hp, atk;
        cin >> type >> hp >> atk;
        if(type == 1)
            // 宝可梦的名字形如 S(1)、C(0)等，括号中数字i表示player[i]
            players[i] = new Squirtle(hp, atk, "S(" + string(1, '0' + i) + ")");
        if(type == 2)
            players[i] = new Charizard(hp, atk, "C(" + string(1, '0' + i) + ")");
    }
    int rounds;
    cin >> rounds;
    while(rounds--)
    {
        int skill, target;
        cin >> skill >> target;
        players[0]->use_skill(skill, players[target]);
        if(!players[0]->alive() || !players[1]->alive())
            break;
        cin >> skill >> target;
        players[1]->use_skill(skill, players[target]);
        if(!players[0]->alive() || !players[1]->alive())
            break;
    }
    cout << "-----game over-----" << endl;
    cout << players[0]->get_name() << " " << players[0]->get_hp() << " " << players[0]->get_atk() << endl;
    cout << players[1]->get_name() << " " << players[1]->get_hp() << " " << players[1]->get_atk() << endl;
    delete players[0];
    delete players[1];

    return 0;
}
```
### 基类Pokemon说明
```
class Pokemon
{
protected:
    int tot_hp, hp, atk;
    string name;
public:
    Pokemon(int hp, int atk, string name);
    Pokemon();
    virtual void use_skill(int idx, Pokemon* target);// 对目标target使用idx号技能
    virtual void hurt(int dmg, Pokemon* from);// 受到来自from的dmg点伤害时的反应
    string get_name();    // 获取宝可梦名字
    bool alive();     // 宝可梦是否存活
    int get_hp();     // 获取生命值
    int get_atk();  // 获取攻击力
    ~Pokemon();
};
```
所有宝可梦的技能都通过use_skill函数调用，如果该技能不要求目标，则调用时向target传入任意指针，不影响执行结果。

### 杰尼龟Squirtle
有两项技能，分别是：

0：回血（Regen）：恢复自身最大生命值的1/5（向下取整），生命值最大不超过原来的生命值。无target

1：喷射（Splash）：对目标宝可梦造成自身攻击力atk点伤害

杰尼龟受到伤害时，如果当前生命值小于等于最大生命值的1/5（向下取整），则受到的伤害减半（向下取整，不小于1）

### 喷火龙Charizard
喷火龙有一个额外属性fire（初始为1）以及两项技能：

0：点燃（Ignite）：fire属性+= 1，自身攻击力×2。fire属性改变之后，自身生命值减少fire * 10。无target

1：喷火（Flame）：对目标宝可梦造成自身攻击力atk点伤害

喷火龙受到（非自己造成的）大于10的伤害时，对来源造成所受伤害dmg * 1/5（向下取整，不小于1）的伤害。

### 输出要求：
* 在每次使用技能时，需要按如下格式输出一行信息：
[pokemon_name] used [Skillname] (to [target_name])

例：S(0) used Splash to C(1), C(1) used Ignite

* 宝可梦收到伤害后，需要按如下格式输出一行信息：
[pokemon_name] received [final_damage] damage from [from_name]

例：Charizard(1) received 100 damage from Squirtle(0)

### 输入样例
```
1 120 30 
2 160 40
10
0 0
0 1
1 1
0 1
1 1
1 0
```
样例解释：
```
1 120 30 // player[0]选择宝可梦1（杰尼龟） 生命值120 攻击力 30
2 160 40 // player[1]选择宝可梦2（喷火龙） 生命值160 攻击力 40
10    // 最大回合数
0 0     // 杰尼龟使用0号技能回血，后面的目标0无意义
0 1    // 喷火龙使用0号技能点燃，后面的目标1无意义
1 1    // 0号杰尼龟对1号喷火龙使用喷射
0 1    // 喷火龙继续点燃
1 1    // 继续喷射
1 0    // 1号喷火龙对0号杰尼龟使用喷火
```
### 输出样例
```
S(0) used Regen
C(1) used Ignite
C(1) received 20 damage from C(1)
S(0) used Splash to C(1)
C(1) received 30 damage from S(0)
S(0) received 6 damage from C(1)
C(1) used Ignite
C(1) received 30 damage from C(1)
S(0) used Splash to C(1)
C(1) received 30 damage from S(0)
S(0) received 6 damage from C(1)
C(1) used Flame to S(0)
S(0) received 160 damage from C(1)
-----game over-----
S(0) -52 30
C(1) 50 160
```
### 提交要求
* 你需要提交Pokemon.cpp, Pokemon.h。评测时OJ将会把题目提供的main.cpp和你提交的文件一同编译。

* 编译命令g++ -o main main.cpp Pokemon.cpp --std=c++11

### 评分标准
OJ自动评测占100%。

