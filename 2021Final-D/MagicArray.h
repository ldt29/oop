#pragma once
#include <vector>
#include "Instruction.h"


class Magic{
public:
    
    int num;
    std::vector<Instruction*>* instructions; 
    Magic(int _num){
        num=_num;
    };
    Magic():num(0){};
    Magic& operator+=(const int& i){
        instructions->push_back(new iInstruction(num,i));
        return *this;
    };

    Magic& operator+=(const Magic& another){
        instructions->push_back(new aInstruction(num,another.num));
        return *this;
    };

    Magic& operator=(const Magic& another){
        instructions->push_back(new eInstruction(num,another.num));
        return *this;
    };
    friend std::ostream& operator<<(std::ostream& out,const Magic& another){
        if(another.num==-1)
        another.instructions->push_back(new lInstruction());
        else
        another.instructions->push_back(new cInstruction(another.num));
        return out;
    }
};

class MagicArray{
public:
    std::vector<Instruction*> instructions; 
    int length;
    std::vector<Magic> test;
    Magic end;
    MagicArray(int _length):instructions(std::vector<Instruction*>(0)),test(std::vector<Magic>(_length)),length(_length){
        end.num=-1;
        end.instructions=&instructions;
        for(int i=0;i<length;i++){
            test[i].num=i;
            test[i].instructions = &instructions;
        }
    };

    void apply(std::vector<int> &vec);
    void apply(std::vector<double> &vec);
    Magic& operator[](int i){
        return test[i];
    }
    std::vector<Instruction*>& getInstructions(){
        return instructions;
    };

    Magic& endl(){
        return end;
    }

};  

void MagicArray::apply(std::vector<int> &vec){
    for(auto ins : instructions) {
        ins -> apply(vec);
    }
}
void MagicArray::apply(std::vector<double> &vec){
     for(auto ins : instructions) {
        ins -> apply(vec);
    }
}