#pragma once

#include<string>
using namespace std;

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
    void addhp(int _hp);
    void addatk(int _atk);
    int gettot_hp();
};

class Squirtle:public Pokemon{
public:
    Squirtle(int hp,int atk,string name);
    void use_skill(int idx, Pokemon* target);
    void hurt(int dmg, Pokemon* from);
};

class Charizard:public Pokemon{
    int fire;
public:
    Charizard(int hp,int atk,string name);
    void use_skill(int idx, Pokemon* target);
    void hurt(int dmg, Pokemon* from);
};