#include<iostream>
using namespace std;
#include<cmath>

int main() {
	double a, b, c,d,x1, x2,x;
	cout << "a*x*x+b*x+c=0" << endl;
	cout << "������a��b��c��ֵ" << endl;
	cin >> a >> b >> c;
	d = b * b - 4 * a * c;
	if (d > 0) {
		x1 = (-b + sqrt(d)) / 2 * a; x2 = (-b - sqrt(d)) / 2 * a;
		cout << "x1= " << x1 << " x2= " << x2 << endl;
	}
	else if (d == 0) {
		x = (-b) / 2 * a;
		cout << "x= " << x << endl;
	}
	else {
		cout << "x�޽�" << endl;
	}
	system("pause");

	return 0;

}