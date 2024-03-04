#include<iostream>
using  namespace  std;
template<typename  T>
class  add
{
public:
    add(T  a, T  b)
    {
        x = a;
        y = b;
    }
    T  addl()
    {
        return  x + y;
    }
private:
    T  x, y;
};

int  main()
{
    int  a1, a2;
    double  b1, b2;

    cin >> a1 >> a2 >> b1 >> b2;
    add<int> s(a1, a2);
    cout << s.addl() <<endl;
    add<double> S(b1, b2);
    cout << S.addl();
}