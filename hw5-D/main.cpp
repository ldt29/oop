#include "dataloader.h"
#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;


string matrix_unicode(vector<vector<int>>& mat){
    // this is a function to check print batch data for answer checking
    string unicode = "[";
    for (auto row : mat){
        unicode += "[";
        for (auto elem : row){
            unicode += std::to_string(elem)+",";
        }
        unicode.erase(unicode.end()-1);
        unicode += "],";
    }
    unicode.erase(unicode.end()-1);
    unicode+="]";
    return unicode;
}

int main(){
    int N, NUM_EPOCH, BATCH_SIZE;
    cin >> N;

    Vocabulary V;
    DataLoader D;
    cin.get();

    for (int i=0; i<N; i++){
        string sentence;
        getline(cin, sentence);
        D.addData(V.insertSentReturnIds(sentence));
    }

    cin >> NUM_EPOCH;

    for (int i=0; i<NUM_EPOCH; i++){
        cin >> BATCH_SIZE;
        vector<int> random_order;
        for (int j=0;j<N;j++){
            int tmp;
            cin >> tmp;
            random_order.push_back(tmp);
        }
        D.setOrder(random_order);
        D.setBatchSize(BATCH_SIZE);
        //cout <<matrix_unicode(D.test())<<endl;
        for (auto batch : D){
            string str = matrix_unicode(batch);
            cout<< str <<endl;
        }
    }
    return 0;
}