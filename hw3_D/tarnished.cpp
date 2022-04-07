#include "tarnished.h"
#include <iostream>
using namespace std;

Tarnished::Tarnished(){
 for (int i = 0; i < MAX_WEAPONS; i++) {
        normal_weapons[i] = nullptr;
        somber_weapons[i] = nullptr;
    }
    for (int i = 0; i < MAX_STONES; i++)
    {
        normal_smithing_stones[i] = nullptr;
        somber_smithing_stones[i] = nullptr;
    }
}

Tarnished::~Tarnished(){
    for(int i=0;i<MAX_STONES;i++){
        if(normal_smithing_stones[i]){
            delete normal_smithing_stones[i];
        }
    }
    for(int i=0;i<MAX_STONES;i++){
        if(somber_smithing_stones[i]){
            delete somber_smithing_stones[i];
        }
    }
    for (int i = 0; i < NormalWeapon::get_len(); i++)
    {
        delete normal_weapons[i];
    }
    for (int i = 0; i < SomberWeapon::get_len(); i++)
    {
        delete somber_weapons[i];
    }
    
}

void Tarnished::pick_up_stone(int type, int level, int number){
    if(type){
        if(somber_smithing_stones[level])
            somber_smithing_stones[level]->change_amount(number);
        else
            somber_smithing_stones[level]=new SomberSmithingStone(level,number);
    }else{
        if(normal_smithing_stones[level])
            normal_smithing_stones[level]->change_amount(number);
        else
            normal_smithing_stones[level]=new NormalSmithingStone(level,number);
    }
}

void Tarnished::pick_up_weapon(int type, string name){
    if(type){
        somber_weapons[SomberWeapon::get_len()]=new SomberWeapon(name);
        SomberWeapon::add_len();
    }else{
        normal_weapons[NormalWeapon::get_len()]=new NormalWeapon(name);
        NormalWeapon::add_len();
    }
}

void Tarnished::upgrade_weapon(int target, string name){
    for(int i=0;i<NormalWeapon::get_len();i++){
        if(normal_weapons[i]->isname(name)){
            if(normal_weapons[i]->get_curlevel()>=target){
                cout<<"Stay calm!"<<endl;
                return;
            }
            int need=0;
            int type=0;
            int flag=normal_weapons[i]->get_curlevel();
            for(int j=flag;j<target;j++){
                type=j/3+1;
                if(!(j%3)) need=0;
                need+=j%3*2+2;
                if(!normal_smithing_stones[type]){
                    cout<<"Upgrade failed for lacking normal smithing stone "<<type<<"."<<endl;
                    return;
                }
                if(!normal_smithing_stones[type]->greater_curnumber(need)){
                    cout<<"Upgrade failed for lacking normal smithing stone "<<type<<"."<<endl;
                    return;
                }
            }
            for(int j=flag;j<target;j++){
                type=j/3+1;
                need=j%3*2+2;
                normal_smithing_stones[type]->change_amount(-need);
                if(!normal_smithing_stones[type]->greater_curnumber(1)){
                    delete normal_smithing_stones[type];
                    normal_smithing_stones[type]=nullptr;
                }
                normal_weapons[i]->up();
            }
            if(flag)
            cout<<"Upgrade "<<name<<"+"<<flag<<" to "<<name<<"+"<<target<<" Successfully."<<endl;
            else
            cout<<"Upgrade "<<name<<" to "<<name<<"+"<<target<<" Successfully."<<endl;
            return;
        }
    }
    for (int i = 0; i < SomberWeapon::get_len(); i++)
    {
        if(somber_weapons[i]->isname(name)){
            if(somber_weapons[i]->get_curlevel()>=target){
                cout<<"Stay calm!"<<endl;
                return;
            }
            int need=0;
            int type=0;
            int flag=somber_weapons[i]->get_curlevel();
            for(int j=flag;j<target;j++){
                type=j+1;
                if(!somber_smithing_stones[type]){
                    cout<<"Upgrade failed for lacking somber smithing stone "<<type<<"."<<endl;
                    return;
                }
                if(!somber_smithing_stones[type]->greater_curnumber(1)){
                    cout<<"Upgrade failed for lacking somber smithing stone "<<type<<"."<<endl;
                    return;
                }
            }
            for(int j=flag;j<target;j++){
                type=j+1;
                somber_smithing_stones[type]->change_amount(-1);
                if(!somber_smithing_stones[type]->greater_curnumber(1)){
                    delete somber_smithing_stones[type];
                    somber_smithing_stones[type]=nullptr;
                }
                somber_weapons[i]->up();
            }
            if(flag)
            cout<<"Upgrade "<<name<<"+"<<flag<<" to "<<name<<"+"<<target<<" Successfully."<<endl;
            else
            cout<<"Upgrade "<<name<<" to "<<name<<"+"<<target<<" Successfully."<<endl;
            return;
        }
    }
    cout<<"You don't have the right!"<<endl;
}