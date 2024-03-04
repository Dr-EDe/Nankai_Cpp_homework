#include  <iostream>
using  namespace  std;

class  Fraction {
    int  numerator, denominator;

public:
    Fraction(int  a, int  b);

    bool  operator==(Fraction  const& f)  const;
    bool  operator!=(Fraction  const& f)  const;
    bool  operator>(Fraction  const& f)  const;
    bool  operator>=(Fraction  const& f)  const;
    bool  operator<(Fraction  const& f)  const;
    bool  operator<=(Fraction  const& f)  const;

    Fraction  operator+(Fraction  const& f)  const;
    Fraction  operator-(Fraction  const& f)  const;
    Fraction  operator*(Fraction  const& f)  const;
    Fraction  operator/(Fraction  const& f)  const;

    friend  std::istream& operator>>(std::istream&, Fraction& f);
    friend  std::ostream& operator<<(std::ostream&, Fraction  const& f);

private:
    void  simplify();
};
bool Fraction::operator==(Fraction const& f)const {
    if (numerator*f.denominator==denominator*f.numerator) {
        return true;
    }
    else return false;
}
bool Fraction::operator!=(Fraction const& f)const {
    if (numerator * f.denominator != denominator * f.numerator) {
        return true;
    }
    else return false;
}
bool Fraction::operator>(Fraction const& f)const {
    double num1, num2;
    num1 = (double)numerator / (double)denominator;
    num2 = (double)f.numerator / (double)f.denominator;
    if (num1 > num2)return true;
    else return false;
}
bool Fraction ::operator>=(Fraction const& f)const {
    double num1, num2;
    num1 = (double)numerator / (double)denominator;
    num2 = (double)f.numerator /(double) f.denominator;
    if (num1 >= num2)return true;
    else return false;
}
bool Fraction::operator<(Fraction const& f)const {
    double num1, num2;
    num1 = (double)numerator / (double)denominator;
    num2 = (double)f.numerator / (double)f.denominator;
    if (num1 < num2)return true;
    else return false;
}
bool Fraction::operator<=(Fraction const& f)const {
    double num1, num2;
    num1 = (double)numerator / (double)denominator;
    num2 = (double)f.numerator / (double)f.denominator;
    if (num1 <= num2)return true;
    else return false;
}
Fraction Fraction::operator+(Fraction const& f)const {
    int x = denominator * f.denominator;
    int y = numerator * f.denominator + f.numerator * denominator;
    Fraction temp(y,x);
    temp.denominator = x;
    temp.simplify();
    return temp;
}
Fraction Fraction::operator-(Fraction const& f)const{
    int x= numerator * f.denominator - f.numerator * denominator;
    int y= denominator * f.denominator;
    Fraction temp(x, y);
    temp.denominator = y;
    temp.simplify();
    return temp;
}
Fraction Fraction::operator*(Fraction  const& f)  const {
    int x = numerator * f.numerator;
    int y = denominator * f.denominator;
    Fraction temp(x, y);
    temp.denominator = y;
    temp.simplify();
    return temp;
}
Fraction Fraction::  operator/(Fraction  const& f)  const {
    int x = numerator * f.denominator;
    int y = denominator * f.numerator;
    Fraction temp(x, y);
    temp.denominator = y;
    temp.simplify();
    return temp;
}
std::istream& operator>>(std::istream&, Fraction& f) {
    cin >> f.numerator >> f.denominator;
    return cin;
}
std::ostream& operator<<(std::ostream&, Fraction  const& f) {
    cout << f.numerator << '/' << f.denominator;
    return cout;
}
void Fraction::simplify() {
    int a = numerator > 0 ? numerator : -numerator; int b = denominator > 0 ? denominator : -denominator;
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else b = b - a;
    }
    numerator /= b;
    denominator /= b;
}
Fraction::Fraction(int a,int b=1) {
    numerator = a; 
    denominator = 1;
}
int  main() {
    Fraction  a(1), b(1, 3);
    cin >> a >> b;

    cout << "a=  " << a << ",  b  =  " << b << endl;

    cout << a << "  +  " << b << "  =  " << a + b << endl;
    cout << a << "  -  " << b << "  =  " << a - b << endl;
    cout << a << "  *  " << b << "  =  " << a * b << endl;
    cout << a << "  /  " << b << "  =  " << a / b << endl;

    cout << "a  ==  b  is  " << (a == b) << endl;
    cout << "a  !=  b  is  " << (a != b) << endl;
    cout << "a  <=  b  is  " << (a <= b) << endl;
    cout << "a  >=  b  is  " << (a >= b) << endl;
    cout << "a  <  b  is  " << (a < b) << endl;
    cout << "a  >  b  is  " << (a > b) << endl;
    return  0;
}