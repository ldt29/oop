#pragma once
#include<iostream>
#include "smithing_stone.h"
using namespace std;

class NormalSmithingStone:public SmithingStone
{
private:
    
public:
    NormalSmithingStone(int level,int number);
    ~NormalSmithingStone();
    void change_amount(int number);
    bool greater_curnumber(int need);
};
