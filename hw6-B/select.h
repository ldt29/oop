#pragma once
#include<vector>

using namespace std;

vector<int> select(vector<int> credit, int l, int r, Student* student){
    vector<int> result;
    for(int i=l-1;i<r;i++){
        if(student->check(credit[i],i+1))
            result.push_back(i+1);
    }
    return result;
}
