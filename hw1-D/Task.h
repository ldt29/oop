#ifndef Task_H
#define Task_H

#include<string.h>
class Task{
public:
    char ts[30];
    int d,td,tn,tm;
    int* Use;
    Task(char* s,int d,int n,int m){
        strcpy(ts,s);
        td = d;
        tn = n;
        tm = m;
        Use = new int[n];
    }
};

#endif