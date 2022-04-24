#include "Pokemon.h"
#include <iostream>


using namespace std;

Pokemon::Pokemon(int hp, int atk, string name):tot_hp(hp),hp(hp),atk(atk),name(name){}

Pokemon::Pokemon(){}

string Pokemon::get_name(){
    return name;
}

bool Pokemon::alive(){
    return hp>0;
}  

int Pokemon::get_hp(){
    return hp;
}

int Pokemon::get_atk(){
    return atk;
}

void Pokemon::addhp(int _hp){
    hp+=_hp;
    if(hp>tot_hp)
    hp=tot_hp;
}

int Pokemon::gettot_hp(){
    return tot_hp;
}

void Pokemon::addatk(int _atk){
    atk+=_atk;
}

Pokemon::~Pokemon(){}

void Pokemon::use_skill(int idx, Pokemon* target){}

void Pokemon::hurt(int dmg, Pokemon* from){}

Squirtle::Squirtle(int hp,int atk,string name):Pokemon(hp, atk, name){}

void Squirtle::use_skill(int idx, Pokemon* target){
    if(idx==0){
        cout<<get_name()<<" used Regen"<<endl;
        this->addhp(gettot_hp()/5);
    }
    if(idx==1){
        cout<<get_name()<<" used Splash to "<<target->get_name()<<endl;
        target->hurt(atk,this);
    }
}

void Squirtle::hurt(int dmg, Pokemon* from){
    if(get_hp()<=gettot_hp()/5) {
        addhp(-(dmg/2));
        cout<<get_name()<<" received "<<dmg/2<<" damage from "<<from->get_name()<<endl;
    }
    else {
        addhp(-dmg);
        cout<<get_name()<<" received "<<dmg<<" damage from "<<from->get_name()<<endl;
    }
}

Charizard::Charizard(int hp,int atk,string name):fire(1),Pokemon(hp, atk, name){}

void Charizard::use_skill(int idx, Pokemon* target){
    if(idx==0){
        fire++;
        cout<<get_name()<<" used Ignite"<<endl;
        addatk(get_atk());
        hurt(fire*10,this);
    }
    if(idx==1){
        cout<<get_name()<<" used Flame to "<<target->get_name()<<endl;
        target->hurt(atk,this);
    } 
}

void Charizard::hurt(int dmg, Pokemon* from){
    addhp(-dmg);
    cout<<get_name()<<" received "<<dmg<<" damage from "<<from->get_name()<<endl;
    if(dmg>10&&from!=this){
        from->hurt(dmg/5,this);
    }
}       