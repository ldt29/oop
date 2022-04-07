#include "normal_smithing_stone.h"
#include <iostream>
using namespace std;

bool NormalSmithingStone::greater_curnumber(int need){
    return greater_equal(need);
}

void NormalSmithingStone::change_amount(int number){
    add_amount(number);
    if(number>0)
        cout<<"Normal smithing stone "<<get_level()<<" was added with "<<number<<"."<<endl;
    else
        cout<<"Normal smithing stone "<<get_level()<<" was substracted with "<<-number<<"."<<endl;
}

NormalSmithingStone::NormalSmithingStone(int level,int number):SmithingStone(level)
{
    cout<<"Normal smithing stone "<<level<<" was created."<<endl;
    change_amount(number);
}
NormalSmithingStone::~NormalSmithingStone()
{
    cout<< "Normal smithing stone "<<get_level()<<" was destroyed."<<endl;
}
