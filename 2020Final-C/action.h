#pragma once
#include "animal.h"
#include<vector>
using namespace std;

void action(Animal* buffer,vector<Dog>& dogzone,  vector<Bird>& birdzone){
    Dog* dog;
    if(dog= dynamic_cast<Dog*>(buffer)){
        dogzone.push_back(move(*dog));
    }else{
        Bird* bird=dynamic_cast<Bird*>(buffer);
        birdzone.push_back(move(*bird));
    }
    return;
}