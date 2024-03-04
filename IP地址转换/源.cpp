#include<iostream>
#include<math.h>
using namespace std;


int main() {
	char m[32];
	cin >> m;
	char n[32];
	cin >> n;
	int a=0, b=0, c=0, d=0, a1=0, b1=0, c1=0, d1=0;
	for (int i = 7; i >=0; i--) {
		if (m[i] == '0') { a += 0 * pow(2, 7-i); }
		else { a += 1 * pow(2, 7 - i); }
	}for (int i = 15; i >= 8; i--) {
		if (m[i] == '0') { b += 0 * pow(2, 15 - i); }
		else { b += 1 * pow(2, 15 - i); }
	}for (int i = 23; i >= 16; i--) {
		if (m[i] == '0') { c += 0 * pow(2, 23 - i); }
		else { c+= 1 * pow(2, 23 - i); }
	}for (int i = 31; i >= 24; i--) {
		if (m[i] == '0') {d += 0 * pow(2, 31 - i); }
		else { d += 1 * pow(2, 31 - i); }
	}
	cout << a << '.' << b << '.' << c << '.' << d<< endl;
	for (int i = 7; i >= 0; i--) {
		if (n[i] == '0') { a1 += 0 * pow(2, 7 - i); }
		else { a1 += 1 * pow(2, 7 - i); }
	}for (int i = 15; i >= 8; i--) {
		if (n[i] == '0') { b1 += 0 * pow(2, 15 - i); }
		else { b1 += 1 * pow(2, 15 - i); }
	}for (int i = 23; i >= 16; i--) {
		if (n[i] == '0') { c1 += 0 * pow(2, 23 - i); }
		else { c1 += 1 * pow(2, 23 - i); }
	}for (int i = 31; i >= 24; i--) {
		if (n[i] == '0') { d1+= 0 * pow(2, 31 - i); }
		else { d1 += 1 * pow(2, 31 - i); }
	}
	cout << a1 << '.' << b1 << '.' << c1 << '.' << d1 << endl;
	long long x;
	x = a * pow(256, 3) + b * pow(256, 2) + c * pow(256, 1) + d - a1 * pow(256, 3) - b1 * pow(256, 2) - c1 * pow(256, 1) - d1;
	if (x > 0) {  cout << x - 1; }
	else if (x == 0) { cout << 0; }
	else { cout << -x - 1; }
	system("pause");

	return 0;

}