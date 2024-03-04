#include<iostream>
#include<iomanip>
#include<cmath>
using  namespace  std;
class  Point
{
private:
	double x;
	double y;
	double l;

public:
	Point(double x0, double y0) {
		x = x0;
		y = y0;
		l = sqrt(x * x + y * y);
	}
	double getl() {
		return l;
	}

};
int  main()
{
	int n;
	cin >> n;
	double p, q;
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> p >> q;
		Point point = Point(p, q);
		x[i] = point.getl();
	}
	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(3) << x[i]<< endl;
	}
}