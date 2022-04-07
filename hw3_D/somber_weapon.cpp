#include "somber_weapon.h"
#include <iostream>
using namespace std;


int SomberWeapon::length=0;

void SomberWeapon::up(){
    upgrade();
    if(get_level()-1)
    cout<<"Somber weapon "<<get_name()<<"+"<<get_level()-1<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl;
    else
    cout<<"Somber weapon "<<get_name()<<" was upgraded to "<<get_name()<<"+"<<get_level()<<"."<<endl;
}

int SomberWeapon::get_curlevel(){
    return get_level();
}

bool SomberWeapon::isname(string name){
    return true?name==get_name():false;
}

int SomberWeapon::get_len(){
    return length;
}
void SomberWeapon::add_len(){
    length++;
}

SomberWeapon::SomberWeapon(string name):Weapon(name){
    cout<<"Somber weapon "<<name<<" was created."<<endl;
}

SomberWeapon::~SomberWeapon()
{
    if(get_level())
    cout<<"Somber weapon "<<get_name()<<'+'<<get_level()<<" was destroyed."<<endl;
    else
    cout<<"Somber weapon "<<get_name()<<" was destroyed."<<endl;
}

