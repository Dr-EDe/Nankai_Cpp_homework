#include<iostream>
using namespace std;
#include<math.h>
#include<iomanip>
double s(double a, double b, double c) {
	double p = (a + b + c) / 2;
	double S = p * (p - a) * (p - b) * (p - c);
	return sqrt(S);
}

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(2) << s(a, b, c);

	system("pause");

	return 0;

}