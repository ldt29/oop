#pragma once

class Vehicle{
public:
    int max_wheel_num;
    int max_wing_num; 
    int wheel_num;
    int wing_num;
    Vehicle(){
        max_wheel_num=0;
        max_wing_num=0; 
        wheel_num=0;
        wing_num=0;
    }
    void set_max_wheel_num(int num){
        max_wheel_num=num;
    };
    void set_max_wing_num(int num){
        max_wing_num=num;
    };
    bool finished(){
        if(wheel_num==max_wheel_num&&wing_num==max_wing_num){
            return true;
        }
        return false;
    }
    void add_wing(){
        wing_num++;
    }
    void add_wheel(){
        wheel_num++;
    }
    void run(){
        std::cout << "I am running" << std::endl;
    }
};