#include <iostream>
#include "tarnished.h"
using namespace std;

int main()
{
    Tarnished *you = new Tarnished();
    int n, operation, type, target, level, number;
    int magic;
    string name;
    cin >> n >> magic;
    // set global magic number
    Weapon::set_magic(magic);
    SmithingStone::set_magic(magic);
    // operate
    while (n--)
    {
        cin >> operation;
        if (operation == 0)
        {
            cin >> type >> level >> number;
            you->pick_up_stone(type, level, number);
        }
        else if (operation == 1)
        {
            cin >> type >> name;
            you->pick_up_weapon(type, name);
        }
        else if (operation == 2)
        {
            cin >> target >> name;
            you->upgrade_weapon(target, name);
        }
    }
    delete you;
    return 0;
}
