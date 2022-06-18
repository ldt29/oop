#include<iostream>

#include"Fraction.h"
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int abs(int a){
    return a<0 ?-a:a;
}
Fraction::Fraction() {
    up=0;
    down=1;
};
Fraction::Fraction(int z) {
    up = z;
    down = 1;
}
Fraction::Fraction(int x, int y) {
    up = x;
    down = y;
}

Fraction Fraction::operator+(Fraction x) {
    Fraction ans = Fraction();
    ans.up = up * x.down + down * x.up;
    ans.down = x.down * down;
    if (ans.up == 0) return Fraction();
    if (ans.down < 0){
        ans.up=-ans.up;
        ans.down=-ans.down;
    }
    int temp = gcd(abs(ans.up), abs(ans.down));
    ans.up = ans.up / temp;
    ans.down = ans.down / temp;
    return ans;
}
Fraction Fraction::operator-(Fraction x) {
    Fraction ans = Fraction();
    ans.up = up * x.down - down * x.up;
    ans.down = x.down * down;
    if (ans.up == 0) return Fraction();
    if (ans.down < 0){
        ans.up=-ans.up;
        ans.down=-ans.down;
    }
    int temp = gcd(abs(ans.up), abs(ans.down));
    ans.up = ans.up / temp;
    ans.down = ans.down / temp;
    return ans;
}
Fraction Fraction::operator*(Fraction x) {
    Fraction ans = Fraction();
    ans.up = up * x.up;
    ans.down = x.down * down;
    if (ans.up == 0) return Fraction();
    if (ans.down < 0){
        ans.up=-ans.up;
        ans.down=-ans.down;
    }
    int temp = gcd(abs(ans.up), abs(ans.down));
    ans.up = ans.up / temp;
    ans.down = ans.down / temp;
    return ans;
}
Fraction Fraction::operator/(Fraction x) {
    Fraction ans = Fraction();
    ans.up = up * x.down;
    ans.down = x.up * down;
    if (ans.up == 0) return Fraction();
    if (ans.down < 0){
        ans.up=-ans.up;
        ans.down=-ans.down;
    }
    int temp = gcd(abs(ans.up), abs(ans.down));
    ans.up = ans.up / temp;
    ans.down = ans.down / temp;
    return ans;
}


    