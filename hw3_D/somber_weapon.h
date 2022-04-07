#pragma once
#include<iostream>
#include "weapon.h"
using namespace std;

class SomberWeapon : public Weapon
{
private:
    static int length;
public:
    ~SomberWeapon();
    SomberWeapon(string name);
    static int get_len();
    static void add_len();
    bool isname(string name);
    int get_curlevel();
    void up();
};
