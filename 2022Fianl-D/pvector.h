#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template<class T>
class Data
{
protected:
    int length;
public:
    vector<T> datas;
    Data(int _length) : length(_length), datas(vector<T>(_length)) {}
    Data(const Data& _data) {
        length = _data.length;
        datas = _data.datas;
    }
    virtual const T& get(int index) = 0;
};

template<class T>
class DataEmpty : public Data<T>
{
public:
    DataEmpty<T>() : Data<T>(0) {};
    const T& get(int index) {
        assert(0); // No data in DataEmpty
    }
};

template<class T>
class DataPushBackDecorator : public Data<T>
{
public:
    T value;
    DataPushBackDecorator(Data<T>* _data, T _value) :Data<T>(*_data) {
        value = _value;
        this->datas.push_back(value);
    }
    const T& get(int index) {
        return this->datas[index];
    }
    // Implement a Decorator for push_back operation
};

template<class T>
class DataPopBackDecorator : public Data<T>
{
public:
    T value;
    DataPopBackDecorator(Data<T>* _data) :Data<T>(*_data) {
        this->datas.pop_back();
    }
    const T& get(int index) {
        return this->datas[index];
    }
    // Implement a Decorator for push_back operation
};


template<class T>
class DataSetDecorator : public Data<T>
{
public:
    T value;
    T value1;
    int index;
    DataSetDecorator(Data<T>* _data, int _index, T _value) :Data<T>(*_data) {
        index = _index;
        value = _value;
        value1 = this->datas[index];
        this->datas[index] = value;
    }
    const T& get(int index) {
        return this->datas[index];
    }
    // Implement a Decorator for set operation
};


template<class T>
class PVector
{
public:
    Data<T>* data;
    PVector<T>() {
        data = new DataEmpty<T>();
        // when to delete??
    }
 
    PVector<T>(Data<T>* _data) : data(_data) { }
    PVector<T> push_back(const T& value) const {
        return PVector<T>(new DataPushBackDecorator<T>(data, value));
    }
    PVector<T> set(int index, const T& value) const {
        return PVector<T>(new DataSetDecorator<T>(data, index, value));
    }

    const T& operator[](int index) {
        return data->get(index);
    }


    friend ostream& operator<<(ostream& out, PVector x) {
        out << "[";
        if (x.data->datas.size()) {
            cout << x.data->datas[0];
        }
        for (int i = 1; i < x.data->datas.size(); i++) {
            cout <<", " << x.data->datas[i];
        }
        out << "]" ;
        return out;
    }
    PVector<T> undo() {
        if (dynamic_cast<DataSetDecorator<T>*>(this->data) != nullptr) {
            DataSetDecorator<T>* temp = dynamic_cast<DataSetDecorator<T>*>(this->data);
            return PVector<T>(new DataSetDecorator<T>(data, temp->index, temp->value1));
        }
        else if(dynamic_cast<DataPushBackDecorator<T>*>(this->data) != nullptr){
            DataPushBackDecorator<T>* temp = dynamic_cast<DataPushBackDecorator<T>*>(this->data);
            return PVector<T>(new DataPopBackDecorator<T>(data));
        }
        else {
            cout << "cannot undo" << endl;
        }
    }
   
};
