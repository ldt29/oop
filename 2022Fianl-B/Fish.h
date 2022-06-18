#pragma once
#include<iostream>
#include<string>
#include"Animal.h"

using namespace std;
class Fish: public Animal
{
private:
    /* data */
public:
    int color;
    void sing(){
        cout<<"Fish can not sing."<<endl;
    }
    void swim(){
        if(color==1)
        cout<<"Blue fish is swimming."<<endl;
        else
        cout<<"Red fish is swimming."<<endl;
    }
    Fish(int _color/* args */):color(_color){};
    ~Fish();
};

Fish::~Fish()
{
    if(color==1)
        cout<<"Blue fish is gone."<<endl;
        else
        cout<<"Red fish is gone."<<endl;
}
