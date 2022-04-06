#include "Vector.h"

Vector::Vector(int n):capacity(n),len(0),array(new Node[n]){
}

Vector::~Vector(){
    if(array)delete[] array;
}

Vector::Vector(const Vector & other):capacity(other.capacity),len(other.len),array(new Node[capacity]){
    for(int i=0;i<len;i++)
        array[i]=other.array[i];
}

Vector::Vector(Vector && other):capacity(other.capacity),len(other.len),array(other.array){
    other.capacity=0;
    other.len=0;
    other.array=nullptr;
}

Vector & Vector::operator=(const Vector & other){
    if(this!=&other){
        len=other.len;
        capacity=other.capacity;
        if(array)
            delete[] array;
        array = new Node[capacity];
        for(int i=0;i<len;i++){
            array[i]=other.array[i];
        }
    }
    return *this;
}

Vector & Vector::operator=(Vector && other){
    if(this!=&other){
      len =other.len;
      other.len=0;
      capacity=other.capacity;
      other.capacity=0;
      if(array)
      delete[] array;
      array=other.array;
      other.array=nullptr;  
    }
    return *this;
}

Node& Vector::operator [] (int pos){
    return array[pos];
}

void Vector::append(int value){
    array[len] = Node(value);
    len++;
}

void Vector::insert(int pos, int value){
    for(int i=len;i>pos;i--){
        array[i]=std::move(array[i-1]);
    }
    array[pos]=Node(value);
    len++;
}

void Vector::swap(int pos1, int pos2){
    Node tmp=std::move(array[pos1]);
    array[pos1]=std::move(array[pos2]);
    array[pos2]=std::move(tmp);
}

void Vector::dilatation(){
    Vector a(2*capacity);
    for(int i=0;i<len;i++)
        a.array[i]=std::move(array[i]);
    delete [] array;
    capacity*=2;
    array=a.array;
    a.array=nullptr;
}

int Vector::getlen(){
    return len;
}
