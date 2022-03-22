#include "Monomial.h"
#include <cmath>
#include <iostream>
using namespace std;

Monomial::Monomial():coe(0),deg(0){}

Monomial::Monomial(int _c,int _d){
    coe = _c;
    deg = _d;
}

Monomial Monomial::operator+(const Monomial &x) const{
    Monomial new_M(coe+x.coe,deg);
    if(new_M.coe==0)
        new_M.deg=0;
    return new_M;
}

Monomial Monomial::operator-(const Monomial &x) const{
    Monomial new_M(coe-x.coe,deg);
    if(new_M.coe==0)
        new_M.deg=0;
    return new_M;
}

Monomial Monomial::operator*(const Monomial &x) const{
    Monomial new_M(coe*x.coe,deg+x.deg);
    if(new_M.coe==0)
        new_M.deg=0;
    //cout << deg << x.deg << new_M.deg<<"---------"<<endl;
    return new_M;
}

Monomial Monomial::operator/(const Monomial &x) const{
    Monomial new_M(coe/x.coe,deg-x.deg);
    if(new_M.coe==0)
        new_M.deg=0;
    return new_M;
}

int Monomial::definite_integral(const int a, const int b) const{
    return int((pow(b,deg+1)-pow(a,deg+1))*coe)/(deg+1);
}

Monomial Monomial::derive() const{
    Monomial new_M(coe*deg,deg-1);
    if(deg==0){
        new_M.coe=0;
        new_M.deg=0;
    }
    return new_M;
}

int Monomial::get_val(int x) const{
    return int(coe*pow(x,deg));
}

istream& operator>> (istream& in,Monomial& dst){
   char s[10]={'\0'};
    in >> s;
    dst.coe=0;
    dst.deg=0;
    int i=0;
    int flag=1;
    if(s[0]=='-'){
        flag=-1;
        i++;
    }
    while(s[i]!='x'){
        dst.coe=dst.coe*10+s[i]-'0';
        i++;
    }
    dst.coe*=flag;
    while(s[i]!='-'&&(s[i]>'9'||s[i]<'0')){
        i++;
    }
    flag=1;
    if(s[i]=='-'){
        flag=-1;
        i++;
    }
    while(s[i]!='\0'){
        dst.deg=dst.deg*10+s[i]-'0';
        i++;
    }
    dst.deg*=flag;
    return in;
}

ostream& operator<< (ostream& out,const Monomial& src){
    out << src.coe<<"x^"<<src.deg<<endl;
}