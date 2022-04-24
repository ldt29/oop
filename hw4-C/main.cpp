#include "Pokemon.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    Pokemon *players[2];
    for(int i = 0; i < 2; ++i)
    {
        int type, hp, atk;
        cin >> type >> hp >> atk;
        if(type == 1)
            // 宝可梦的名字形如 S(1)、C(0)等，括号中数字i表示player[i]
            players[i] = new Squirtle(hp, atk, "S(" + string(1, '0' + i) + ")");
        if(type == 2)
            players[i] = new Charizard(hp, atk, "C(" + string(1, '0' + i) + ")");
    }
    int rounds;
    cin >> rounds;
    while(rounds--)
    {
        int skill, target;
        cin >> skill >> target;
        players[0]->use_skill(skill, players[target]);
        if(!players[0]->alive() || !players[1]->alive())
            break;
        cin >> skill >> target;
        players[1]->use_skill(skill, players[target]);
        if(!players[0]->alive() || !players[1]->alive())
            break;
    }
    cout << "-----game over-----" << endl;
    cout << players[0]->get_name() << " " << players[0]->get_hp() << " " << players[0]->get_atk() << endl;
    cout << players[1]->get_name() << " " << players[1]->get_hp() << " " << players[1]->get_atk() << endl;
    delete players[0];
    delete players[1];

    return 0;
}