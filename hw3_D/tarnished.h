#pragma once
#include "normal_smithing_stone.h"
#include "normal_weapon.h"
#include "somber_smithing_stone.h"
#include "somber_weapon.h"

#define MAX_STONES 50
#define MAX_WEAPONS 1000

class Tarnished
{
private:
    NormalWeapon *normal_weapons[MAX_WEAPONS];
    SomberWeapon *somber_weapons[MAX_WEAPONS];
    NormalSmithingStone *normal_smithing_stones[MAX_STONES];
    SomberSmithingStone *somber_smithing_stones[MAX_STONES];

public:
    Tarnished();
    ~Tarnished();
    void pick_up_stone(int type, int level, int number);
    void pick_up_weapon(int type, string name);
    void upgrade_weapon(int target, string name);
};
