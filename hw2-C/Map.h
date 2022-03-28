#pragma once
#include "Pair.h"
#include <string>

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    // TODO
    int & operator [](string name);
    const int operator[](string name)const;
    int size();
    ~Map();
};
