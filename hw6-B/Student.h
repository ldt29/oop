#pragma once

#include<iostream>

class Student{
public:
    virtual bool check(int credit,int num){}
};

class StudentTypeA : public Student{
public:
    bool check(int credit,int num){
        if(credit<=2) return true;
        return false;
    }
};

class StudentTypeB : public Student{
public:
    bool isprime(int x){
        if(x==1) return false;
        for(int i=2;i<x;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    bool check(int credit,int num){
        if(isprime(num))return true;
        return false;
    }
};

class StudentTypeC : public Student{
public:
    bool check(int credit,int num){
        if(num%credit==0) return true;
        return false;
    }
};