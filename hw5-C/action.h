#pragma once
#include "animal.h"
#include <vector>

void action(Animal* animal, std::vector<Dog> & dogzone, std::vector<Bird> & birdzone){
    if(dynamic_cast<Dog* >(animal)==nullptr){
        Bird* bird = dynamic_cast<Bird* >(animal);
        birdzone.push_back(std::move(*bird));
    }else{
        Dog* dog = dynamic_cast<Dog* >(animal);
        dogzone.push_back(std::move(*dog));
    }
    return;
}