#include "smithing_stone.h"
#include <iostream>
using namespace std;

int SmithingStone::magic = 0;

void SmithingStone::print_magic()
{
    cout << "[magic=" << magic << "] ";
}

SmithingStone::~SmithingStone()
{
    print_magic();
    cout << "Smithing stone " << level << "(" << number << ") was destroyed" << endl;
}

SmithingStone::SmithingStone(int level) : level(level), number(0)
{
    print_magic();
    cout << "Smithing stone " << level << " was created" << endl;
}

void SmithingStone::set_magic(int _magic)
{
    magic = _magic;
}
void SmithingStone::add_amount(int amount)
{
    print_magic();
    cout << "Smithing stone " << level << " from " << number << " to " << number + amount << endl;
    number += amount;
}

bool SmithingStone::greater_equal(int need) const
{
    return number >= need;
}

int SmithingStone::get_level() const
{
    return level;
}
