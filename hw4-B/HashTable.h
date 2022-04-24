#pragma once

#include <string>
#include <vector>
#include "Hash.h"
#include<vector>
using namespace std;

template <typename T1, typename T2>
class HashTable
{
private:
    int lenth;
    Hash<T1> hash;
    vector<T2*> Table;
public:
    HashTable(int _n):lenth(_n),hash(_n),Table(vector<T2*>(_n,nullptr)){}
    void addItem(const T1 &key, const T2 &value);
    void removeItem(const T1 &key);
    T2 *findByKey(const T1 &key);
    ~HashTable(){};
};

template<>
HashTable<int,int>::~HashTable(){
    for(auto c: Table){
        if(c!=nullptr)
            delete c;
    }
}

template<>
HashTable<int,string>::~HashTable(){
    for(auto c: Table){
        if(c!=nullptr)
            delete c;
    }
}

template<>
HashTable<string,int>::~HashTable(){
    for(auto c: Table){
        if(c!=nullptr)
            delete c;
    }
}

template<>
HashTable<string,string>::~HashTable(){
    for(auto c: Table){
        if(c!=nullptr)
            delete c;
    }
}

template<>
void HashTable<int,int>::addItem(const int &key, const int &value){
    Table[hash(key)]=new int(value);
}

template<>
void HashTable<int,string>::addItem(const int &key, const string &value){
    Table[hash(key)]=new string(value);
}

template<>
void HashTable<string,int>::addItem(const string &key, const int &value){
    Table[hash(key)]=new int(value);
}

template<>
void HashTable<string,string>::addItem(const string &key, const string &value){
    Table[hash(key)]=new string(value);
}

template<>
void HashTable<int,int>::removeItem(const int &key){
    delete Table[hash(key)];
    Table[hash(key)]=nullptr;
}

template<>
void HashTable<int,string>::removeItem(const int &key){
    delete Table[hash(key)];
    Table[hash(key)]=nullptr;
}

template<>
void HashTable<string,int>::removeItem(const string &key){
    delete Table[hash(key)];
    Table[hash(key)]=nullptr;
}

template<>
void HashTable<string,string>::removeItem(const string &key){
    delete Table[hash(key)];
    Table[hash(key)]=nullptr;
}

template<>
int* HashTable<int,int>::findByKey(const int &key){
    return Table[hash(key)];
}

template<>
string* HashTable<int,string>::findByKey(const int &key){
    return Table[hash(key)];
}

template<>
int* HashTable<string,int>::findByKey(const string &key){
    return Table[hash(key)];
}

template<>
string* HashTable<string,string>::findByKey(const string &key){
    return Table[hash(key)];
}