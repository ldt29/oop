#include "somber_smithing_stone.h"
#include <iostream>
using namespace std;


bool SomberSmithingStone::greater_curnumber(int need){
    return greater_equal(need);
}

void SomberSmithingStone::change_amount(int number){
    add_amount(number);
    if(number>0)
        cout<<"Somber smithing stone "<<get_level()<<" was added with "<<number<<"."<<endl;
    else
        cout<<"Somber smithing stone "<<get_level()<<" was substracted with "<<-number<<"."<<endl;
}

SomberSmithingStone::SomberSmithingStone(int level,int number):SmithingStone(level)
{
    cout<<"Somber smithing stone "<<level<<" was created."<<endl;
    change_amount(number);
}
SomberSmithingStone::~SomberSmithingStone()
{
    cout<<"Somber smithing stone "<<get_level()<<" was destroyed."<<endl;
}
