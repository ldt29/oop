#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include<sstream>


using namespace std;



// Change this file as you want or add more files






class Vocabulary
{
private:
    // Choose a proper container from STL.
    int NUM;
    map<string, int> query;
public:
    Vocabulary() :NUM(1) {}
    vector<int> insertSentReturnIds(string sentence) {
        //Enter your code here.
        //This function should build vocabulary and at the same time return a sentence encoding.
        sentence += ' ';
        vector<int> ans;
        string word;
        for (auto c : sentence) {
            if (c == ' ') {
                if (!query[word]) {
                    query[word] = NUM;
                    NUM++;
                }
                ans.push_back(query[word]);
                word = "";

                continue;
            }
            word += c;
        }
        return ans;
    }
};


class DataLoader {
private:
    vector<int> _rand_order;
    int _rand_order_size;
    int batch_size = 0;
    vector<vector<vector<int> > > batchs;
    vector<vector<int> >data;
    //Enter your code here
public:

    void setBatch() {
        batchs.clear();
        int i = 0;
        while (i < _rand_order.size()) {
            vector<vector<int>> temp;
            int j = 0;
            int maxL = 0;
            while (j < batch_size && i < _rand_order.size()) {
                if (data[_rand_order[i]].size() > maxL)
                    maxL = data[_rand_order[i]].size();
                temp.push_back(data[_rand_order[i]]);
                i++;
                j++;
            }
            int cnt = 0;
            while (cnt < j) {
                while (temp[cnt].size() < maxL) {
                     temp[cnt].push_back(0);                   
                }
                cnt++;
            }

            batchs.push_back(temp);
        }
    }
    void setBatchSize(int N) {
        this->batch_size = N; // can also change
        setBatch();
    }

    void setOrder(vector<int>& x) {
        _rand_order = x; // can also change
        _rand_order_size=x.size();
    }

    void addData(vector<int> sent_encoding) {
        data.push_back(sent_encoding);
        //Enter you code here;
    }
    vector<vector<int> >& test() {
        return batchs[0];
    }
    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = std::vector<vector<int> >;
        using reference = std::vector<vector<int> >&;
        using pointer = std::vector<vector<int> >*;
        // Add more using statement here
        // hint: using value_type = ?
        //       using reference = ?

        //Define your constructor and functions that are needed for a Iterator.
        Iterator(DataLoader* ptr, int n) {
            pos = n;
            obj = ptr;
        }
        Iterator() {
            pos = 0;
            obj = nullptr;
        }

        void operator++() {
            pos++;
        }

        void operator++(int) {
            pos++;
        }
        void operator--() {
            pos--;
        }
        vector<vector<int> > operator*() const{
            return obj->batchs[pos];
        }
        bool operator!=(const Iterator& it) {
            return it.pos != pos;
        }
        bool operator==(const Iterator& it) {
            return it.pos == pos;
        }
        void operator--(int) {
            pos--;
        }

    private:
        // Add what where variable you want here to make the Iterator functional.
        int pos;
        DataLoader* obj;
    };

    Iterator begin() {
        //Enter your code here.
        return Iterator(this, 0);
    }
    Iterator end() {
        //Enter your code here.
        return Iterator(this, batchs.size());
    }

};






