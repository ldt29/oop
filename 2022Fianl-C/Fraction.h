#pragma once
#include<iostream>

using namespace std;

class Fraction {
public:
    int up;
    int down;
    Fraction();
    Fraction(int z);
    Fraction(int x, int y);
    Fraction operator+(Fraction x);
    Fraction operator-(Fraction x);
    Fraction operator*(Fraction x);
    Fraction operator/(Fraction x);

    friend ostream& operator<<(ostream& out, Fraction t) {
        if (t.down == 1){
            out << t.up;
        }
        else if (t.down < 0) {
            out << -t.up << "/" << -t.down;
        }
        else {
            out << t.up << "/" << t.down;
        }
        return out;
    }
    
};