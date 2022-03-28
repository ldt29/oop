#include "Map.h"
#include <string>
#include <iostream>
using namespace std;

Map::Map(int n){
    data = new Pair[n];
    sz=0;
}

int & Map::operator[](string name){
    for(int i=0;i<sz;i++){
        if(data[i].hasKey(name)){
            return data[i].getVal();
        }
    }
    data[sz].reset(name,0);
    return data[sz++].getVal();
}
const int Map::operator[](string name) const{
    for(int i=0;i<sz;i++){
        if(data[i].hasKey(name)){
            return data[i].getVal();
        }
    }
    return 0;
}

int Map::size(){
    return sz;
}

Map::~Map(){
    if(data) delete[] data;
}
