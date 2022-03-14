#ifndef SERVER_H
#define SERVER_H
#include "Task.h"
#include<iostream>
class Server{
public:
    int* ME;
    int N; 
    Task* tasks[200];
    int num=0;
    Server(int N,int M){
        this->N = N ;
        ME = new int[N];
        for(int i=0;i<N;i++){
            ME[i]=M;
        }
    }
    
    void tick(){
        for(int i=1;i<=num;i++){
            if(tasks[i]->td){
                tasks[i]->td--;
                if(tasks[i]->td==0){
                    for(int j=0;j<tasks[i]->tn;j++){
                        ME[tasks[i]->Use[j]]+=tasks[i]->tm;
                    }
                }
            }
        }
    }

    bool submit_task(Task task){
        int us=0;
        for(int i=0;i<N;i++){
            if(ME[i]>=task.tm){
                task.Use[us]=i;
                us++;
                if(us==task.tn){
                    for(int j=0;j<us;j++){
                        ME[task.Use[j]]=ME[task.Use[j]]-task.tm;
                    }
                    num++;
                    tasks[num]=new Task(task);
                    return true;
                }
            }
        }
        return false;
    }

    bool cancel_task(char* s){
        for(int i=1;i<=num;i++){
            if(!strcmp(tasks[i]->ts,s)){
                if(tasks[i]->td!=0){
                    tasks[i]->td=0;
                    for(int j=0;j<tasks[i]->tn;j++){
                            ME[tasks[i]->Use[j]]+=tasks[i]->tm;
                    }
                    return true;
                }  
            }
        }
        return false;
    }
};

#endif