#pragma once
#include<iostream>
#include<string>
#include"Animal.h"

using namespace std;
class Bird: public Animal
{
private:
    /* data */
public:
    int color;
    void sing(){
         if(color==1)
        cout<<"Blue bird is singing."<<endl;
        else
        cout<<"Red bird is singing."<<endl;
    }
    void swim(){
        cout<<"Bird can not swim."<<endl;
    }
    Bird(int _color/* args */):color(_color){};
    ~Bird();
};



Bird::~Bird()
{
    if(color==1)
        cout<<"Blue bird is gone."<<endl;
        else
        cout<<"Red bird is gone."<<endl;
}
