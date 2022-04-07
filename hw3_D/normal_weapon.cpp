#include "normal_weapon.h"
#include <iostream>
using namespace std;


int NormalWeapon::length=0;

void NormalWeapon::up(){
    upgrade();
    if(get_level()-1)
    cout<<"Normal weapon "<<get_name()<<"+"<<get_level()-1<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl;
    else
    cout<<"Normal weapon "<<get_name()<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl;
}

int NormalWeapon::get_curlevel(){
    return get_level();
}
bool NormalWeapon::isname(string name){
    return true?name==get_name():false;
}

int NormalWeapon::get_len(){
    return length;
}
void NormalWeapon::add_len(){
    length++;
}
NormalWeapon::NormalWeapon(string name):Weapon(name){
    cout<<"Normal weapon "<<name<<" was created."<<endl;
}

NormalWeapon::~NormalWeapon()
{
    if(get_level())
    cout<<"Normal weapon "<<get_name()<<'+'<<get_level()<<" was destroyed."<<endl;
    else
    cout<<"Normal weapon "<<get_name()<<" was destroyed."<<endl;
}

