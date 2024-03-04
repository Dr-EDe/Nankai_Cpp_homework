#include<iostream>
#include<cmath>  
#include<iomanip>

using  namespace  std;

class  Point {
private:
    double  x, y;
public:
    Point(double  xx, double  yy) { x = xx; y = yy; }
    void  Getxy();
    friend  double  Distance(Point& a, Point& b);
    ~Point() {
        cout << "The  destructor  is  called" << endl;
    }
};
void Point:: Getxy() {
    cout << '(' << x << ',' << y << ')' << endl;
}
double Distance(Point& a, Point& b){
    int r = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return sqrt(r);
}
int  main() {
    int  x, y;
    cin >> x >> y;
    Point  p1(x, y);
    cin >> x >> y;
    Point  p2(x, y);
    p1.Getxy();
    p2.Getxy();
    double  d = Distance(p1, p2);
    cout << "Distance  is  " << setprecision(2) << std::fixed << d << endl;
    return  0;
}