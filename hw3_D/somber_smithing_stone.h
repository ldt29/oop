#pragma once
#include<iostream>
#include "smithing_stone.h"
using namespace std;

class SomberSmithingStone:public SmithingStone
{
private:
    
public:
    SomberSmithingStone(int level,int number);
    ~SomberSmithingStone();
    void change_amount(int number);
    bool greater_curnumber(int need);
};
