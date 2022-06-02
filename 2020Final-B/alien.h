#pragma once
#include "what.h"

class Alien:public WhatCanMotion,public WhatCanSpeak
{
private:
    string name;
public:
    Alien(string _name);
    void speak();
    void motion();
    void stop();
    ~Alien();
};

Alien::Alien(string _name):name(_name)
{

}

Alien::~Alien()
{
}

void Alien::speak(){
    cout<<name<<" is speaking"<<endl;
}

void Alien::motion(){
    cout<<name<<" is moving"<<endl;
}

void Alien::stop(){
    cout<<name<<" stops"<<endl;
}