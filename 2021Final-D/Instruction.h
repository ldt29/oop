#pragma once
#include <vector>
#include <iostream>

class Instruction
{
public:
    virtual void apply(std::vector<int> &vec) = 0;
    virtual void apply(std::vector<double> &vec) = 0;
    virtual void output() = 0;
    
};

class iInstruction:public Instruction
{
public:
    int iforarr; 
    int num; 
    iInstruction(int i,int _num):iforarr(i),num(_num){};
    void apply(std::vector<int> &vec){
        vec[iforarr]+=num;
    };
    void apply(std::vector<double> &vec){
        vec[iforarr]+=num;
    }
    void output(){
        std::cout<<"arr"<<"["<<iforarr<<"] "<<"+= "<< num <<std::endl;
    }
    
};

class eInstruction:public Instruction
{
public:
    int iforarr; 
    int iforarr2; 
    eInstruction(int i,int _num):iforarr(i),iforarr2(_num){};
    void apply(std::vector<int> &vec){
        vec[iforarr]=vec[iforarr2];
    };
    void apply(std::vector<double> &vec){
        vec[iforarr]=vec[iforarr2];
    }
    void output(){
        std::cout<<"arr["<<iforarr<<"] "<<"= "<<"arr["<< iforarr2<< "]" <<std::endl;
    }
    
};

class aInstruction:public Instruction
{
public:
    int iforarr; 
    int iforarr2; 
    aInstruction(int i,int _num):iforarr(i),iforarr2(_num){};
    void apply(std::vector<int> &vec){
        vec[iforarr]+=vec[iforarr2];
    };
    void apply(std::vector<double> &vec){
        vec[iforarr]+=vec[iforarr2];
    }
    void output(){
        std::cout<<"arr["<<iforarr<<"] "<<"+= "<<"arr["<< iforarr2<< "]" <<std::endl;
    }
    
};

class cInstruction:public Instruction
{
public:
    int iforarr; 
    
    cInstruction(int i):iforarr(i){};
    void apply(std::vector<int> &vec){
        std::cout<< vec[iforarr];
    };
    void apply(std::vector<double> &vec){
         std::cout<< vec[iforarr];
    }
    void output(){
        std::cout<<"cout << "<<"arr["<<iforarr<<"]" <<std::endl;
    }
    
};

class lInstruction:public Instruction
{
public:    
    lInstruction(){};
    void apply(std::vector<int> &vec){
        std::cout<< std::endl;
    };
    void apply(std::vector<double> &vec){
        std::cout<< std::endl;
    }
    void output(){
        std::cout<<"cout << endl"<<std::endl;
    }
    
};