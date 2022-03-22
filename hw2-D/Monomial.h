#include <iostream>
#include <string>
using namespace std;
class Monomial
{
private:
    int coe;
    int deg;
public:
    Monomial();
    Monomial(int _c, int _d);
    Monomial operator+(const Monomial &x) const;
    Monomial operator-(const Monomial &x) const;
    Monomial operator*(const Monomial &x) const;
    Monomial operator/(const Monomial &x) const;
    int definite_integral(const int a, const int b) const;
    Monomial derive() const;
    int get_val(int x) const;
    //TODO
    friend istream& operator>> (istream& in,Monomial& dst);
    friend ostream& operator<< (ostream& out,const Monomial& src);
};  