#include  <iostream>
#include  <iomanip>
using  namespace  std;
class  ComplexNumber
{
private:
    double  a, b;
public:
    ComplexNumber(double c, double d) {
        a = c;
        b = d;
    }
    ComplexNumber() {
        a = 0; b = 0;
    }
    void Set(double c, double d) {
        a = c;
        b = d;
    }
    friend ComplexNumber operator+(ComplexNumber temp1, ComplexNumber temp2) {
        ComplexNumber temp;
        temp.a = temp1.a + temp2.a;
        temp.b = temp1.b + temp2.b;
        return temp;
    }
    friend ComplexNumber operator-(ComplexNumber temp1, ComplexNumber temp2) {
        ComplexNumber temp;
        temp.a = temp1.a - temp2.a;
        temp.b = temp1.b - temp2.b;
        return temp;
    }
    friend ComplexNumber operator/(ComplexNumber temp1, ComplexNumber temp2) {
        ComplexNumber temp;
        temp.a = (temp1.a * temp2.a + temp1.b * temp2.b) / (temp2.a * temp2.a + temp2.b * temp2.b);
        temp.b = (temp2.a * temp1.b - temp1.a * temp2.b) / (temp2.a * temp2.a + temp2.b * temp2.b);
        return temp;
    }
    friend ComplexNumber operator*(ComplexNumber temp1, ComplexNumber temp2) {
        ComplexNumber temp;
        temp.a = temp1.a * temp2.a - temp1.b * temp2.b;
        temp.b = temp1.a * temp2.b + temp1.b * temp2.a;
        return temp;
    }
    void  show() {
        cout << setprecision(2) << a << "  " << setprecision(2) << b << "i" << endl;
    }
};

int  main() {
    double  t_a, t_b;
    cin >> t_a >> t_b;
    ComplexNumber  cn1(t_a, t_b), cn2, cn3;
    cin >> t_a >> t_b;
    cn2.Set(t_a, t_b);

    cn3 = cn1 + cn2;
    cn3.show();
    cn3 = cn1 - cn2;
    cn3.show();
    cn3 = cn1 * cn2;
    cn3.show();
    cn3 = cn1 / cn2;
    cn3.show();

    return  0;
}