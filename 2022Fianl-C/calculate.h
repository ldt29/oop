#pragma once
#include<iostream>
#include<string>
#include"Fraction.h"

using namespace std;

template<class T>
class calculate {
public:
    char expressionType;
    T x, y, z;
    calculate(char _expressionType, T _x, T _y, T _z) {
        expressionType = _expressionType;
        x = _x;
        y = _y;
        z = _z;
    }
    T ans;
    void cal() {
        if (expressionType == 'A')
            ans = x * x + y * y + z * z;
        else if (expressionType == 'B') {
            ans = x * y + y / z - x * z;
        }
        else if (expressionType == 'C') {
            ans = y * 3 * z - x * z / (y - 2) - x * y / (z + 1);
        }
    }
    friend ostream& operator<<(ostream& out, calculate t) {
        t.cal();
        out << t.ans;
        return out;
    }
};