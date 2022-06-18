#pragma once
#include<iostream>
#include<string>

using namespace std;

class Animal
{
private:
    /* data */
public:
    virtual void sing()=0;
    virtual void swim()=0;
    Animal(){};
    virtual ~Animal(){};
};


