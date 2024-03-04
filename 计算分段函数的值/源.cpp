#include<iostream>
using namespace std;
#include<cmath>

int main() {
	double y = 0;
	double x = 0;
	cin >> x;
	if (x < 0) {
		y = x *x  + 2 / x + sin(x);
		cout << "" << y << endl;
	}
	else if (x >= 0 && x < 10) {
		y = 2 * pow(x, 5) - cos(x);
		cout << "" << y << endl;
	}
	else {
		y = 1 / sqrt(3 * x * x - 11);
		cout << "" << y << endl;
	}
	system("pause");

	return 0;

}